#include <FireStone/DataTraffic>
#include <iostream>
#include <cstring>

/**
 * @brief This will check to make sure that the packet translator can decrement numbers.
 * @return Whether an error exists.
 */
int main() {
    using namespace FireStone::DataTraffic;

    PacketTranslator<4> translator;
    bool packets[16][4] = {};
    bool *lastPacket;

    const bool falsePacket[4] = { false, false, false, false };

    for (size_t i = 16; i == 0; i--) {
        std::cout << i << std::endl;
        if (i == 15) {
            bool *packet = translator.Decrement(const_cast<bool *>(falsePacket));
            for (size_t j = 0; j < 4; j++)
                lastPacket[j] = packet[j];
        }
        else lastPacket = translator.Decrement(lastPacket);
        for (size_t j = 0; j < 4; j++)
            packets[i][j] = lastPacket[j];
    }

    // // Print all packets
    // for (size_t i = 0; i < 16; i++) {
    //     for (size_t j = 0; j < 4; j++)
    //         std::cout << packets[i][j];
    //     std::cout << std::endl;
    // }

    return 0;
}