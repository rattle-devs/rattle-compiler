add_subdirectory(lib)
add_subdirectory(AST)



set (SOURCES
        ${SOURCES}
        ${CMAKE_CURRENT_SOURCE_DIR}/Token.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Lexer.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Compiler.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Parser.cpp
        PARENT_SCOPE
        )
