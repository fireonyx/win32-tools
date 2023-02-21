#pragma once
#include <utility>
#include <vector>
#include <stdexcept>
#include <functional>

namespace FireStone::DataTraffic {
    /**
     * @brief The node that is used to connect to the bus for sending IO data.
     * @tparam BusWidth
     */
    template <size_t BusWidth>
    class BusNode {
    private:
        /**
         * @brief The current output value of the node.
         */
        bool m_output[BusWidth];

    public:
        /**
         * @brief The bus width.
         */
        static constexpr size_t Width = BusWidth;

        /**
         * @brief Set the value of an output bit.
         * @param index The index of the output bit.
         * @param value The value of the output bit.
         * @throws std::out_of_range If the index is out of range.
         */
        void SetOutputBit(size_t index, bool value) {
            if (index >= BusWidth)
                throw std::out_of_range("Index out of range.");
            m_output[index] = value;
        }

        /**
         * @brief Set the value of the output packet.
         * @param packet The packet to set the output to.
         */
        void SetOutputPacket(bool packet[BusWidth]) {
            m_output = packet;
        }

        /**
         * @brief Get the value of an output bit.
         * @param index The index of the output bit.
         * @return The value of the output bit.
         * @throws std::out_of_range If the index is out of range.
         */
        bool GetOutputBit(size_t index) {
            if (index >= BusWidth)
                throw std::out_of_range("Index out of range.");
            return m_output[index];
        }
    };

    /**
     * @brief Class used for sending and receiving data asynchronously across a set of nodes.
     * @tparam BusWidth The number of bits in the data bus.
     */
    template <size_t BusWidth>
    class Bus {
    private:
        /**
         * @brief The nodes that are actively connected to the bus.
         */
        std::vector<BusNode<BusWidth> *> m_nodes;

        /**
         * @brief The receive handler for the bus.
         */
        bool m_currentPacket[BusWidth];

    public:
        /**
         * @brief Connects a node to the bus.
         * @param node The node to connect to the bus.
         * @return The handle of the node.
         * @throws std::invalid_argument If the node width does not match the bus width.
         */
        size_t Attach(BusNode<BusWidth> *node) {
            m_nodes.push_back(node);
            return m_nodes.size() - 1;
        }

        /**
         * @brief Disconnects a node from the bus.
         * @param handle The handle of the node to disconnect.
         * @throws std::out_of_range If the handle is invalid.
         */
        void Detach(size_t handle) {
            if (handle >= m_nodes.size())
                throw std::out_of_range("Invalid handle.");
            m_nodes.erase(m_nodes.begin() + handle);
        }

        /**
         * @brief Read the current bus value.
         * @return The current bus value.
         */
        bool *Read() {
            for (size_t i = 0; i < BusWidth; i++) {
                bool bitSet = false;
                for (BusNode<BusWidth> *node : m_nodes)
                    if (node->GetOutputBit(i)) {
                        bitSet = true;
                        break;
                    }
                m_currentPacket[i] = bitSet;
            }

            return m_currentPacket;
        }
    };
}