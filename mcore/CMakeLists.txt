find_package(Qt5 REQUIRED COMPONENTS Core Widgets)

set(SOURCES
    menucontainer.h
    menuactionsmanager.h
    command.h
)

set(HEADERS
    menucontainer.cpp
    menuactionsmanager.cpp
    command.cpp
)

ADD_LIBRARY(mcore STATIC ${HEADERS} ${SOURCES})

target_link_libraries(mcore PRIVATE Qt5::Widgets Qt5::Core)
