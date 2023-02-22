#pragma once

#include <iostream>
#include <functional>

namespace FireStone::DataTraffic {
    /**
     * @brief The result of a binary comparison.
     */
    enum class ComparisonResult {
        /**
         * @brief The first packet is less than the second packet.
         */
        LessThan,

        /**
         * @brief The first packet is greater than the second packet.
         */
        GreaterThan,

        /**
         * @brief The first packet is equal to the second packet.
         */
        EqualTo
    };

    /**
     * @brief Class used for manipulating binary packets without converting them to the host integer. This
     * packet translator will accept and manipulate little endian packets.
     * @tparam PacketWidth The width of the packet output.
     */
    template <size_t PacketWidth>
    class PacketTranslator {
    private:
        /**
         * @brief Whether the zero flag is set.
         */
        bool m_zeroFlag = false;

        /**
         * @brief Whether the carry flag is set.
         */
        bool m_carryFlag = false;

        /**
         * @brief Whether the overflow flag is set.
         */
        bool m_overflowFlag = false;

        /**
         * @brief Whether the negative flag is set.
         */
        bool m_negativeFlag = false;
        
    public:
        /**
         * @brief The width of the packet.
         */
        static constexpr size_t Width = PacketWidth;

        /**
         * @brief Compare 2 binary packets.
         * @param packet1 The first packet.
         * @param packet2 The second packet.
         * @return The result of the comparison.
         */
        ComparisonResult Compare(const bool packet1[PacketWidth], const bool packet2[PacketWidth]) {
            for (int i = 0; i < PacketWidth; i++) {
                if (packet1[i] == true && packet2[i] == false)
                    return ComparisonResult::GreaterThan;
                if (packet1[i] == false && packet2[i] == true)
                    return ComparisonResult::LessThan;
            }

            return ComparisonResult::EqualTo;
        }

        /**
         * @brief Add 2 binary packets together.
         * @param packet1 The first packet.
         * @param packet2 The second packet.
         * @return The sum of the 2 packets.
         */
        bool *Add(bool packet1[PacketWidth], const bool packet2[PacketWidth]) {
            ResetFlags();
            uint8_t cary = 0; // 0 (00) 1 (01) 2 (11)

            for (int i = PacketWidth - 1; i >= 0; i--) {
                uint8_t sum = packet1[i] + packet2[i] + cary;
                if (sum == 0) {
                    packet1[i] = false;
                    cary = 0;
                } else if (sum == 1) {
                    packet1[i] = true;
                    cary = 0;
                } else if (sum == 2) {
                    packet1[i] = false;
                    cary = 1;
                } else if (sum == 3) {
                    packet1[i] = true;
                    cary = 1;
                }
            }

            if (cary == 1)
                m_carryFlag = true;
            if (cary == 2)
                m_overflowFlag = true;

            bool zero = true;
            for (int i = 0; i < PacketWidth; i++) {
                if (packet1[i] == true) {
                    zero = false;
                    break;
                }
            }

            if (zero)
                m_zeroFlag = true;

            return packet1;
        }

#pragma clang diagnostic push
#pragma ide diagnostic ignored "ArgumentSelectionDefects"
        /**
         * @brief Increment the value of the packet by 1.
         * @param packet The packet to increment.
         * @return The incremented packet.
         */
        bool *Increment(bool packet[PacketWidth]) {
            bool one[PacketWidth];
            for (int i = 0; i < PacketWidth - 1; i++)
                one[i] = false;
            one[PacketWidth - 1] = true;

            return Add(packet, one);
        }
#pragma clang diagnostic pop

