#pragma once
#include <iostream>

namespace Rayonix::Win32Tools::ControlFlow::DataTransport {
    /**
     * Data transport bus can be used to allow multiple units to send and receive data without
     * having to be directly compatible with each other, the bus protocol will transmit data across
     * to all contested nodes.
     */
    class Bus {
    private:
        /**
         * The number of bits that the bus can transmit at once.
         */
        const size_t bitCount;

    public:
        /**
         * @param bitCount The number of bits that the bus can transmit at once.
         * @throws std::invalid_argument If the bit count is less than 1, or not a multiple of 8.
         */
        Bus(size_t bitCount);
    };
}