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
void insertionSort(vector<int>& arr, int p, int r){
    for (int i = p + 1; i <= r; ++i) {
        int key = arr[i], j = i - 1;
        // key 表示当前目标
        // j 表示当前可能需要为目标挪步的元素
        // 如果说元素 j 比 key 要大，那么元素 j 应该往后挪一位，以便为 key 腾出位置
        for (; j >= 0 && arr[j] > key; --j) arr[j + 1] = arr[j];
        // j 全部遍历完， 则 j + 1 就是 k 的位置了
        arr[j + 1] = key;
    }
}

//测试
int main() {
    const int n = 20;
    srand(int(time(0)));
    vector<int> a(n);
    for (int i = 0; i < n; ++i) a[i] = rand() % n;
    cout << "排序前:";
    for (auto i : a)
        cout << i << " ";
    cout << endl;
    insertionSort(a, 0, n - 1);
    cout << "排序后:";
    for (auto i : a)
        cout << i << " ";
    cout << endl;
}


