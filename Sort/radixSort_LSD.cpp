#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string.h>
using namespace std;
/*
 * 基数排序--最低位优先法(LSD):
 * 取 0 - 9 一个长度为 10 的数组作为桶
 * 0. 找到待排序数列array中最大的元素，它的位数决定了入出桶的次数
 * 1. 对待排序数列array中的所有数字按照最低位(个位)入桶
 * 2. 按照先进先出的顺序出桶
 * 3. 位数晋一，迭代操作
 */
/**
 *
 * @param[in,out] a 待排序数组
 * @param[in] p 起始下标
 * @param[in] r 终止下标
 * @param[in] maxv 数组中的最大值
 * @param[in] maxBit 数组中的最大位
 * @param[in] cnt 统计每次桶里的元素个数
 * @param[in] bucket 桶，存放元素
 */
void radixSort_LSD(vector<int>& a, int p, int r) {
    int maxv = a[p];
    for (int i = p; i <= r; ++i) maxv = max(maxv, a[i]);
    int maxBit = int(log10(maxv)) + 1;
    const int num = 10;
    int cnt[num], bucket[num][r - p + 1];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < maxBit; ++i) { //位数迭代
        for (int j = p; j <= r; ++j) {// 入桶
            int bit = a[j] / int(pow(10, i)) % 10;
            bucket[bit][cnt[bit]] = a[j];
            ++cnt[bit];
        }

        int j = 0;
        for (int k = 0; k < num; ++k) { // 出桶
            if (cnt[k]) {
                for (int l = 0; l < cnt[k]; ++l) a[j++] = bucket[k][l];
                cnt[k] = 0; // 还原
            }
        }
    }
}
//测试函数
int main() {
    const int n = 20;
    srand(int(time(0)));
    vector<int> a(n);
    for (int i = 0; i < n; ++i) a[i] = rand() % 99;
    cout << "排序前:";
    for (auto i : a) cout << i << " ";
    radixSort_LSD(a, 0, a.size() - 1);
    cout << endl << "排序后:";
    for (auto i : a) cout << i << " ";
}
