find_package(Qt5 REQUIRED COMPONENTS Core Widgets)

set(SOURCES
    command.cpp

    basemenuactionscontainer.cpp

    menuactionscontainer.cpp
    menubaractionscontainer.cpp
    contextmenuactionscontainer.cpp
    toolbaractionscontainer.cpp

    basemenumanager.cpp
)

set(HEADERS
    command.h

    iactionscontainer.h

    ibasemenuactionscontainer.h
    basemenuactionscontainer.h

    menuactionscontainer.h
    menubaractionscontainer.h
    contextmenuactionscontainer.h
    toolbaractionscontainer.h

    imenumanager.h
    basemenumanager.h
)

ADD_LIBRARY(mcore STATIC ${HEADERS} ${SOURCES})

target_link_libraries(mcore PRIVATE Qt5::Widgets Qt5::Core)
