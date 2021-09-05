#ifndef RATTLE_COMPILER_AST_PROGRAM_HPP
#define RATTLE_COMPILER_AST_PROGRAM_HPP

#include <sys/types.h>
#include <vector>
#include "ASTStatement.hpp"

using namespace std;

class ASTProgram {
    public:
        ASTProgram();

        vector<ASTStatement*>* statements;
};



#endif //RATTLE_COMPILER_AST_PROGRAM_HPP
