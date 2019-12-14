/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start\
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty())
        {
            return s;
        }
        else
        {
            int  len    = s.length();
            // bool dp[][] = new bool[STRING_MAXLENGTH][STRING_MAXLENGTH];
            // bool dp_debugger_cur = false;
            // bool dp_debugger_pre = false;
            // char s_debugger_i, s_debugger_j;
            int  right  = 0;
            int  left   = 0;
            bool dp[1000][1000];
            int i, j;
            for (i = len-2; i >= 0; i--) {
                dp[i][i] = true;
                for (j = i+1; j < len; j++) {
                // dp_debugger_pre = dp[i+1][j-1];
                // s_debugger_i = s[i];
                // s_debugger_j = s[j];
                dp[i][j] = (s[i] == s[j]) && ((j-i < 3) || (dp[i+1][j-1]));
                // dp_debugger_cur = dp[i][j];
                if ((dp[i][j] == true) && (right-left < j-i)) {
                    right = j;
                    left  = i;
                }
                }
            }
            return s.substr(left, right-left+1);
        }
};
// @lc code=end

