#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
/*
 * 冒泡排序: 两个for
 */
void bubbleSort(vector<int>& a, int p, int r) {
    int t = r - p; // 大循环次数
    for (int i = 0; i < t; ++i) {
        for (int j = p; j < r; ++j) {
            if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
        }
    }
}
int main() {
    const int n = 30;
    srand(int(time(0)));

    vector<int> a(n);
    for (int i = 0; i < n; ++i) a[i] = rand() % n;
    cout << "排序前:";
    for (auto i : a) cout << i << " ";
    bubbleSort(a, 0, a.size() - 1);
    cout << endl << "排序后:";
    for (auto i : a) cout << i << " ";
}
