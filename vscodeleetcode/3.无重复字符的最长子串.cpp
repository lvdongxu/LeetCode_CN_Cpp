/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // My answer 1
        // string final_String;
        // // string string_Cache;
        // int max_Length = 0;
        // // if (s == " ") {
        // //     return 1;
        // // }
        // for (int i = 0; i < s.length(); i++) {
        //     if (final_String.find(s[i]) == string::npos) {
        //         final_String += s[i];
        //     }
        //     else {
        //         if (max_Length < final_String.length()) {
        //             max_Length = final_String.length();
        //             // string_Cache = final_String;
        //         }
        //         final_String = final_String.substr(final_String.find(s[i])+1) + s[i];
        //     }
        //     if ((i == s.length()-1) && (max_Length < final_String.length())) {
        //         max_Length = final_String.length();
        //         // string_Cache = final_String;
        //     }
        // }
        // return max_Length;
        // // 滑动窗解法，资源较少
        // // int start(0), end(0), length(0), result(0);
        // // int sSize = int(s.size());
        // // while (end < sSize)
        // // {
        // //     char tmpChar = s[end];
        // //     for (int index = start; index < end; index++)
        // //     {
        // //         if (tmpChar == s[index])
        // //         {
        // //             start = index + 1;
        // //             length = end - start;
        // //             break;
        // //         }
        // //     }

        // //     end++;
        // //     length++;
        // //     result = max(result, length);
        // // }
        // // return result;
        // // // 哈希表查找。超快
        int m[256]={0};//字符有256个
        int left=0;//查找的左边界
        int mlen=0;//结果
        for(int i=0;i<s.length();i++)
        {
            if(m[s[i]]==0||m[s[i]]<left)
            {
                mlen=max(mlen,i-left+1);
            }
            else
            {
                left=m[s[i]];
            }
            m[s[i]]=i+1;
        }
        return mlen;
    }
};
// @lc code=end

