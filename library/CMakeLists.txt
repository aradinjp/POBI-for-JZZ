cmake_minimum_required(VERSION 3.4)
project(Library)

set(SOURCE_FILES src/model/Client.cpp
        include/model/Client.h
        include/typedefs.h
        src/model/ClientType.cpp
        include/model/ClientType.h
        src/model/ClientType/Honorary.cpp
        include/model/ClientType/Honorary.h
        src/model/ClientType/Default.cpp
        include/model/ClientType/Default.h
        src/model/Order.cpp
        include/model/Order.h
        src/model/Transaction.cpp
        include/model/Transaction.h
        include/repositories/ClientRepository.h
        include/repositories/OrderRepository.h
        include/repositories/TransactionRepository.h
        src/repositories/ClientRepository.cpp
        src/repositories/OrderRepository.cpp
        src/repositories/TransactionRepository.cpp
        include/menagers/ClientMenager.h
        src/menagers/ClientMenager.cpp src/menagers/OrderMenager.cpp include/menagers/OrderMenager.h include/menagers/TransactionMenager.h test/menagers/TransactionMenagerTest.cpp src/menagers/TransactionMenager.cpp)

#Utwórz bibliotekę typu STATIC, SHARED albo MODULE ze wskazanych źródeł
add_library(Library ${SOURCE_FILES})

target_include_directories(Library PUBLIC include include/model include/repositories include/menagers include/model/ClientType)

enable_testing() # dodane wcześniej w punkcie 2
find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

set(SOURCE_TEST_FILES
        test/model/master.cpp
        test/model/ClientTest.cpp
        test/model/OrderTest.cpp
        test/model/TransactionTest.cpp
        test/repositories/ClientRepositoryTest.cpp
        test/repositories/TransactionRepositoryTest.cpp
        test/repositories/OrderRepositoryTest.cpp
        test/menagers/ClientMenagerTest.cpp test/menagers/OrderMenagerTest.cpp) # tu w przyszłości będą dodawane pliki źródłowe testów

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