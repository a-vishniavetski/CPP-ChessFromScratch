cmake_minimum_required(VERSION 3.4)

project(Program)

#Ustaw we własnej zmiennej SOURCE_FILES zbiór plików źródłowych projektu
set(SOURCE_FILES src/main.cpp ../library/include/model/MainFrame.h ../library/src/model/MainFrame.cpp ../library/include/model/App.h ../library/src/model/App.cpp ../library/include/model/GameFrame.h ../library/include/model/UI.h ../library/src/model/UI.cpp ../library/src/model/GameFrame.cpp)

#add_subdirectory(../wxWidgets-3.2.2.1)
#
#find_package(wxWidgets REQUIRED COMPONENTS net core base)
#if(wxWidgets_USE_FILE) # not defined in CONFIG mode
#    include(${wxWidgets_USE_FILE})
#endif()
#Włącz powyższy zbiór plików do zbudowania programu wykonywalnego Program
add_executable(Program ${SOURCE_FILES})
target_link_libraries(Program wx::net wx::core wx::base)

#Określenie zależności pomiędzy projektami Program i Biblioteka
target_link_libraries(Program Library)

#Dołącz katalog include podprojektu Program do globalnej listy. Dzięki temu każdy inny podprojekt będzie ten katalog "widział"
target_include_directories(Program PUBLIC include)
enable_testing()

