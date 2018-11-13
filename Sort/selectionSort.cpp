#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
/*
 * ѡ������: ͬð������for
 */
void selectionSort(vector<int>& a, int p, int r) {
    int t = r - p; // ��ѭ������
    for (int i = 0; i < t; ++i) {
        // ÿ������С��
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
    cout << "����ǰ:";
    for (auto i : a) cout << i << " ";
    selectionSort(a, 0, a.size() - 1);
    cout << endl << "�����:";
    for (auto i : a) cout << i << " ";
}
