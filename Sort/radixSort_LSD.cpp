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
 *
 * @param[in,out] a ����������
 * @param[in] p ��ʼ�±�
 * @param[in] r ��ֹ�±�
 * @param[in] maxv �����е����ֵ
 * @param[in] maxBit �����е����λ
 * @param[in] cnt ͳ��ÿ��Ͱ���Ԫ�ظ���
 * @param[in] bucket Ͱ�����Ԫ��
 */
void radixSort_LSD(vector<int>& a, int p, int r) {
    int maxv = a[p];
    for (int i = p; i <= r; ++i) maxv = max(maxv, a[i]);
    int maxBit = int(log10(maxv)) + 1;
    const int num = 10;
    int cnt[num], bucket[num][r - p + 1];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < maxBit; ++i) { //λ������
        for (int j = p; j <= r; ++j) {// ��Ͱ
            int bit = a[j] / int(pow(10, i)) % 10;
            bucket[bit][cnt[bit]] = a[j];
            ++cnt[bit];
        }

        int j = p;
        for (int k = 0; k < num; ++k) { // ��Ͱ
            if (cnt[k]) {
                for (int l = 0; l < cnt[k]; ++l) a[j++] = bucket[k][l];
                cnt[k] = 0; // ��ԭ
            }
        }
    }
}
//���Ժ���
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
