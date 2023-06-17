cmake_minimum_required(VERSION 3.4)

project(Library)

set(SOURCE_FILES
        test/master.cpp src/model/Game.cpp include/model/Game.h include/typedefs.h src/model/Player.cpp include/model/Player.h src/model/Board.cpp include/model/Board.h src/model/Field.cpp include/model/Field.h src/model/units/Unit.cpp include/model/units/Unit.h src/model/units/Pawn.cpp include/model/units/Pawn.h src/model/units/King.cpp include/model/units/King.h src/model/units/Queen.cpp include/model/units/Queen.h src/model/units/Rook.cpp include/model/units/Rook.h src/model/units/Bishop.cpp include/model/units/Bishop.h src/model/units/Knight.cpp include/model/units/Knight.h include/model/MainFrame.h src/model/MainFrame.cpp include/model/App.h src/model/App.cpp include/model/GameFrame.h include/model/UI.h src/model/UI.cpp src/model/GameFrame.cpp test/UnitTest.cpp test/UnitTest.cpp test/FieldTest.cpp test/GameTest.cpp)

#Utwórz bibliotekę typu STATIC, SHARED albo MODULE ze wskazanych źródeł
add_library(Library ${SOURCE_FILES})

target_include_directories(Library PUBLIC include)
target_include_directories(Library PUBLIC include/model)
target_include_directories(Library PUBLIC include/model/units)
target_include_directories(Library PUBLIC src)
target_include_directories(Library PUBLIC src/model)
target_include_directories(Library PUBLIC src/model/units)

#add_subdirectory(../wxWidgets-3.2.2.1)
#
if(APPLE)
    find_package(wxWidgets REQUIRED COMPONENTS net core base)
    if(wxWidgets_USE_FILE) # not defined in CONFIG mode
        include(${wxWidgets_USE_FILE})
    endif()
endif()

enable_testing()

find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

set(SOURCE_TEST_FILES
        test/master.cpp test/UnitTest.cpp test/UnitTest.cpp test/FieldTest.cpp test/GameTest.cpp) # tu w przyszłości będą dodawane pliki źródłowe testów

add_executable (LibraryTest ${SOURCE_TEST_FILES})
if(LINUX)

    target_link_libraries(Library wx::net wx::core wx::base)
endif()
if(APPLE)
    message("hi")
    target_link_libraries(Library ${wxWidgets_LIBRARIES})

elseif(UNIX)
    target_link_libraries(Library wx::net wx::core wx::base)

endif()

#dołącz bibliotekę z testowanymi klasami oraz bibliotekę boost.test do programu testów
target_link_libraries (LibraryTest
        Library
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

#dodaj test TestBiblioteki1. Instrukcji cmake add_test może być wiele.
#Dodatkowe parametry wpływają na szczegółowość generowanego raportu. Standardowo znajduje się on w Testing/Temporary.
add_test(LibraryTest1 LibraryTest
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )
		
add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})