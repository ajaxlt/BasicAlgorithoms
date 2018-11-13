#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
/*
 * 选择排序: 同冒泡两个for
 */
void selectionSort(vector<int>& a, int p, int r) {
    int t = r - p; // 大循环次数
    for (int i = 0; i < t; ++i) {
        // 每次找最小的
        int key = a[i], idx = i;
        for (int j = i + 1; j <= r; ++j) {
            if (key > a[j]) {
                key = a[j];
                idx = j;
            }
        }
        swap(a[i], a[idx]);
    }
}
int main() {
    const int n = 30;
    srand(int(time(0)));

    vector<int> a(n);
    for (int i = 0; i < n; ++i) a[i] = rand() % n;
    cout << "排序前:";
    for (auto i : a) cout << i << " ";
    selectionSort(a, 0, a.size() - 1);
    cout << endl << "排序后:";
    for (auto i : a) cout << i << " ";
}
