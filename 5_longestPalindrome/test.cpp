#include <iostream>
#include <string>
#include <stdio.h>

#define STRING_MAXLENGTH 1000
using namespace std;

string longestPalindrome(string s) {
    if (s.empty())
    {
        return s;
    }
    else
    {
        int  len    = s.length();
        // bool dp[][] = new bool[STRING_MAXLENGTH][STRING_MAXLENGTH];
        bool dp[1000][1000];
        // bool dp_debugger_cur = false;
        // bool dp_debugger_pre = false;
        // char s_debugger_i, s_debugger_j;
        int  right  = 0;
        int  left   = 0;
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
}

int main() {
    string s("aacdvfgbbgfvadada");
    string return_s;

    return_s = longestPalindrome(s);
    
    cout << "原字符串为：" << s << endl;
    cout << "最大回文字符串：" << return_s << endl;
    cout << "应该的最大回文字符串：" << s.substr(4,8) << endl;
    return 0;
}