project(sort-test)

list(APPEND TestList 
    QuickSortTest
)

foreach(Test IN LISTS TestList)
    add_executable(${Test} ${Test}.cpp)

    target_link_libraries(${Test} 
        PRIVATE 
            sort
            GTest::gtest_main
    )

    add_test(NAME ${Test} COMMAND ${Test})
endforeach()

include(GoogleTest)