        /**
         * @brief Subtract 2 binary packets together.
         * @param packet1 The first packet.
         * @param packet2 The second packet, which will be subtracted from the first packet.
         * @param seamless Whether the subtraction should look seamless when approaching negative numbers. If this
         * is disabled, the subtraction will loop around to the highest binary number after subtraction from 0.
         * @return The difference of the 2 packets.
         */
        bool *Subtract(bool packet1[PacketWidth], bool packet2[PacketWidth], bool seamless = true) { // NOLINT(readability-non-const-parameter)
            ResetFlags();

            auto packet1Copy = packet1;
            auto packet2Copy = packet2;

            auto compResult = Compare(packet1Copy, packet2Copy);

            if (compResult == ComparisonResult::LessThan && seamless) {
                auto temp = packet1Copy;
                packet1Copy = packet2Copy;
                packet2Copy = temp;

                m_negativeFlag = true;
            } else if (compResult == ComparisonResult::EqualTo) {
                for (int i = 0; i < PacketWidth; i++)
                    packet1[i] = false;

                m_zeroFlag = true;
                return packet1;
            }

            for (int i = PacketWidth - 1; i >= 0; i--) {
                if (packet1Copy[i] == true && packet2Copy[i] == false) {
                    packet1Copy[i] = true;
                } else if (packet1Copy[i] == false && packet2Copy[i] == true) {
                    packet1Copy[i] = true;
                    for (int j = i - 1; j >= 0; j--) {
                        if (packet1Copy[j] == true) {
                            packet1Copy[j] = false;
                            break;
                        } else {
                            packet1Copy[j] = true;
                        }
                    }
                } else {
                    packet1Copy[i] = false;
                }
            }

            return packet1Copy;
        }

#pragma clang diagnostic push
#pragma ide diagnostic ignored "ArgumentSelectionDefects"
        /**
         * @brief Decrement the value of the packet by 1.
         * @param packet The packet to decrement.
         * @param seamless Whether the subtraction should look seamless when approaching negative numbers. If this
         * @return The decremented packet.
         */
        bool *Decrement(bool packet[PacketWidth], bool seamless = true) {
            bool one[PacketWidth];
            for (int i = 0; i < PacketWidth - 1; i++)
                one[i] = false;
            one[PacketWidth - 1] = true;

            return Subtract(packet, one, seamless);
        }
#pragma clang diagnostic pop

        /**
         * @brief Multiply 2 binary packets together.
         * @param packet1 The first packet.
         * @param packet2 The second packet.
         * @return The product of the 2 packets.
         */
        bool *Multiply(bool packet1[PacketWidth], const bool packet2[PacketWidth]) {
            ResetFlags();

            bool *result = GetZeroPacket();
            bool *timesMultiplied = GetZeroPacket();

            // Load result with packet1
            for (int i = 0; i < PacketWidth; i++)
                result[i] = packet1[i];

            auto CheckIfMultipliedFully = [&] () {
                for (int i = 0; i < PacketWidth; i++) {
                    if (packet2[i] != timesMultiplied[i])
                        return true;
                }
                return false;
            };

            while (!CheckIfMultipliedFully()) {
                for (int i = 0; i < PacketWidth; i++)
                    std::cout << timesMultiplied[i];
                std::cout << " vs ";
                for (int i = 0; i < PacketWidth; i++)
                    std::cout << packet2[i];
                std::cout << std::endl;
                result = Add(result, packet1);
                timesMultiplied = Increment(timesMultiplied);
            }

            return result;
        }

        /**
         * @brief Get whether the zero flag is set.
         * @return Whether the zero flag is set.
         */
        bool GetZeroFlag() const {
            return m_zeroFlag;
        }

        /**
         * @brief Get a newly generated packet with a zero value.
         * @return A newly generated packet with a zero value.
         */
        bool *GetZeroPacket() const {
            bool packet[PacketWidth];
            for (int i = 0; i < PacketWidth; i++)
                packet[i] = false;
            return packet;
        }

        /**
         * @brief Get whether the carry flag is set.
         * @return Whether the carry flag is set.
         */
        bool GetCarryFlag() const {
            return m_carryFlag;
        }

        /**
         * @brief Get whether the overflow flag is set.
         * @return Whether the overflow flag is set.
         */
        bool GetOverflowFlag() const {
            return m_overflowFlag;
        }

        /**
         * @brief Get whether the negative flag is set.
         * @return Whether the negative flag is set.
         */
        bool GetNegativeFlag() const {
            return m_negativeFlag;
        }

        /**
         * @brief Reset the flags.
         */
        void ResetFlags() {
            m_zeroFlag = false;
            m_carryFlag = false;
            m_overflowFlag = false;
            m_negativeFlag = false;
        }
    };
}