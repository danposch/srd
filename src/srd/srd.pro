! include( $$_PRO_FILE_PWD_/../../common.pri ){
    error( "Couldn't find the common.pri file!" )
}

TEMPLATE = app

DESTDIR = ../../bin
TARGET = srd

LIBS += 

HEADERS += 
SOURCES += \
    main.cc
