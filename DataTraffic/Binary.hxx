#pragma once

namespace FireStone::DataTraffic {
    /**
     * @brief Class used for manipulating binary packets without converting them to the host integer. This
     * packet translator will accept and manipulate little endian packets.
     * @tparam PacketWidth The width of the packet output.
     */
    template <size_t PacketWidth>
    class PacketTranslator {
    public:
        /**
         * @brief The width of the packet.
         */
        static constexpr size_t Width = PacketWidth;

        /**
         * @brief Increment the value of the packet by 1.
         * @param packet The packet to increment.
         * @return The incremented packet.
         */
        bool *Increment(bool packet[PacketWidth]) {
            for (size_t i = 0; i < PacketWidth; i++)
                if (packet[i] == false) {
                    packet[i] = true;
                    break;
                } else
                    packet[i] = false;
            return packet;
        }
    };
}