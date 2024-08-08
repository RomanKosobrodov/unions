set(UNIONS "unions")

set(UNIONS_HEADER_FILES
)

set(UNIONS_SOURCE_FILES
    main.cpp
)

add_executable(${UNIONS} 
    ${UNIONS_HEADER_FILES}
    ${UNIONS_SOURCE_FILES}
)

target_link_libraries(${UNIONS}
)

target_compile_definitions(${UNIONS} PRIVATE CMAKE_EXPORT_COMPILE_COMMANDS=1)
