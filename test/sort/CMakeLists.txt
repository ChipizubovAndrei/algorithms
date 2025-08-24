project(sort-test)

list(APPEND TestList 
    SortTest
)

foreach(Test IN LISTS TestList)
    add_executable(${Test} ${Test}.cpp)

    set_property(TARGET ${Test} PROPERTY CXX_STANDARD 17)

    target_link_libraries(${Test} 
        PRIVATE 
            sort
            GTest::gtest_main
    )

    add_test(NAME ${Test} COMMAND ${Test})
endforeach()

include(GoogleTest)