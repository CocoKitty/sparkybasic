#pragma once
// By Edith Pugh on 2026-04-10

#include <variant>
#include <string>
#include <cassert>

namespace basic {
    struct Token {
        enum Type {
            // Like NumLiteral, but no funny business with negatives or non-int
            // values.
            LineNum,

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
            GreaterThanOrEqualTo,

            // Just used for indexing lists, as far as I can tell
            OpenParen,
            CloseParen,

            // For variable names
            Var,
        } type; // End enum Type

        std::variant<std::monostate, std::string, double, size_t> value;

        static Token from_literal(double num);
        static Token from_literal(std::string&& str);
        static Token from_line_num(size_t num);
        static Token from_var_or_keyword(std::string&& id);
        
        Token(Type sym)
            : type(sym)
            , value(std::monostate()) {
            assert(sym != NumLiteral && sym != StrLiteral);
        }
    private:
        Token(Type type, std::variant<std::monostate, 
            std::string, double, size_t>&& value)
            : type(type)
            , value(std::move(value)) {}
    }; // End struct Token
}