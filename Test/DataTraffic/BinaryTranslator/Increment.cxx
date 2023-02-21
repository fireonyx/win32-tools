#include <FireStone/DataTraffic>
#include <iostream>

/**
 * @brief This will check to make sure that the packet translator can increment numbers.
 * @return Whether an error exists.
 */
int main() {
    using namespace FireStone::DataTraffic;

    PacketTranslator<4> translator;
    uint16_t realNumber = 0;
    bool packets[16][4] = {};
    bool *lastPacket;

    const bool truePacket[4] = { true, true, true, true };

    for (size_t i = 0; i < 16; i++) {
        if (i == 0) lastPacket = translator.Increment(const_cast<bool *>(truePacket));
        else lastPacket = translator.Increment(lastPacket);
        for (size_t j = 0; j < 4; j++)
            packets[i][j] = lastPacket[j];
    }

    // print out all values
    for (size_t i = 0; i < 16; i++) {
        for (size_t j = 0; j < 4; j++)
            std::cout << packets[i][j];
        std::cout << std::endl;
    }
}