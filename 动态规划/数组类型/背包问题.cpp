#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

/**
 * @brief 0-1 背包二维空间解法
 * 给定一系列物品的重量的和价值，在给定背包可承重量下，选择某些物品装入背包，使得装入背包的价值最大
 * 每个物品，要么取要么不取
 *
 * @param w : 物品重量
 * @param v : 物品价值
 * @param vol : 背包可承重量
 * @return 最大可能的价值
 */
int ZeroOneKnapsackByTwoDimesion (vector<int>& w, vector<int>& v, int vol) {
    int nums = w.size(); // 物品总数
    vector<vector<int> > dp(nums + 1, vector<int>(vol + 1, 0));
    //dp[i][j], 只考虑前 i 个物品，在背包容量 j 下的可能最大价值
    //dp[i][0] = 0, dp[0][j] = 0;
    for (int i = 1; i <= nums; ++i) {
        for (int j = 1; j <= vol; ++j) {
            // 如果当前考虑的物品重量比总约束还大，则一定放不进去
            if (w[i] > j) dp[i][j] = dp[i - 1][j];
            // 否则，比较放与不放的情况
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
        }
    }
    return dp[nums][vol];
}

/**
 * @brief 0-1 背包一维空间解法
 */
int ZeroOneKnapsackByOneDimesion (vector<int>& w, vector<int>& v, int vol) {
    int nums = w.size(); // 物品总数
    // 二维情况下 dp[i][j] 只与 dp[i - 1][k] 有关, 其中 k <= j
    // 当dp[i - 1] 计算完之后， 直接在其状态上更新即可, 而且每次都应该从右至左遍历
    // 因为要保证左边状态是上一层保留下来的
    vector<int> dp(vol + 1, 0);
    for (int i = 1; i <= nums; ++i) for (int j = vol; j >= 1; --j) {
        // 注意第二层循环逆序
        if (w[i] <= j) dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    }
    return dp[vol];
}

/**
 * @brief 完全 背包二维空间解法
 * 给定一系列物品的重量的和价值，在给定背包可承重量下，选择某些物品装入背包，使得装入背包的价值最大
 * 每个物品，可以不取，获取取任意个
 *
 * @param w : 物品重量
 * @param v : 物品价值
 * @param vol : 背包可承重量
 * @return 最大可能的价值
 */
int CompleteKnapsackByTwoDimesion (vector<int>& w, vector<int>& v, int vol) {
    int nums = w.size(); // 物品总数
    vector<vector<int> > dp(nums + 1, vector<int>(vol + 1, 0));
    for (int i = 1; i <= nums; ++i) {
        for (int j = 1; j <= vol; ++j) {
            // 加一层数量循环
            dp[i][j] = dp[i - 1][j];
            for (int k = 0; k <= j / w[i]; ++k) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k * w[i]] + k * v[i]);
            }
        }
    }
    return dp[nums][vol];
}
/**
 * @brief 完全 背包一维空间解法
 */
int CompleteKnapsackByOneDimesion (vector<int>& w, vector<int>& v, int vol) {
    int nums = w.size(); // 物品总数
    vector<int> dp(vol + 1);
    // 完全背包，如果利用 01 背包的思路可以将 三重循环 降低为 二重
    // 考虑已经计算得到了前 i - 1 个物品在背包容量 0 ~ vol 的最优解
    // 如果要加入第 i 个物品，显然循环起点应该在 w[i]， 因为如果 w[i] > j, 背包放不进去
    // 即，当 j = 0 ~ w[i] - 1时，加入第 i 个物品的最优解应该与前 i - 1 个物品的解保持一致， 即不放它进去
    // 当 j = w[i] ~ vol 时，背包可以放入第 i 个物品，而且在容量比较大时可以持续放入多个
    // 因此，内循环应该是正序的，因为需要与当前层进行比较
    // 比如，放进 2 个第 i 个商品时，要比较与放入 1 个第 i 个商品哪种更优
    for (int i = 1; i <= nums; ++i) for (int j = w[i]; j <= vol; ++j) {
        // 第二层正序
        dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    }
    return dp[vol];
}

