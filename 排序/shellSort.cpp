#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
/*
 * ϣ�������ʵ�֣�
 * ϣ������ȫ��Ϊϣ����������������С���������Ƕ�ֱ�Ӳ��������һ�ָĽ�
 * ���ǽ�������з��飬����һ������gap, ��ô i �� i + gap, i + 2 * gap ...һ��
 * �ܹ�Ϊ gap ��
 * ����ÿ����ò��ò������� ÿ�ν���һ�ˣ� gap ����С��ֱ��gap = 1
 * �� gap = 1ʱ�� ��ʵ���������ֻ��Ҫ΢���Ϳ���
 * �ʱ�临�Ӷ�O(n ^ 2)�� �Ż�����ԴﵽO(n ^ 3 / 2)
 */
void insertionGapSort(vector<int>& a, int p, int r, int gap) {
    int i = p + gap;
    // ����Ҫ�� p + gap Ԫ�ؿ�ʼ
    // ��Ϊ p + gap ֮ǰ��������ÿ����׸�Ԫ�أ�������Ϊ���Ѿ��ź���
    for(; i <= r; ++i) {
        // ����ѭ������û�п��ǵ����顱�����ǣ�gap��������ʵ������ʽ�ؽ��з��������
        int x = a[i];//��ǰ�������Ԫ��ֵ
        int j = i - gap;//��ǰԪ�ص�ǰһ��Ԫ��
        for(; j >= p && x < a[j]; j -= gap) {
            a[j + gap] = a[j];// Ų����
        }
        a[j + gap] = x;
    }
}
void shellSort(vector<int>& a, int p, int r) {
    const int len = r - p + 1;
    int gap = len / 2;
    while(gap >= 1) {
        insertionGapSort(a, p, r, gap);
        gap /= 2;
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
    shellSort(a, 0, a.size() - 1);
    cout << endl << "�����:";
    for(int &i : a) cout << i <<" ";
    return 0;
}