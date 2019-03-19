#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string.h>
using namespace std;
/*
 * 基数排序--最高位优先法(MSD):
 * 取 0 - 9 一个长度为 10 的数组作为桶
 * 0. 找到待排序数列array中最大的元素，它的位数决定了入出桶的次数
 * 1. 对待排序数列array中的所有数字按照最高位入桶
 * 2. 排查桶，如果某个桶位的元素个数只有1，则回收该桶
 * 否则，递归操作
 */
/**
 * @brief 计算最大位数
 * @return 最大位数 - 1
 */
int calMaxBit(vector<int>& a, int p, int r) {
    int maxv = a[p];
    for (int i = p; i <= r; ++i) maxv = max(maxv, a[i]);
    int maxBit = int(log10(maxv));
    return maxBit;
}
/**
 * @brief 递归实现MSD
 */
void radixSort_MSD_Rec(vector<int>& a, int p, int r, int mb) {
    if (p < r) {
        const int num = 10;
        int cnt[num], bucket[num][r - p + 1];
        memset(cnt, 0, sizeof(cnt));
        for (int i = p; i <= r; ++i) { //入桶
            int bit = a[i] / int(pow(10, mb)) % 10;
            bucket[bit][cnt[bit]] = a[i];
            ++cnt[bit];
        }
        for (int k = 0; k < num; ++k) { //打印
            cout << k << ": ";
            for (int n = 0; n < cnt[k]; ++n) cout << bucket[k][n] << " ";
            cout << endl;
        }
        int j = p;
        for (int k = 0; k < num; ++k) { //排查桶
            if (cnt[k] == 1) a[j++] = bucket[k][0];
            else if (cnt[k] > 1) {
                // 注意这里，如果有个桶，他里面的值都是一样的，那么就不要再递归，所以要判断
                int x = bucket[k][0];
                bool flag = true;
                for (int l = 0; l < cnt[k]; ++l) {
                    if (bucket[k][l] != x) flag = false;
                    a[j + l] = bucket[k][l];
                }
                if (!flag) radixSort_MSD_Rec(a, j, j + cnt[k] - 1, mb - 1);
                j += cnt[k];
            }
        }
    }
}
/**
 * @brief 主调用
 */
void radixSort_MSD(vector<int>& a, int p, int r) {
    int maxBit = calMaxBit(a, p, r);
    radixSort_MSD_Rec(a, p, r, maxBit);
}
//测试函数
int main() {
    const int n = 20;
    srand(int(time(0)));
    vector<int> a(n);
    for (int i = 0; i < n; ++i) a[i] = rand() % 10;
    cout << "排序前:";
    for (auto i : a) cout << i << " ";
    radixSort_MSD(a, 0, a.size() - 1);
    cout << endl << "排序后:";
    for (auto i : a) cout << i << " ";
}
