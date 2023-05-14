cmake_minimum_required(VERSION 3.4)
project(Library)

set(SOURCE_FILES
        src/model/client.cpp src/model/address.cpp src/model/vehicle.cpp src/model/rent.cpp ../program/src/main.cpp include/model/bicycle.h include/typedefs.h src/model/bicycle.cpp include/model/car.h include/model/motorVehicle.h src/model/motorVehicle.cpp src/model/car.cpp include/model/moped.h src/model/moped.cpp include/repositories/ClientRepository.h src/repositories/ClientRepository.cpp include/repositories/RentRepository.h src/repositories/RentRepository.cpp include/repositories/StorageContainer.h include/repositories/VehicleRepository.h src/repositories/VehicleRepository.cpp src/repositories/StorageContainer.cpp)
#Utwórz bibliotekę typu STATIC, SHARED albo MODULE ze wskazanych źródeł
add_library(Library ${SOURCE_FILES} src/model/client.cpp)

target_include_directories(Library PUBLIC include)
enable_testing()

find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" "date_time" REQUIRED)

target_link_libraries(Library ${Boost_DATE_TIME_LIBRARY})

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

set(SOURCE_TEST_FILES test/ClientTest.cpp test/master.cpp test/AddressTest.cpp test/VehicleTest.cpp test/RentTest.cpp include/typedefs.h  test/BicycleTest.cpp test/CarTest.cpp test/MopedTest.cpp test/RepositoryClientTest.cpp test/RepositoryRentTest.cpp test/RepositoryVehicleTest.cpp) # tu w przyszłości będą dodawane pliki źródłowe testów

add_executable (LibraryTest ${SOURCE_TEST_FILES})

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
