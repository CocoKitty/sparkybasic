#pragma once
// By Edith Pugh on 2026-04-10

#include <variant>
#include <string>
#include <cassert>

namespace basic {
    struct Token {
        enum Type {
            // erases all stored commands
            New,
            // executes commands in program
            Run,
            // lists all the commands in program, sorted by line number.
            List,

            // frees a value
            Clear,
            // prints a value
            Print,
            // prints a question mark and space, then takes input and places it
            // in a variable. If no input is entered, the program is aborted.
            Input,

            // a number
            NumLiteral,
            // a string
            StrLiteral,

            // used for concatonating two values in print
            Semicolon,
            // indicates that the line will be split into 5 columns of 14, and
            // then moves to the next column.
            Comma,

            // Relation tokens, for comparing and, in the case of Equal,
            // assignment
            Equal,
            GreaterThan,
            LessThan,
            // The <> operator
            NotEqualTo,
            LessThanOrEqualTo,
            GreaterThanOrEqualTo
        } type; // End enum Type

        std::variant<std::monostate, std::string, double> value;

        Token(std::string&& str_literal)
            : type(StrLiteral)
            , value(str_literal) {}
        
        Token(double num)
            : type(NumLiteral)
            , value(num) {}
        
        Token(Type sym)
            : type(sym)
            , value(std::monostate()) {
            assert(sym != NumLiteral && sym != StrLiteral);
        } // End Token(Type sym)
    }; // End struct Token
}