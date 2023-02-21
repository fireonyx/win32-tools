#pragma once

#include <iostream>

namespace FireStone::DataTraffic {
    /**
     * @brief Output flags.
    */
    enum class OutputFlags {
        /**
         * @brief Negative number.
         */
        Negative = 1 << 0,

        /**
         * @brief Zero.
         */
        Zero = 1 << 1,

        /**
         * Overflow.
         */
        Overflow = 1 << 2,

        /**
         * @brief Carry.
         */
        Carry = 1 << 3
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
         * @brief The output flags.
         */
        uint8_t m_outputFlags = 0;
        
    public:
        /**
         * @brief The width of the packet.
         */
        static constexpr size_t Width = PacketWidth;

        /**
         * @brief Add 2 binary packets together.
         * @param packet1 The first packet.
         * @param packet2 The second packet.
         * @return The sum of the 2 packets.
         */
        bool *Add(bool packet1[PacketWidth], bool packet2[PacketWidth]) {
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

            m_outputFlags = 0;

            if (cary == 1)
                m_outputFlags |= (uint8_t) OutputFlags::Carry;
            if (cary == 2)
                m_outputFlags |= (uint8_t) OutputFlags::Overflow;

            bool zero = true;
            for (int i = 0; i < PacketWidth; i++) {
                if (packet1[i] == true) {
                    zero = false;
                    break;
                }
            }

            if (zero)
                m_outputFlags |= (uint8_t) OutputFlags::Zero;

            return packet1;
        }

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

        /**
         * @brief Subtract 2 binary packets together.
         * @param packet1 The first packet.
         * @param packet2 The second packet, which will be subtracted from the first packet.
         * @return The difference of the 2 packets.
         */
        bool *Subtract(bool packet1[PacketWidth], bool packet2[PacketWidth]) {
            for (int i = PacketWidth - 1; i >= 0; i--) {
                if (packet1[i] == true && packet2[i] == false) {
                    packet1[i] = true;
                } else if (packet1[i] == false && packet2[i] == true) {
                    packet1[i] = true;
                    for (int j = i - 1; j >= 0; j--) {
                        if (packet1[j] == true) {
                            packet1[j] = false;
                            break;
                        } else {
                            packet1[j] = true;
                        }
                    }
                } else {
                    packet1[i] = false;
                }
            }

            m_outputFlags = 0;

            bool isZero = true;
            for (int i = 0; i < PacketWidth; i++) {
                if (packet1[i] == true) {
                    isZero = false;
                    break;
                }
            }

            if (isZero)
                m_outputFlags |= (uint8_t) OutputFlags::Zero;

            // TODO: Negative checker via comparator

            return packet1;
        }

        /**
         * @brief Decrement the value of the packet by 1.
         * @param packet The packet to decrement.
         * @return The decremented packet.
         */
        bool *Decrement(bool packet[PacketWidth]) {
            bool one[PacketWidth];
            for (int i = 0; i < PacketWidth - 1; i++)
                one[i] = false;
            one[PacketWidth - 1] = true;

            return Subtract(packet, one);
        }

        /**
         * @brief Get the output flags.
         * @return The output flags.
         */
        uint8_t GetOutputFlags() const {
            return m_outputFlags;
        }
    };
}