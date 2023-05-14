cmake_minimum_required(VERSION 3.4)

project(Program)

#Ustaw we własnej zmiennej SOURCE_FILES zbiór plików źródłowych projektu
set(SOURCE_FILES src/main.cpp ../library/src/model/client.cpp ../library/src/model/address.cpp ../library/include/model/vehicle.h ../library/src/model/vehicle.cpp ../library/src/model/rent.cpp ../library/include/model/rent.h ../library/include/typedefs.h ../library/include/model/bicycle.h ../library/src/model/bicycle.cpp ../library/src/model/motorVehicle.cpp ../library/src/model/car.cpp ../library/include/model/moped.h ../library/src/model/moped.cpp ../library/include/repositories/ClientRepository.h ../library/src/repositories/ClientRepository.cpp ../library/include/repositories/RentRepository.h ../library/src/repositories/RentRepository.cpp ../library/include/repositories/StorageContainer.h ../library/include/repositories/VehicleRepository.h ../library/src/repositories/VehicleRepository.cpp ../library/src/repositories/StorageContainer.cpp)

#Włącz powyższy zbiór plików do zbudowania programu wykonywalnego Program
add_executable(Program ${SOURCE_FILES} ../library/src/model/client.cpp)

find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" "date_time" REQUIRED)

target_link_libraries(Program ${Boost_DATE_TIME_LIBRARY})

#Określenie zależności pomiędzy projektami Program i Biblioteka
target_link_libraries(Program Library)
#Dołącz katalog include podprojektu Program do globalnej listy. Dzięki temu każdy inny podprojekt będzie ten katalog "widział"
target_include_directories(Program PUBLIC include)
enable_testing()
