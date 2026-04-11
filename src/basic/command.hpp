#pragma once
// By Edith Pugh on 2026-04-10, Sparky's third birthday

#include "token.hpp"
#include "evalenv.hpp"

#include <string>
#include <vector>
#include <variant>

namespace basic {
    // A class that 
    class Command {
        std::vector<Token> tokens;
    public:
        struct EvalResult {
            struct Ok { std::string out; };
            struct Err { std::string msg; };
            std::variant<Ok, Err> result;
        }; // end struct EvalResult
        // a direct command is immediately executed by the interpreter, whereas
        // an indirect command is saved and executed after the next RUN command.
        bool is_direct_command(void) const;
        // returns the line number if Command is an indirect command
        // PANICS: if Command is in fact a direct command
        unsigned int get_line_number(void) const;
        // executes command on env, may mutate env
        EvalResult eval(EvalEnv& env) const;
        // basic constructor for command
        Command(std::vector<Token>&& tokens)
            : tokens(std::move(tokens)) {}
    }; // End Class Command
} // End namespace basic