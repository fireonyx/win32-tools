#pragma once

namespace Rayonix::Win32Tools::ControlFlow::DataTransport {
    /**
     * Data transport bus can be used to allow multiple units to send and receive data without
     * having to be directly compatible with each other, the bus protocol will transmit data across
     * to all contested nodes.
     */
    class Bus {
    public:
        Bus();
    };
}