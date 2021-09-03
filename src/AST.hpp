#ifndef RATTLE_COMPILER_AST_HPP
#define RATTLE_COMPILER_AST_HPP

#include <sys/types.h>
#include <vector>

using namespace std;

enum struct ASTType : size_t{
    ASTProgram,
    ASTVariableDeclaration,
    ASTExpression,
    ASTNoop,
};

class AST {
    public:
        ASTType type;
        vector<AST> children;
};


#endif //RATTLE_COMPILER_AST_HPP
