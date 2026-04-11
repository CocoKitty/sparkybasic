// By Edith Pugh on 2026-04-10

#include "parse.hpp"

#include "token.hpp"

#include <vector>
#include <cctype>
#include <strstream>
#include <string>

using namespace basic;

ParseResult parse_line(const std::string& line) {
    std::vector<Token> tokens;
    size_t index = 0;
    if (line[0] == '0') {
        return {
            ParseResult::Err{"Line numbers cannot have leading zeroes."}
        };
    }
    // eat linenum rq
    std::strstream line_num_stream;
    while (index < line.size() && std::isdigit(line[index])) {
        line_num_stream << line[index];
        index++;
    }
    if (!std::isspace(line[index])) {
        return {
            ParseResult::Err{"Missing space between line number and command."}
        };
    }
    std::string line_num_string = line_num_stream.str();
    if (line_num_string.size() != 0) {
        // shouldn't throw, since it's just a string of digits
        size_t line_num = std::stoul(line_num_string);
        tokens.push_back(Token::from_line_num(line_num));
    }
    // now get to actual tokenizing
    while (index < line.size()) {
        switch (line[index]) {
            case '(': 
                tokens.push_back(Token(Token::OpenParen));
                index++;
                break;
            case ')':
                tokens.push_back(Token(Token::CloseParen));
                index++; 
                break;
            case '=':
                tokens.push_back(Token(Token::Equal));
            case '>':
                if (index + 1 < line.size() || line[index + 1] != '=') {
                    tokens.push_back(Token(Token::GreaterThan));
                } else {
                    tokens.push_back(Token(Token::GreaterThanOrEqualTo));
                }
            case '<':
                if (index + 1 < line.size()
                    || line[index + 1] != '='
                    || line[index + 1] != '>') {
                    tokens.push_back(Token(Token::LessThan));
                } else if (line[index + 1] == '>') {
                    tokens.push_back(Token(Token::NotEqualTo));
                } else {
                    tokens.push_back(Token(Token::LessThanOrEqualTo));
                }
        } // end switch(line[index])
    } // end while(index < line.size())
    return {
        ParseResult::Ok{std::move(tokens)}
    };
} // end parse_line