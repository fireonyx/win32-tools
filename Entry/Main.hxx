#pragma once
#include <Rayonix/Win32Tools/ControlFlow>
#include "config.h"

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
         * The size of the address bus.
         */
        const size_t m_addressWidth;

        /**
         * The size of the data bus.
         */
        const size_t m_dataWidth;

    public:
        /**
         * The address data bus. This bus is used to send request addresses to memory.
         */
        const Rayonix::Win32Tools::ControlFlow::DataTransport::Bus m_addressBus;

        /**
         * The data bus. This bus is used to send and receive data between nodes
         * connected to the bus.
         */
        const Rayonix::Win32Tools::ControlFlow::DataTransport::Bus m_dataBus;

        /**
         * The commanding bus, this tells components on the bus what to do.
         */
        const Rayonix::Win32Tools::ControlFlow::DataTransport::Bus m_commandBus;

        /**
         * @param addressWidth The size of the address bus.
         * @param dataWidth The size of the data bus.
         * @throws std::invalid_argument If the address width is less than 1, or not a multiple of 8.
         */
        Main(size_t addressWidth = DEFAULT_ADDRESS_WIDTH, size_t dataWidth = DEFAULT_DATA_WIDTH);

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