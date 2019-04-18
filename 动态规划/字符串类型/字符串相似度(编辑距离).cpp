/*
 * 描述:
 * 对于序列 s 和 t，它们之间距离定义为：对二者其一进行几次以下的操作
 * (1)删去一个字符；
 * (2)插入一个字符；
 * (3)改变一个字符。
 * 每进行一次操作，计数增加1。
 * 将 s 和 t 变为同一个字符串的最小计数即为它们的距离
 *
 * 思路:
 * dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j])
 * dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] if s[i - 1] == t[j - 1] else dp[i - 1][j - 1] + 1)
 */
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size();
        if (len1 == 0 || len2 == 0) return len1 + len2;

        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        for (int i = 1; i <= len1; ++i) dp[i][0] = i;
        for (int j = 1; j <= len2; ++j) dp[0][j] = j;

        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                int tar1 = 1 + min(dp[i][j - 1], dp[i - 1][j]);
                int tar2 = word1[i - 1] == word2[j - 1] ? dp[i - 1][j - 1] : dp[i - 1][j - 1] + 1;
                dp[i][j] = min(tar1, tar2);
            }
        }
        return dp[len1][len2];
    }
};
};