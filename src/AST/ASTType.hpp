#ifndef RATTLE_COMPILER_AST_TYPE_HPP
#define RATTLE_COMPILER_AST_TYPE_HPP

#include <string>
#include <vector>
#include "ASTExpression.hpp"

using namespace std;

class ASTType {
    public:
        string* identifier;
        vector<ASTType*>* generics;
        size_t arraySize; // onnly if isArray = true and size defined
        bool isArray;
        bool isSizeDefined;
        char _pad[6];

};


#endif //RATTLE_COMPILER_AST_TYPE_HPP
