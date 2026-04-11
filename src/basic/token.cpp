// By Edith Pugh on 2026-04-11

// Implements some of the static functions from token.hpp for help with
// constructing

#include "token.hpp"

using namespace basic;

Token Token::from_literal(double num) {
    return Token(Token::NumLiteral, num);
}
Token Token::from_literal(std::string&& str) {
    return Token(Token::StrLiteral, str);
}
Token Token::from_line_num(size_t num) {
    return Token(Token::LineNum, num);
}
Token Token::from_var_or_keyword(std::string&& id) {
    // todo
    assert(false);
    return Token(Token::Var);
}