#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
/*
 * 归并排序:
 * 归并排序是分治法的主要代表，其运作原理分为“分”、“治”两个部分
 * 即递归分解与合并两个部分
 */
/**
 * @brief 将两个有序数组合成一个新的有序数组
 * @param[in] p 左端点
 * @param[in] q 分界点
 * @param[in] r 右端点
 * @param[in] left 左有序数组 p..q
 * @param[in] right右有序数组 q + 1..r
 * @return null
 */
void merge(vector<int>& a, int p, int q, int r) {
    const int llen = q - p + 1;
    const int rlen = r - q;
    vector<int> left(llen + 1);
    vector<int> right(rlen + 1);
    for(int i = 0; i < llen; ++i) left[i] = a[p + i];
    left[llen] = INT32_MAX; //sentinel
    for(int i = 0; i < rlen; ++i) right[i] = a[q + 1 + i];
    right[rlen] = INT32_MAX; //sentinel
    int i = 0, j = 0;
    for(int k = p; k <= r; ++k) {
        if (left[i] < right[j]) a[k] = left[i++];
        else a[k] = right[j++];
    }
}
void mergeSort(vector<int>& a, int p, int r) {
//    if (p == r)
//    此时只有一个元素，无需处理
    if (p < r) {
        int q = (p + r) / 2;
        mergeSort(a, p, q);
        mergeSort(a, q + 1, r);
        merge(a, p, q, r);
    }
}
//测试函数
int main() {
    const int n = 30;
    srand(int(time(0)));
    vector<int> a(n);
    for (int i = 0; i < n; ++i) a[i] = rand() % n;
    cout << "排序前:";
    for (auto i : a) cout << i << " ";
    mergeSort(a, 0, a.size() - 1);
    cout << endl << "排序后:";
    for (auto i : a) cout << i << " ";
}
