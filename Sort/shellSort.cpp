#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
/*
 * 希尔排序的实现：
 * 希尔排序全称为希尔插入排序，又名缩小增量排序，是对直接插入排序的一种改进
 * 我们将数组进行分组，设置一个增量gap, 那么 i 与 i + gap, i + 2 * gap ...一组
 * 总共为 gap 组
 * 对于每组采用采用插入排序， 每次进行一趟， gap 将缩小，直至gap = 1
 * 当 gap = 1时， 其实多数情况下只需要微调就可以
 * 最坏时间复杂度O(n ^ 2)， 优化后可以达到O(n ^ 3 / 2)
 */
void insertionGapSort(vector<int>& a, int p, int r, int gap) {
    int i = p + gap;
    // 首先要从 p + gap 元素开始
    // 因为 p + gap 之前的他们是每组的首个元素，我们认为其已经排好序
    for(; i <= r; ++i) {
        // 这层大循环看似没有考虑到“组”，但是，gap的引入其实便已隐式地进行分组操作了
        int x = a[i];//当前待排序的元素值
        int j = i - gap;//当前元素的前一个元素
        for(; j >= p && x < a[j]; j -= gap) {
            a[j + gap] = a[j];// 挪步法
        }
        a[j + gap] = x;
    }
}
void shellSort(vector<int>& a, int p, int r) {
    const int len = r - p + 1;
    int gap = len / 2;
    while(gap >= 1) {
        insertionGapSort(a, p, r, gap);
        gap /= 2;
    }
}
//测试函数
int main() {
    const int n = 20;
    srand(int(time(0)));
    vector<int> a(n);
    for(int &i : a) i = rand() % 100;
    cout << "排序前：";
    for(int &i : a) cout << i <<" ";
    shellSort(a, 0, a.size() - 1);
    cout << endl << "排序后:";
    for(int &i : a) cout << i <<" ";
    return 0;
}