#include <FireStone/DataTraffic>
#include <iostream>

/**
 * @brief This will check to make sure that the packet translator can increment numbers.
 * @return Whether an error exists.
 */
int main() {
    using namespace FireStone::DataTraffic;

    PacketTranslator<4> translator;
    
    bool packet1[4] = { 0, 0, 0, 0 };
    bool packet2[4] = { 0, 0, 0, 1 };

    bool *sum = translator.Subtract(packet1, packet2);
    for (int i = 0; i < 4; i++)
        std::cout << sum[i];
    std::cout << std::endl;

    // If zero
    if (translator.GetOutputFlags() & static_cast<uint8_t>(OutputFlags::Zero))
        std::cout << "Zero" << std::endl;
    // If negative
    if (translator.GetOutputFlags() & static_cast<uint8_t>(OutputFlags::Negative))
        std::cout << "Negative" << std::endl;
    // If overflow
    if (translator.GetOutputFlags() & static_cast<uint8_t>(OutputFlags::Overflow))
        std::cout << "Overflow" << std::endl;
    // If carry
    if (translator.GetOutputFlags() & static_cast<uint8_t>(OutputFlags::Carry))
        std::cout << "Carry" << std::endl;

    return 0;
}