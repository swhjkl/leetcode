/*
 * @lc app=leetcode id=65 lang=cpp
 *
 * [65] Valid Number
 */

// @lc code=start
class Solution {
public:
    bool isNumber(string s) {
        enum State {
            INIT = 0,
            SIGNED,
            BEGIN_DOTTED,
            INTERGERED,
            DOTTED,
            DECIMALED,
            EXPONENTED,
            EXPONENT_SIGNED,
            EXPONENT_INTERGERED,
        } state = INIT;
        enum CharType {
            DIGIT,
            SIGN,
            EXPONENT,
            DOT
        } char_type;

        unordered_map<State, unordered_map<CharType, State>> dfa{
            { INIT, { { DIGIT, INTERGERED }, { SIGN, SIGNED }, { DOT, BEGIN_DOTTED } } },
            { SIGNED, { { DIGIT, INTERGERED }, { DOT, BEGIN_DOTTED } } },
            { BEGIN_DOTTED, { { DIGIT, DECIMALED } } },
            { INTERGERED, { { DIGIT, INTERGERED }, { DOT, DOTTED }, { EXPONENT, EXPONENTED } } },
            { DOTTED, { { DIGIT, DECIMALED }, { EXPONENT, EXPONENTED } } },
            { DECIMALED, { { DIGIT, DECIMALED }, { EXPONENT, EXPONENTED } } },
            { EXPONENTED, { { DIGIT, EXPONENT_INTERGERED }, { SIGN, EXPONENT_SIGNED } } },
            { EXPONENT_SIGNED, { { DIGIT, EXPONENT_INTERGERED } } },
            { EXPONENT_INTERGERED, { { DIGIT, EXPONENT_INTERGERED } } },
        };

        for (auto &&c : s) {
            if (c == '+' || c == '-') {
                char_type = SIGN;
            } else if (c >= '0' && c <= '9') {
                char_type = DIGIT;
            } else if (c == 'e' || c == 'E') {
                char_type = EXPONENT;
            } else if (c == '.') {
                char_type = DOT;
            } else {
                return false;
            }
            state = dfa[state][char_type];
            if (state == INIT) {
                return false;
            }
        }
        return state == INTERGERED || state == DOTTED || state == DECIMALED || state == EXPONENT_INTERGERED;
    }
};
// @lc code=end

