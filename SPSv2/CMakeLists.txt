cmake_minimum_required(VERSION 3.5)

project(SPSv2 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)


if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(SPSv2
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        View/customgraphicswidget.h View/customgraphicswidget.cpp
        Model/grid.h Model/grid.cpp
        View/component.h View/component.cpp
        Model/gridnode.h Model/gridnode.cpp
        Model/commonmodegrid.h Model/commonmodegrid.cpp
    )


# Thumbnail images:
file(GLOB thumbnail_files "View/thumbnailImages/*")

# Print the list of image files during CMake configuration
message(STATUS "List of Image Files:")
foreach(thumbnail_file ${thumbnail_files})
    message(STATUS "  ${thumbnail_file}")
endforeach()

qt_add_resources(thumbnailImageRSC "thumbnailImages"
    FILES
        ${thumbnail_files}
)


# Define target properties for Android with Qt 6 as:
#    set_property(TARGET SPSv2 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(SPSv2 SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(SPSv2
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(SPSv2 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_include_directories(SPSv2 PRIVATE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/View/>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Model/>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Controller/>
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.SPSv2)
endif()
set_target_properties(SPSv2 PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS SPSv2
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(SPSv2)
endif()
