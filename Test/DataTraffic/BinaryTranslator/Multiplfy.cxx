#include <FireStone/DataTraffic>

/**
* @brief This will check to make sure that the packet translator can multiply numbers.
 * @return Whether an error exists.
 */
int main() {
    using namespace FireStone::DataTraffic;

    PacketTranslator<4> translator;

    bool packets[4][4] = {};
    bool *lastPacket;

    const bool onePacket[4] = { false, false, false, true };
    const bool multiplier[4] = { false, false, true, false };

    for (size_t i = 0; i < 4; i++) {
        if (i == 0) lastPacket = translator.Multiply(const_cast<bool *>(onePacket), multiplier);
        else lastPacket = translator.Multiply(lastPacket, multiplier);
        for (size_t j = 0; j < 4; j++)
            packets[i][j] = lastPacket[j];
    }

    // print out the packets
//    for (size_t i = 0; i < 4; i++) {
//        for (size_t j = 0; j < 4; j++)
//            std::cout << packets[i][j];
//        std::cout << std::endl;
//    }

    return 0;
}