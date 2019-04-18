#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
/*
 * 快速排序的实现:
 * 两个函数 partition 和 quickSort, 前者用于调度，后者用于二分递归
 * partition:
 * 1.选择主元(一般是数组末尾元素)
 * 2.定义2个指针: i 记录不大于主元的个数; j 当前遍历值
 *   以主元为基准, 小于主元的元素位于主元的左侧，反之位于主元的右侧
 *   i 不但记录了不大于主元的个数，而当最后遍历完整个子数组后，i 的下一个就是主元应该处在的位置
 */
int partition(vector<int>& arr, int p, int r) {
    int x = arr[r]; //选择主元
    int i = p - 1; //i代表不大于主元的数
    for (int j = p; j < r; ++j) {
        if (arr[j] <= arr[r]) swap(arr[j], arr[++i]);
        //若当前元素小于主元, 作交换
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}
void quickSort(vector<int>& arr, int p, int r) {
    if (p < r) {
        int q = partition(arr, p, r);
        quickSort(arr, p, q - 1);
        quickSort(arr, q + 1, r);
    }
}

//测试
int main() {
    const int n = 20;
    srand(int(time(0)));
    vector<int> a(n);
    for (int i = 0; i < n; ++i) a[i] = rand() % n;
    cout << "排序前:";
    for (auto i : a)
        cout << i << " ";
    cout << endl;
    quickSort(a, 0, a.size() - 1);
    cout << "排序后:";
    for (auto i : a)
        cout << i << " ";
    cout << endl;
}


