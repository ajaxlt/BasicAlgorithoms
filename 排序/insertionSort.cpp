#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
/*
 * ���������ʵ��:
 * �ӵڶ���Ԫ�ؿ�ʼ����ǰ�ҵ�����ʵ�λ��
 * Ų����
 */
void insertionSort(vector<int>& a, int p, int r) {
    int i = 1;//������ĸ���
    for(; i <= r; ++i) {
        int x = a[p + i];//��ǰ�������Ԫ��ֵ
        int j = p + i - 1;//��ǰ�������±�
        for (; j >= p && a[j] > x; --j) a[j + 1] = a[j];//Ų��
        a[j + 1] = x;//����
    }
}
//���Ժ���
int main() {
    const int n = 20;
    srand(int(time(0)));
    vector<int> a(n);
    for(int &i : a) i = rand() % 100;
    cout << "����ǰ��";
    for(int &i : a) cout << i <<" ";
    insertionSort(a, 0, a.size() - 1);
    cout << endl << "�����:";
    for(int &i : a) cout << i <<" ";
    return 0;
}