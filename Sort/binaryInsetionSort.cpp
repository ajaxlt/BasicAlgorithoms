#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
/*
 * �۰���������ʵ��:
 * ���������У�������Էֳ������֣�ǰ�벿���Ѿ����򣬺�벿�ֻ�δ����
 * ���ڵ�ǰ����ֵ i��������Ҫ�������뵽ǰ�벿�ֺ��ʵ�λ��
 * ���淽������һ�Ƚϣ���������ǰ�벿���Ѿ�����������ǿ��Բ���BS��log2n��ʱ���ҵ���λ��
 */
void insertionSort(vector<int>& a, int p, int r) {
    int i = 1;//������ĸ���
    for(; i <= r; ++i) {
        int x = a[p + i];//��ǰ�������Ԫ��ֵ
        int head = p, tail = p + i - 1, mid;// j�Ǵ������λ��
        while(tail >= head) {// ���ֲ���
            mid = (head + tail) / 2;
            // �������д�������Ҳ���Բ�д
            if(a[mid] > x) tail = mid - 1;
            else  head = mid + 1;
        }
        for(int j = p + i - 1; j > head; --j) a[j + 1] = a[j];
        a[head] = x;
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