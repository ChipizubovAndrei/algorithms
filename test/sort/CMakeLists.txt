project(sort-test)

list(APPEND TestList 
    QuickSortTest
)

foreach(Test IN LISTS TestList)
    add_executable(${Test} ${Test}.cpp ${PROJECT_SOURCES})

    set_property(TARGET ${Test} PROPERTY CXX_STANDARD 17)

    target_link_libraries(${Test} 
        PRIVATE 
            sort
            GTest::gtest_main
    )

    target_include_directories(${Test} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../app)

    add_test(NAME ${Test} COMMAND ${Test})
endforeach()