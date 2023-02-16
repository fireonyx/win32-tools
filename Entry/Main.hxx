#pragma once
#include <Rayonix/Win32Tools/ControlFlow>

using namespace Rayonix::Win32Tools::ControlFlow::DataTransport;

namespace Rayonix::Win32Tools::Entry {
    /**
     * Win32Tools main class, entry program will begin here.
     */
    class Main {
    private:
        /**
         * Return code of the program. This can be set by this class, and when the program main function
         * finished.
         */
        int m_returnCode;

        /**
         * The control bus. This bus is used to send and receive control signals to nodes and other units.
         */

    public:
        /**
         * The address data bus. This bus is used to send request addresses to memory.
         */
        const Bus m_addressBus;

        /**
         * The data bus. This bus is used to send and receive data between nodes
         * connected to the bus.
         */
        const Bus m_dataBus;

        /**
         * Execute the program main function and duty.
         */
        void Execute();

        /**
         * Get the return code of the program.
         * @return Return code of the program.
         */
        [[nodiscard]] int GetReturnCode() const;
    };
}