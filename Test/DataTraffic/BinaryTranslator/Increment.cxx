#include <FireStone/DataTraffic>
#include <iostream>
#include <cstring>

/**
 * @brief This will check to make sure that the packet translator can increment numbers.
 * @return Whether an error exists.
 */
int main() {
    using namespace FireStone::DataTraffic;

    PacketTranslator<4> translator;
    bool packets[16][4] = {};
    bool *lastPacket;

    const bool truePacket[4] = { true, true, true, true };

    for (size_t i = 0; i < 16; i++) {
        if (i == 0) lastPacket = translator.Increment(const_cast<bool *>(truePacket));
        else lastPacket = translator.Increment(lastPacket);
        for (size_t j = 0; j < 4; j++)
            packets[i][j] = lastPacket[j];
    }

    const bool expected[16][4] = {
        { false, false, false, false },
        { false, false, false, true },
        { false, false, true, false },
        { false, false, true, true },
        { false, true, false, false },
        { false, true, false, true },
        { false, true, true, false },
        { false, true, true, true },
        { true, false, false, false },
        { true, false, false, true },
        { true, false, true, false },
        { true, false, true, true },
        { true, true, false, false },
        { true, true, false, true },
        { true, true, true, false },
        { true, true, true, true }
    };

    for (size_t i = 0; i < 16; i++) {
        if (std::memcmp(packets[i], expected[i], 4) != 0)
            return 1;
    }

    return 0;
}