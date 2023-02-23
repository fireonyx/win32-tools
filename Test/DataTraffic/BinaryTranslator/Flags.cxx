#include <FireStone/DataTraffic>

/**
 * @brief This will ensure that flags are working properly.
 * @return Whether an error exists.
 */
int main() {
    using namespace FireStone::DataTraffic;

    PacketTranslator<4> translator;
    bool *out;

    {
        bool packetA[4] = {true, true, true, true};
        bool packetB[4] = {true, true, true, true};

        // Testing zero
        out = translator.Subtract(packetA, packetB);
        for (size_t i = 0; i < 4; i++)
            if (out[i]) return 1;

        // Flags: (Zero)
        if (!translator.GetZeroFlag()) return 1;
        if (translator.GetCarryFlag()) return 1;
        if (translator.GetNegativeFlag()) return 1;
        if (translator.GetOverflowFlag()) return 1;

        printf("Testing for zero with subtract passed.\n");
    }

    {
        bool packetA[4] = {false, false, false, false};
        bool packetB[4] = {false, false, false, false};

        // Testing zero
        out = translator.Add(packetA, packetB);
        for (size_t i = 0; i < 4; i++)
            if (out[i]) return 1;

        // Flags: (Zero)
        if (!translator.GetZeroFlag()) return 1;
        if (translator.GetCarryFlag()) return 1;
        if (translator.GetNegativeFlag()) return 1;
        if (translator.GetOverflowFlag()) return 1;

        printf("Testing for zero with add passed.\n");
    }

    {
        bool packetA[4] = {false, false, false, true};
        bool packetB[4] = {false, false, true, false};

        // Testing negative
        out = translator.Subtract(packetA, packetB);
        bool expected[4] = {false, false, false, true};

        for (size_t i = 0; i < 4; i++)
            if (out[i] != expected[i]) return 1;

        // Flags: (Negative)
        if (translator.GetZeroFlag()) return 1;
        if (translator.GetCarryFlag()) return 1;
        if (!translator.GetNegativeFlag()) return 1;
        if (translator.GetOverflowFlag()) return 1;

        printf("Testing for negative with subtract passed.\n");
    }

    return 0;
}