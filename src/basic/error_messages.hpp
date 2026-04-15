#pragma once
// By Edith Pugh on 2026-04-14

#include <string>

namespace basic {
    // PE0*, line number errors
    const std::string k_msg_line_num_leading_zero
        = "PE00: Line numbers cannot have leading zeroes.";
    const std::string k_msg_line_num_negative
        = "PE01: Line numbers cannot be negative.";
    const std::string k_msg_line_num_non_int
        = "PE02: Line numbers must be integers";
    const std::string k_msg_line_num_missing_space
        = "PE03: Missing space after line number";

    // PE1*, string literal errors
    const std::string k_msg_unexpected_eol_reading_string
        = "PE10: Unexpected end of line while reading string";
    const std::string k_msg_unknown_backspace_sequence
        = "PE11: Unknown backspace sequence: \\";

    // PE2*, num literal errors
    const std::string k_msg_ending_in_dot
        = "PE20: Num literal cannot end in a dot. If this is not true in the "
        "original implementation of Altair Basic, please raise an issue to that"
        " effect.";

    // PE8*, miscellaneous errors
    const std::string k_msg_unknown_token
        = "PE80: Unknown token: ";
}