#include "Main.hxx"
#include <Rayonix/Win32Tools/ControlFlow>

using namespace Rayonix::Win32Tools::ControlFlow::DataTransport;

namespace Rayonix::Win32Tools::Entry {
    void Main::Execute() {

        m_returnCode = 0;
    }

    int Main::GetReturnCode() const {
        return m_returnCode;
    }
}

int main() {
    Rayonix::Win32Tools::Entry::Main main;
    main.Execute();

    return main.GetReturnCode();
}