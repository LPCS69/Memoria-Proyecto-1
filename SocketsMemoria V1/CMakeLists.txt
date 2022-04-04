cmake_minimum_required(VERSION 3.21)
project(SocketsMemoria)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)

#add_executable(SocketsMemoria main.cpp  guiCliente.cpp guiCliente.h)
add_executable(CLIENT client.cpp )
add_executable(MAIN main.cpp guiCliente.cpp guiCliente.h threadGUI.cpp threadGUI.h)
add_executable(SERVER server.cpp)


# Tell cmake where Qt is located
set(Qt5_DIR "~/Qt/5.12.8/clang_64/lib/cmake/Qt5")

# Tell cmake to find the modules Qt5Core and Qt5widgets
find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

# Link the library to the executable
#target_link_libraries(SocketsMemoria Qt5::Core Qt5::Widgets)

target_link_libraries(CLIENT Qt5::Core Qt5::Widgets)
target_link_libraries(MAIN Qt5::Core Qt5::Widgets)