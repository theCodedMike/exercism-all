#include "matching_brackets.h"

#include <algorithm>

#include "stack"

namespace matching_brackets {
    bool match(const char left, const char right) {
        if ((left == '(' && right == ')') || (left == '[' && right == ']') || (left == '{' && right == '}'))
            return true;

        return false;
    }

    bool check(const std::string_view input) {
        std::stack<char> stack;

        for (char ch: input) {
            if (ch == '(' || ch == '[' || ch == '{')
                stack.push(ch);
            else if (ch == ')' || ch == ']' || ch == '}') {
                if (stack.empty())
                    return false;
                if (const char left = stack.top(); !match(left, ch))
                    return false;
                stack.pop();
            }
        }

        return stack.empty();
    }
} // namespace matching_brackets
