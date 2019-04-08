#include <iostream>
#include <vector>
#include <string>
/*
 * KMP算法:
 * next[i] 表示模式串的 0 ~ i 中 前缀后缀相同的最大长度
 *
 * 我们用 i 指针指向主串, j 指针指向模式串。如果我们发现当前位置不匹配，使用暴力法会同时回溯 i, j 两指针
 * 但是，更加高效的做法应该是保持 i 指针不动, 移动 j 指针
 * 因为，我们匹配的时候，虽然有时遭遇失败，但不代表这次匹配全是无用的
 * 起码，我们验证了模式串 j 之前的子串能够与主串匹配。
 * 我们移动 j， 使得与后缀相同的前缀移动到后缀的位置，则这一部分仍然是匹配的，可以继续往后尝试，直到 j 移动到左端点
 * 用 next[j] 去表示每次匹配失败时 j 应该移到的位置
 */
using namespace std;
void getNext(string p, vector<int>& next) {
    next[0] = -1;
    int i = 0, j = -1;
    while(i < p.size()) {
        if (j == -1 || p[i] == p[j]) next[++i] = ++j;
        else j = next[j];
    }
}
int KMP(string t, string p) {
    int i = 0, j = 0;
    vector<int> next(p.size());
    getNext(p, next);
    int len1 = t.size(), len2 = p.size();
    while(i < len1 && j < len2) {
        if (j == -1 || t[i] == p[j]) ++i, ++j;
        else j = next[j];
    }
    if (j == len2) return i - j;
    else return -1;
}
int main() {
    string t = "abababca", p = "bca";
    cout << KMP(t, p) << endl;
    return 0;
}