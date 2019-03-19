#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string.h>
using namespace std;
/*
 * ��������--���λ���ȷ�(MSD):
 * ȡ 0 - 9 һ������Ϊ 10 ��������ΪͰ
 * 0. �ҵ�����������array������Ԫ�أ�����λ�����������Ͱ�Ĵ���
 * 1. �Դ���������array�е��������ְ������λ��Ͱ
 * 2. �Ų�Ͱ�����ĳ��Ͱλ��Ԫ�ظ���ֻ��1������ո�Ͱ
 * ���򣬵ݹ����
 */
/**
 * @brief �������λ��
 * @return ���λ�� - 1
 */
int calMaxBit(vector<int>& a, int p, int r) {
    int maxv = a[p];
    for (int i = p; i <= r; ++i) maxv = max(maxv, a[i]);
    int maxBit = int(log10(maxv));
    return maxBit;
}
/**
 * @brief �ݹ�ʵ��MSD
 */
void radixSort_MSD_Rec(vector<int>& a, int p, int r, int mb) {
    if (p < r) {
        const int num = 10;
        int cnt[num], bucket[num][r - p + 1];
        memset(cnt, 0, sizeof(cnt));
        for (int i = p; i <= r; ++i) { //��Ͱ
            int bit = a[i] / int(pow(10, mb)) % 10;
            bucket[bit][cnt[bit]] = a[i];
            ++cnt[bit];
        }
        for (int k = 0; k < num; ++k) { //��ӡ
            cout << k << ": ";
            for (int n = 0; n < cnt[k]; ++n) cout << bucket[k][n] << " ";
            cout << endl;
        }
        int j = p;
        for (int k = 0; k < num; ++k) { //�Ų�Ͱ
            if (cnt[k] == 1) a[j++] = bucket[k][0];
            else if (cnt[k] > 1) {
                // ע���������и�Ͱ���������ֵ����һ���ģ���ô�Ͳ�Ҫ�ٵݹ飬����Ҫ�ж�
                int x = bucket[k][0];
                bool flag = true;
                for (int l = 0; l < cnt[k]; ++l) {
                    if (bucket[k][l] != x) flag = false;
                    a[j + l] = bucket[k][l];
                }
                if (!flag) radixSort_MSD_Rec(a, j, j + cnt[k] - 1, mb - 1);
                j += cnt[k];
            }
        }
    }
}
/**
 * @brief ������
 */
void radixSort_MSD(vector<int>& a, int p, int r) {
    int maxBit = calMaxBit(a, p, r);
    radixSort_MSD_Rec(a, p, r, maxBit);
}
//���Ժ���
int main() {
    const int n = 20;
    srand(int(time(0)));
    vector<int> a(n);
    for (int i = 0; i < n; ++i) a[i] = rand() % 10;
    cout << "����ǰ:";
    for (auto i : a) cout << i << " ";
    radixSort_MSD(a, 0, a.size() - 1);
    cout << endl << "�����:";
    for (auto i : a) cout << i << " ";
}
