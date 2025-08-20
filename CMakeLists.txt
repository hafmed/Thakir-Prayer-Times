cmake_minimum_required(VERSION 3.16)

project(thakir_prayer_times VERSION 0.1 LANGUAGES CXX C)

set(APP_VERSION 2.0.5)

set(CMAKE_INCLUDE_CURRENT_DIR ON)


set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

configure_file(version.h.in version.h)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Multimedia)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Multimedia)


qt_standard_project_setup(REQUIRES 6.5)

set(CMAKE_AUTORCC ON)

set(ANDROID_PACKAGE_SOURCE_DIR ${PROJECT_SOURCE_DIR}/android CACHE INTERNAL "")


set(PROJECT_SOURCES
        main.cpp
        prayer.c
        prayer.h
        thakir_prayer_times.cpp
        thakir_prayer_times.h
        thakir_prayer_times.ui
        qtresource.qrc
        io.github.hafmed.Thakir-Prayer-Times.metainfo.xml
        io.github.hafmed.Thakir-Prayer-Times.desktop
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(thakir_prayer_times
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        about.cpp about.h about.ui astro.c astro.h constants.h prayer.c prayer.h qtresource.qrc winlogohaf.rc
        version.h.in
        io.github.hafmed.Thakir-Prayer-Times.png io.github.hafmed.Thakir-Prayer-Times.svg
        io.github.hafmed.Thakir-Prayer-Times
        io.github.hafmed.Thakir-Prayer-Times.yaml
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET thakir_prayer_times APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(thakir_prayer_times SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(thakir_prayer_times
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(thakir_prayer_times PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt6::Multimedia)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.thakir_prayer_times)
endif()
set_target_properties(thakir_prayer_times PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS thakir_prayer_times
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(thakir_prayer_times)
endif()


install(FILES ${PROJECT_SOURCE_DIR}/io.github.hafmed.Thakir-Prayer-Times.metainfo.xml DESTINATION $ENV{HOME}/.local/app/share/metainfo/io.github.hafmed.Thakir-Prayer-Times.metainfo.xml)
