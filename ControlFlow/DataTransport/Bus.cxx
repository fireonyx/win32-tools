#include "Bus.hxx"

namespace Rayonix::Win32Tools::ControlFlow::DataTransport {
    Bus::Bus(size_t bitCount) : bitCount(bitCount) {
        if (bitCount < 1)
            throw std::invalid_argument("The bit count must be greater than 0.");
        if (bitCount % 8 != 0)
            throw std::invalid_argument("The bit count must be a multiple of 8.");
    }
}