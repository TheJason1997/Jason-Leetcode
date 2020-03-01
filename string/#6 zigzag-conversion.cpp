// Time:  O(n)
// Space: O(1)

class Solution {
public:
    string convert(string s, int numRows) {
        // attention
        if (numRows == 1) {
            return s;
        }

        string zigzag;
        int step = 2 * numRows - 2;

        for (int i = 0; i < numRows; ++i) { //row
            for (int j = 0; j + i < s.length(); j += step) {  // ori string
                zigzag.push_back(s[j + i]); // the first and the last row

                if (i > 0 && i < numRows - 1 && j + step - i < s.length()) {    // except the first and the last row
                    zigzag.push_back(s[j + step - i]);
                }
            }
        }

        return zigzag;
    }
};

/**
 * first row: idx = k(2 * numRows - 2)
 * last row: idx = k(2 * numRows - 2) + numRows - 1
 * mid row: idx = k(2 * numRows - 2) + i and (k+1)(2 * numRows - 2) - i
*/