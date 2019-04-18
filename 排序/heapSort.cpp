#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
/*
 * 堆排序实现思想
 * 二叉堆可以近似地看成是完全二叉树:
 * 除了最底层外，该树是完全充满的，而且是从左向右填充。
 *
 * 需要深刻掌握的几点:
 * (i begin with 0)
 * 1. parent(i) = (i - 1) / 2
 * 2. left(i) = 2 * i + 1
 * 3. right(i) = 2 * i + 2
 *
 * 4. 二叉堆分最大堆，最小堆; 其中最大堆用于排序，最小堆用于实现优先队列
 *
 * 实现堆排序需要 3 个函数:
 * 1. maxHeapify(维护最大堆) -> 假定结点 i 的左右儿子的二叉树均是最大堆，但 i 与其左右儿子不一定满足最大堆的性质，
 * 因此，我们需要maxHeapify函数使 i 逐级下沉。显然地maxHeapify需要递归调用
 * 2. buildMaxHeapify(创建最大堆) -> 当我们首次进行处理时，需要用原数组构建一个最大堆。
 * 其中，length(array) / 2 ... length(array) - 1 是叶子节点我们不需要处理
 * 只要对 length(array) / 2 - 1 ... 0 这些元素调用 maxHeapify 即可
 * 3. heapSort(堆排序函数) -> 第一次构建堆后，堆顶元素是最大的元素，我们可以将其与末尾的元素交换，那么一个元素已经排序完毕
 * 这时，应当减少堆的大小，继续调用maxHeapify函数，找出次大元素，将其与倒数第二位的元素交换，那么两个元素排序完毕..
 * 经过 length(array) - 1 次操作后，数组可有序

 */

int parent(int i) {
    return (i - 1) >> 1;
}
int left(int i) {
    return (i << 1) + 1;
}
int right(int i) {
    return left(i) + 1;
}
/**
 * @brief 维护最大堆
 * @param[inout] a 数组
 * @param[in] i 当前结点
 * @param[in] heapSize 当前堆大小
 * @param[in] lchd 左儿子
 * @param[in] rchd 右儿子
 *
 * 将左右儿子中较大的那个与根交换，然后递归调用
 *
 */
void maxHeapify(vector<int>& a, int i, int heapSize) {
    int lchd = left(i), rchd = right(i), largest = i;
    if (lchd < heapSize && a[lchd] > a[i]) largest = lchd;
    if (rchd < heapSize && a[rchd] > a[largest]) largest = rchd;

    if (largest != i) {
        //说明有变化
        swap(a[i], a[largest]);
        maxHeapify(a, largest, heapSize);
    }
}
int buildMaxHeap(vector<int>& a) {
    //自底向上
    int heapSize = a.size();
    //cout << endl << (heapSize >> 1) - 1 << endl;
    for (int i = (heapSize >> 1) - 1; i >= 0; --i) maxHeapify(a, i, heapSize);
    return heapSize;
}
void heapSort(vector<int>& a) {
    int heapSize = buildMaxHeap(a);
    for (int i = a.size() - 1; i > 0; --i) {
        swap(a[i], a[0]);
        --heapSize;
        maxHeapify(a, 0, heapSize);
    }
}
int main() {
    const int n = 30;
    srand(int(time(0)));

    vector<int> a(n);
    for (int i = 0; i < n; ++i) a[i] = rand() % n;
    cout << "排序前:";
    for (auto i : a) cout << i << " ";
    heapSort(a);
    cout << endl << "排序后:";
    for (auto i : a) cout << i << " ";
}
