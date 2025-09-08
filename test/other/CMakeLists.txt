project(sort-test)

list(APPEND TestList 
    SwapTest
    IteratorsTest
    ListIteratorTest
)

foreach(Test IN LISTS TestList)
    add_executable(${Test} ${Test}.cpp)

    set_property(TARGET ${Test} PROPERTY CXX_STANDARD 17)

    target_link_libraries(${Test} 
        PRIVATE 
            GTest::gtest_main
    )

    add_test(NAME ${Test} COMMAND ${Test})
endforeach()

include(GoogleTest)