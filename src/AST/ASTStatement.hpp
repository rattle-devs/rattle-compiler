#ifndef RATTLE_COMPILER_AST_STATEMENT_HPP
#define RATTLE_COMPILER_AST_STATEMENT_HPP

#include <vector>
#include "ASTExpression.hpp"

using namespace std;

enum ASTStatementType: size_t {
    StatementArray,
    NOOP,
    Expression,
    Return,
    ForLoop,
    WhileLoop,
    IfCondition,
    ElseCondition,
    VariableDeclaration,
    TypeDeclaration,
    FunctionDeclaration,
};


class ASTStatement {
    public:
        ASTStatement() = default;

        ASTStatementType type;
};

class ASTStatementArray: public ASTStatement{
    public:
        ASTStatementArray() = default;

        vector<ASTStatement*>* statements;
};

class ASTStatementNOOP: public ASTStatement{
    public:
        ASTStatementNOOP() = default;
};

class ASTStatementExpression: public ASTStatement{
    public:
        ASTStatementExpression() = default;

        ASTExpression* expression;
};

class ASTStatementForLoop: public ASTStatement{
    public:
        ASTStatementForLoop() = default;

        ASTExpression* iterators;
        ASTExpression* array;
        ASTStatement* body;
};

class ASTStatementWhileLoop: public ASTStatement{
    public:
        ASTStatementWhileLoop() = default;

        ASTExpression* condition;
        ASTStatement* body;
};

class ASTStatementIfCondition: public ASTStatement{
    public:
        ASTStatementIfCondition() = default;

        ASTExpression* condition;
        ASTStatement* body;
};

class ASTStatementElseCondition: public ASTStatement{
    public:
        ASTStatementElseCondition() = default;

        ASTExpression* condition;
        ASTStatement* body;
};

#endif //RATTLE_COMPILER_AST_STATEMENT_HPP
