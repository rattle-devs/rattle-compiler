#include "utils.hpp"

using namespace std;

bool isLiteral(string *text) {
    if (isdigit(text->at(0)) || text->starts_with('.') || text->starts_with('"') || text->starts_with('\'') ||
        text->starts_with('`')) {
        return true;
    }
    return false;
}

bool isKeyword(string *text) {
    string keywords[] = {KEYWORDS};
    for (auto &keyword : keywords) {
        if (*text == keyword) {
            return true;
        }
    }
    return false;
}

bool isOperator(string *text) {
    string operators[] = {OPERATORS};
    for (auto &i : operators) {
        if (*text == i) {
            return true;
        }
    }
    return false;
}

bool isSeparator(string *text) {
    string separators[] = {SEPARATORS};
    for (auto &separator : separators) {
        if (*text == separator) {
            return true;
        }
    }
    return false;
}

bool isWordOperator(string *text) {
    string word_operators[] = {WORD_OPERATORS};
    for (auto &word_operator : word_operators) {
        if (*text == word_operator) {
            return true;
        }
    }
    return false;
}

bool isAlphanumeric(char ch) {
    return isalnum(ch) || ch == '"' || ch == '\'' || ch == '`' || ch == '_';
}
