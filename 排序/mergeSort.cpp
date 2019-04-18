#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
/*
 * �鲢����:
 * �鲢�����Ƿ��η�����Ҫ����������ԭ���Ϊ���֡������Ρ���������
 * ���ݹ�ֽ���ϲ���������
 */
/**
 * @brief ��������������ϳ�һ���µ���������
 * @param[in] p ��˵�
 * @param[in] q �ֽ��
 * @param[in] r �Ҷ˵�
 * @param[in] left ���������� p..q
 * @param[in] right���������� q + 1..r
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
//    ��ʱֻ��һ��Ԫ�أ����账��
    if (p < r) {
        int q = (p + r) / 2;
        mergeSort(a, p, q);
        mergeSort(a, q + 1, r);
        merge(a, p, q, r);
    }
}
//���Ժ���
int main() {
    const int n = 30;
    srand(int(time(0)));
    vector<int> a(n);
    for (int i = 0; i < n; ++i) a[i] = rand() % n;
    cout << "����ǰ:";
    for (auto i : a) cout << i << " ";
    mergeSort(a, 0, a.size() - 1);
    cout << endl << "�����:";
    for (auto i : a) cout << i << " ";
}
