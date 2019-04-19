#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string.h>
using namespace std;
/*
 * ��������--���λ���ȷ�(LSD):
 * ȡ 0 - 9 һ������Ϊ 10 ��������ΪͰ
 * 0. �ҵ�����������array������Ԫ�أ�����λ�����������Ͱ�Ĵ���
 * 1. �Դ���������array�е��������ְ������λ(��λ)��Ͱ
 * 2. �����Ƚ��ȳ���˳���Ͱ
 * 3. λ����һ����������
 */
/**
 * @param[in,out] a ����������
 * @param[in] p ��ʼ�±�
 * @param[in] r ��ֹ�±�
 * @param[in] maxn �����е����ֵ
 * @param[in] maxbit �����е����λ
 * @param[in] cnt ͳ��ÿ��Ͱ���Ԫ�ظ���
 * @param[in] bucket Ͱ�����Ԫ��
 */
void radixSort_LSD(vector<int>& a, int p, int r) {
    int maxn = INT32_MIN;
    for (auto i : a) maxn = max(maxn, i);
    const int maxbit = (int) log10(maxn) + 1;
    const int digits = 10;
    vector<vector<int> > bucket(digits, {});
    for (int i = 0; i < maxbit; ++i) {
        for (int j = p; j <= r; ++j) {
            int bit = a[j] / (int) pow(10, i) % 10;
            bucket[bit].push_back(a[j]);
        }
        int j = p;
        for (auto &b : bucket) {
            for (auto item : b) {
                a[j++] = item;
            }
            b.clear();
        }
    }
}
// ���Ժ���
int main() {
    const int n = 20;
    srand(int(time(0)));
    vector<int> a(n);
    for (int i = 0; i < n; ++i) a[i] = rand() % 99;
    cout << "����ǰ:";
    for (auto i : a) cout << i << " ";
    radixSort_LSD(a, 0, a.size() - 1);
    cout << endl << "�����:";
    for (auto i : a) cout << i << " ";
}