#include <FireStone/DataTraffic>

/**
 * @brief This will check to see if the error handling of the bus works.
 * @return Whether an error exists.
 */
int main() {
    using namespace FireStone::DataTraffic;
    Bus<8> bus;
    BusNode<8ULL> nodeA {};

    try {
        bus.Detach(0); // An error should be thrown.
    } catch (std::out_of_range& e) {
        size_t handle = bus.Attach(&nodeA);
        if (handle != 0)
            return 1;
        try {
            bus.Detach(handle); // An error should NOT be thrown.
        } catch (std::out_of_range& e) {
            return 1;
        }

        return 0;
    }

    return 1;
}