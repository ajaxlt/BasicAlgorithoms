#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
/*
 * 折半插入排序的实现:
 * 插入排序中，数组可以分成两部分，前半部分已经排序，后半部分还未排序
 * 对于当前遍历值 i，我们需要将他插入到前半部分合适的位置
 * 常规方法是逐一比较，但是由于前半部分已经有序，因此我们可以采用BS用log2n的时间找到该位置
 */
void insertionSort(vector<int>& a, int p, int r) {
    int i = 1;//已排序的个数
    for(; i <= r; ++i) {
        int x = a[p + i];//当前待排序的元素值
        int head = p, tail = p + i - 1, mid;// j是代求插入位置
        while(tail >= head) {// 二分查找
            mid = (head + tail) / 2;
            // 这里可以写等于情况也可以不写
            if(a[mid] > x) tail = mid - 1;
            else  head = mid + 1;
        }
        for(int j = p + i - 1; j > head; --j) a[j + 1] = a[j];
        a[head] = x;
    }
}
//测试函数
int main() {
    const int n = 20;
    srand(int(time(0)));
    vector<int> a(n);
    for(int &i : a) i = rand() % 100;
    cout << "排序前：";
    for(int &i : a) cout << i <<" ";
    insertionSort(a, 0, a.size() - 1);
    cout << endl << "排序后:";
    for(int &i : a) cout << i <<" ";
    return 0;
}