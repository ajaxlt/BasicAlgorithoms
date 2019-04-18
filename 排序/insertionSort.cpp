#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
/*
 * 插入排序的实现:
 * 从第二个元素开始，往前找到其合适的位置
 * 挪步法
 */
void insertionSort(vector<int>& a, int p, int r) {
    int i = 1;//已排序的个数
    for(; i <= r; ++i) {
        int x = a[p + i];//当前待排序的元素值
        int j = p + i - 1;//当前已排序下标
        for (; j >= p && a[j] > x; --j) a[j + 1] = a[j];//挪步
        a[j + 1] = x;//插入
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
    insertionSort(a, 0, a.size() - 1);
    cout << endl << "排序后:";
    for(int &i : a) cout << i <<" ";
    return 0;
}