#include <FireStone/DataTraffic>

/**
* @brief This will check to make sure that transmissions work on the bus.
 * @return Whether an error exists.
 */
int main() {
    using namespace FireStone::DataTraffic;

    Bus<8> bus;
    BusNode<8ULL> nodeA {};
    BusNode<8ULL> nodeB {};

    size_t handleA = bus.Attach(&nodeA);
    size_t handleB = bus.Attach(&nodeB);

    bool* packet = bus.Read();
    {
        bool expected[8] = { false, false, false, false, false, false, false, false };
        for (size_t i = 0; i < 8; i++)
            if (packet[i] != expected[i])
                return 1;
    }

    nodeA.SetOutputBit(0, true);
    nodeA.SetOutputBit(1, true);
    nodeA.SetOutputBit(2, true);
    nodeA.SetOutputBit(3, true);
    nodeA.SetOutputBit(4, true);
    nodeA.SetOutputBit(5, false);
    nodeA.SetOutputBit(6, false);
    nodeA.SetOutputBit(7, false);

    nodeB.SetOutputBit(0, false);
    nodeB.SetOutputBit(1, false);
    nodeB.SetOutputBit(2, false);
    nodeB.SetOutputBit(3, false);
    nodeB.SetOutputBit(4, false);
    nodeB.SetOutputBit(5, true);
    nodeB.SetOutputBit(6, true);
    nodeB.SetOutputBit(7, true);

    packet = bus.Read();
    {
        bool expected[8] = { true, true, true, true, true, true, true, true };
        for (size_t i = 0; i < 8; i++)
            if (packet[i] != expected[i])
                return 1;
    }

    nodeA.SetOutputBit(0, false);
    nodeB.SetOutputBit(0, false);

    packet = bus.Read();
    {
        bool expected[8] = { false, true, true, true, true, true, true, true };
        for (size_t i = 0; i < 8; i++)
            if (packet[i] != expected[i])
                return 1;
    }

    return 0;
}