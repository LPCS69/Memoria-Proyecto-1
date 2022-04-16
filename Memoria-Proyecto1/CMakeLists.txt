cmake_minimum_required(VERSION 3.21)
project(Memoria_Proyecto1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)

add_executable(Memoria_Proyecto1 servidorMain.cpp mainGUI.cpp mainGUI.h servMem.cpp servMem.h gMemEjm.cpp gMemEjm.h
        clienteMem.cpp clienteMem.h)

add_executable(Servidor servidorMain.cpp servMem.cpp servMem.h)

add_executable(Cliente  clienteMain.cpp clienteMem.cpp clienteMem.h)

# Tell cmake where Qt is located
set(Qt5_DIR "~/Qt/5.12.8/clang_64/lib/cmake/Qt5")

# Tell cmake to find the modules Qt5Core and Qt5widgets
find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

# Link the library to the executable
target_link_libraries(Memoria_Proyecto1 Qt5::Core Qt5::Widgets)
target_link_libraries(Cliente Qt5::Core Qt5::Widgets)
target_link_libraries(Servidor Qt5::Core Qt5::Widgets)