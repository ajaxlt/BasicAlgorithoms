/*
 * 描述:
 * 给出两个字符串，找到最长公共子序列(LCS)，返回LCS的长度
 *
 * 思路:
 * dp[i][j] = dp[i - 1][j - 1] + 1  if s[i - 1] = t[i - 1]
 * else max(dp[i - 1][j], dp[i][j - 1])
*/
class Solution {
public:
    /**
     * @param A: A string
     * @param B: A string
     * @return: The length of longest common subsequence of A and B
     */
    int longestCommonSubsequence(string &A, string &B) {
        int len1 = A.size(), len2 = B.size();
        vector<vector<int> > dp(len1 + 1, vector<int>(len2 + 1, 0));
        int ans = 0;
        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};
