cmake_minimum_required(VERSION 3.4)

project(Program)

#Ustaw we własnej zmiennej SOURCE_FILES zbiór plików źródłowych projektu
set(SOURCE_FILES src/main.cpp)

find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)
include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

#Włącz powyższy zbiór plików do zbudowania programu wykonywalnego Program
add_executable(Program ${SOURCE_FILES})

#Określenie zależności pomiędzy projektami Program i Biblioteka
target_link_libraries(Program Library)

#Dołącz katalog include podprojektu Program do globalnej listy. Dzięki temu każdy inny podprojekt będzie ten katalog "widział"
target_include_directories(Program PUBLIC include)