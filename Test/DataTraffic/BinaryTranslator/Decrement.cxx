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
    bool *lastPacket = nullptr;

    const bool falsePacket[4] = { false, false, false, false };

    for (size_t i = 0; i < 15; i++) {
        if (i == 0)
            lastPacket = translator.Decrement(const_cast<bool *>(falsePacket));
        else lastPacket = translator.Decrement(lastPacket);
        for (size_t j = 0; j < 4; j++)
            packets[i][j] = lastPacket[j];
    }

    const bool packetZero[4] = { true, true, true, true };
    const bool packetOne[4] = { true, true, true, false };
    const bool packetTwo[4] = { true, true, false, true };
    const bool packetThree[4] = { true, true, false, false };
    const bool packetFour[4] = { true, false, true, true };
    const bool packetFive[4] = { true, false, true, false };
    const bool packetSix[4] = { true, false, false, true };
    const bool packetSeven[4] = { true, false, false, false };
    const bool packetEight[4] = { false, true, true, true };
    const bool packetNine[4] = { false, true, true, false };
    const bool packetTen[4] = { false, true, false, true };
    const bool packetEleven[4] = { false, true, false, false };
    const bool packetTwelve[4] = { false, false, true, true };
    const bool packetThirteen[4] = { false, false, true, false };
    const bool packetFourteen[4] = { false, false, false, true };
    const bool packetFifteen[4] = { false, false, false, false };

    if (std::memcmp(packets[0], packetZero, 4) != 0)
        return 1;
    if (std::memcmp(packets[1], packetOne, 4) != 0)
        return 1;
    if (std::memcmp(packets[2], packetTwo, 4) != 0)
        return 1;
    if (std::memcmp(packets[3], packetThree, 4) != 0)
        return 1;
    if (std::memcmp(packets[4], packetFour, 4) != 0)
        return 1;
    if (std::memcmp(packets[5], packetFive, 4) != 0)
        return 1;
    if (std::memcmp(packets[6], packetSix, 4) != 0)
        return 1;
    if (std::memcmp(packets[7], packetSeven, 4) != 0)
        return 1;
    if (std::memcmp(packets[8], packetEight, 4) != 0)
        return 1;
    if (std::memcmp(packets[9], packetNine, 4) != 0)
        return 1;
    if (std::memcmp(packets[10], packetTen, 4) != 0)
        return 1;
    if (std::memcmp(packets[11], packetEleven, 4) != 0)
        return 1;
    if (std::memcmp(packets[12], packetTwelve, 4) != 0)
        return 1;
    if (std::memcmp(packets[13], packetThirteen, 4) != 0)
        return 1;
    if (std::memcmp(packets[14], packetFourteen, 4) != 0)
        return 1;
    if (std::memcmp(packets[15], packetFifteen, 4) != 0)
        return 1;

    return 0;
}