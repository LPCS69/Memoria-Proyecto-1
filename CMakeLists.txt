cmake_minimum_required(VERSION 3.21)
project(Memoria_Proyecto1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)

add_executable(Memoria_Proyecto1)

add_executable(Servidor MAINservidor.cpp servidorMememoria.cpp servidorMememoria.h)

add_executable(Cliente MAINcliente.cpp clienteMemoria.cpp clienteMemoria.h)

# Tell cmake where Qt is located
set(Qt5_DIR "~/Qt/5.12.8/clang_64/lib/cmake/Qt5")

# Tell cmake to find the modules Qt5Core and Qt5widgets
find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

# Link the library to the executable
target_link_libraries(Memoria_Proyecto1 Qt5::Core Qt5::Widgets)
target_link_libraries(Cliente Qt5::Core Qt5::Widgets)
target_link_libraries(Servidor Qt5::Core Qt5::Widgets)