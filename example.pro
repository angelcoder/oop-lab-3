TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt


INCLUDEPATH += "/Users/anhelinalohvina/Desktop/SFML/include"
DEPENDPATH += "/Users/anhelinalohvina/Desktop/SFML/include"

LIBS += -L"/Users/anhelinalohvina/Desktop/SFML/lib"

LIBS += -L"/Users/anhelinalohvina/Desktop/SFML" \
        -lsfml-graphics \
        -lsfml-window \
        -lsfml-system \
        -lsfml-audio \
        -lsfml-network


SOURCES += \
        main.cpp \
    divideandconqueralgo.cpp \
    javis.cpp \
    graham.cpp \
    kirpatrick.cpp

HEADERS += \
    divideandconqueralgo.h \
    javis.h \
    graham.h \
    point.h \
    kirpatrick.h

