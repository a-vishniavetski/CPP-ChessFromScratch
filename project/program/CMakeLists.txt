cmake_minimum_required(VERSION 3.4)


project(Program)

#Ustaw we własnej zmiennej SOURCE_FILES zbiór plików źródłowych projektu
set(SOURCE_FILES src/main.cpp ../library/include/model/ui/MainFrame.h ../library/src/model/ui/MainFrame.cpp ../library/include/model/ui/App.h ../library/src/model/ui/App.cpp ../library/include/model/ui/GameFrame.h ../library/include/model/ui/UI.h ../library/src/model/ui/UI.cpp ../library/src/model/ui/GameFrame.cpp ../library/include/model/ui/ResultsFrame.h ../library/src/model/ui/ResultsFrame.cpp ../library/include/model/SaveManager.h ../library/src/model/SaveManager.cpp)

if(APPLE)
    find_package(wxWidgets REQUIRED COMPONENTS net core base)
    if(wxWidgets_USE_FILE) # not defined in CONFIG mode
        include(${wxWidgets_USE_FILE})
    endif()
endif()
#add_subdirectory(../wxWidgets-3.2.2.1)
#

#Włącz powyższy zbiór plików do zbudowania programu wykonywalnego Program
add_executable(Program ${SOURCE_FILES})

if(APPLE)
    target_link_libraries(Program ${wxWidgets_LIBRARIES})

elseif(UNIX)
    target_link_libraries(Program wx::net wx::core wx::base)

endif()

#Określenie zależności pomiędzy projektami Program i Biblioteka
target_link_libraries(Program Library)

#Dołącz katalog include podprojektu Program do globalnej listy. Dzięki temu każdy inny podprojekt będzie ten katalog "widział"
target_include_directories(Program PUBLIC include)
enable_testing()

