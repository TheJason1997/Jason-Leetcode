// Time:  O(n)
// Space: O(1)
// double pointer(counter)

class Solution {
public:
    int longestValidParentheses(string s) {
        return max(length(s.begin(), s.end(), '(', true), length(s.rbegin(), s.rend(), '(', false));
    }

private:
    template<typename T>
    int length(T begin, T end, char c, bool fromLeft) {
        int len = 0, left = 0, right = 0;

        for (T it = begin; it != end; ++it) {
            if (*it == c)
                ++left;
            else
                ++right;
            
            if (left == right)
                len = max(len, 2 * left);
            else if ((fromLeft == true && left < right) || (fromLeft == false && left > right))
                left = right = 0;
        }

        return len;
    }
};



// Time:  O(n)
// Space: O(n)
// dp + stack

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int len = 0;

        stk.emplace(-1);
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(')
                stk.emplace(i); // if '(', push the current idex into stk
            
            else {
                stk.pop();  // pop the top index
                if (stk.empty())
                    stk.emplace(i); // even now is ')', the current index should be emplaced
                else
                    len = max(len, i - stk.top()); // the current valid length = curret index - the top index after pop 
            }
        }

        return len;
    }
};