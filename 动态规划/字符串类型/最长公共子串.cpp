/*
 * 来源: LintCode
 * 题目: 最长公共子串
 *
 * 描述:
 * 给出两个字符串，找到最长公共子串，并返回其长度。
 *
 * 思路:
 * dp[i][j] = dp[i - 1][j - 1] + 1  if s[i - 1] = t[i - 1]
*/
class Solution {
public:
    /**
     * @param A: A string
     * @param B: A string
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        int len1 = A.size(), len2 = B.size();
        int ans = 0;
        vector<vector<int> > dp(len1 + 1, vector<int>(len2 + 1, 0));
        //dp[i][0] = 0; i > 0
        //dp[0][j] = 0; j > 0
        //dp[i][j] = 1 + dp[i - 1][j - 1] if s[i - 1] = t[j - 1]
        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
};