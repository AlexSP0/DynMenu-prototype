find_package(Qt5 REQUIRED COMPONENTS Core Widgets)

set(SOURCES
    command.h

    iactionscontainer.h
    baseactionscontainer.h
    menuactionscontainer.h
    contextmenuactionscontainer.h
    toolbaractionscontainer.h

    imenumanager.h
    basemenumanager.h
)

set(HEADERS
    command.cpp

    baseactionscontainer.cpp
    menuactionscontainer.cpp
    contextmenuactionscontainer.cpp
    toolbaractionscontainer.cpp

    basemenumanager.cpp
)

ADD_LIBRARY(mcore STATIC ${HEADERS} ${SOURCES})

target_link_libraries(mcore PRIVATE Qt5::Widgets Qt5::Core)
