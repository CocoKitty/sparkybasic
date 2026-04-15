#pragma once
// By Edith Pugh on 2026-04-14

#include <optional>
#include <string>

#include "lex_line.hpp"
#include "lex_line.hpp"

namespace basic {
    std::optional<LexResult::Err> lex_token(const std::string& line,
        size_t& index,
        std::vector<Token>& tokens);
}