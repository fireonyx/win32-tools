#include "Main.hxx"
#include <Rayonix/Win32Tools/ControlFlow>

using namespace Rayonix::Win32Tools::ControlFlow::DataTransport;

namespace Rayonix::Win32Tools::Entry {
    Main::Main(size_t addressWidth, size_t dataWidth) :
        m_addressWidth(addressWidth),
        m_dataWidth(dataWidth),
        m_addressBus(addressWidth),
        m_dataBus(dataWidth),
        m_commandBus(COMMAND_BUS_WIDTH) {
    }

    void Main::Execute() {
        m_returnCode = 0;
    }

    int Main::GetReturnCode() const {
        return m_returnCode;
    }
}

int main() {
    Rayonix::Win32Tools::Entry::Main main(8, 8);
    main.Execute();

    return main.GetReturnCode();
}