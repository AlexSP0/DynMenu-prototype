find_package(Qt5 REQUIRED COMPONENTS Core Widgets)

set(SOURCES
    command.cpp

    uielements/basemenuactionscontainer.cpp

    basemenumanager.cpp

    uielements/uicontainer.cpp
    uielements/baseuielement.cpp
    uielements/uiqmenuelement.cpp
    uielements/uiqmenubarelement.cpp
    uielements/uiqtoolbarelement.cpp
)

set(HEADERS
    command.h

    uielements/ibasemenuactionscontainer.h
    uielements/basemenuactionscontainer.h

    imenumanager.h
    basemenumanager.h

    uielements/iactionscontainer.h
    uielements/iuielement.h
    uielements/uicontainer.h
    uielements/baseuielement.h
    uielements/uiqmenuelement.h
    uielements/uiqmenubarelement.h
    uielements/uiqtoolbarelement.h
)

ADD_LIBRARY(mcore STATIC ${HEADERS} ${SOURCES})

target_link_libraries(mcore PRIVATE Qt5::Widgets Qt5::Core)
