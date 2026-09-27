/**
 * 6. Zigzag Conversion
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/zigzag-conversion/
 *
 * Problem:
 * The string "PAYPALISHIRING" is written in a zigzag pattern
 * on a given number of rows and then read line by line.
 *
 * Return the converted string.
 *
 *
 * Example 1:
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 *
 *
 * Example 2:
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 *
 *
 * Example 3:
 * Input: s = "A", numRows = 1
 * Output: "A"
 *
 *
 * Technique:
 * Cycle Pattern / Mathematical Traversal
 *
 *
 * Key Idea:
 * The zigzag pattern repeats after:
 *
 *     cycle = 2 * numRows - 2
 *
 * For each row, characters can be collected by jumping through
 * this cycle.
 *
 * The first and last rows contain only vertical characters.
 * The middle rows also contain a diagonal character inside each cycle.
 *
 *
 * Approach:
 * 1. If numRows is 1 or greater than or equal to the string length,
 *    return the original string (no zigzag is possible).
 * 2. Calculate the cycle length:
 *
 *       cycle = 2 * numRows - 2
 *
 * 3. Process each row from top to bottom.
 * 4. Add the vertical character at index i.
 * 5. For middle rows, calculate the diagonal character:
 *
 *       diagonal = i + cycle - 2 * row
 *
 * 6. Add the diagonal character if it is within the string.
 * 7. Return the resulting string.
 *
 *
 * Complexity:
 * Time: O(n)
 * Space: O(1) extra space
 *
 * n = length of the string
 */
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size())
            return s;

        string result;

        int cycle = 2 * numRows - 2;

        for (int row = 0; row < numRows; row++) {

            for (int i = row; i < s.size(); i += cycle) {

                // Vertical character
                result += s[i];

                // Diagonal character
                int diagonal = i + cycle - 2 * row;

                if (row != 0 &&
                    row != numRows - 1 &&
                    diagonal < s.size()) {
                    result += s[diagonal];
                }
            }
        }

        return result;
    }
};



/**
 * Alternative Approach:
 *
 * Technique:
 * Row Simulation / Direction Flipping
 *
 *
 * Key Idea:
 * Instead of computing character positions mathematically, simulate
 * the zigzag traversal.
 *
 * The row pointer moves down (1, 2, 3, ...) until it hits the last row,
 * then reverses and moves up until it hits the first row, repeating —
 * this bounce is what "direction flipping" refers to.
 *
 *
 * Approach:
 * 1. If numRows is 1 or greater than or equal to the string length,
 *    return the original string.
 *
 * 2. Create one string bucket per row.
 *
 * 3. Walk through the string character by character and append each
 *    character to the current row.
 *
 * 4. When the current row reaches the top, move downward.
 *
 * 5. When the current row reaches the bottom, move upward.
 *
 * 6. Concatenate all row buckets to form the result.
 *
 *
 * Complexity:
 * Time:  O(n)
 * Space: O(n) — auxiliary space
 *
 * n = length of the string
 *
 *
 * Difference from Primary Approach:
 *
 * The primary approach calculates the final character positions
 * directly using the cycle formula. It therefore uses O(1)
 * auxiliary space apart from the output.
 *
 * The alternative approach directly simulates the zigzag pattern.
 * It is easier to understand but requires O(n) extra space for
 * the row buffers.
 */
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length())
            return s;

        vector<string> rows(numRows);

        int currentRow = 0;
        int direction = 1;

        for (char c : s) {
            rows[currentRow] += c;

            if (currentRow == 0)
                direction = 1;
            else if (currentRow == numRows - 1)
                direction = -1;

            currentRow += direction;
        }

        string result;

        for (string& row : rows) {
            result += row;
        }

        return result;
    }
};