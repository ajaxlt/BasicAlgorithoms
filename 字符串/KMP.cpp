#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * @param p 模式串
 * @return 模式串的部分匹配表(往后挪一位)
 * p[i] 表示
 * 以 i 结尾的最长相同前后缀中, 前缀的终止字符下标, -1 表示没有相同的前后缀
 * p[i] + 1 表示
 * 以 i 结尾的最长相同前后缀的长度
 *
 * 动态规划求解
 */
vector<int> getNext(const string& p) {
    int len = p.size();
    vector<int> next(len, -1);
    for (int i = 1; i < len; ++i) {
        int j = next[i - 1];
        // 令临时量 j 初始化为 next[i - 1],
        // 那么 j 的另一层含义为 以 i - 1 结尾的前缀的终止字符下标
        // 然后可以用动态规划的思路求解
        while(p[j + 1] != p[i] && j >= 0) {
            // 如果 i - 1 结尾的前缀的后一个p[j + 1]与扩充的这一位 p[i] 不等
            // 则要向前回溯变量 j, 直到可以相等为止，这个时候， j 是越来越小的
            j = next[j];
        }
        if (p[j + 1] == p[i]) next[i] = j + 1;
        //else next[i] = -1;
    }
    return next;
}

/**
 * @param s 主串串
 * @param p 模式串
 * return 第一次匹配时, 主串的起始匹配位置，如果不匹配，则返回 -1
 *
 */
int KMP (const string& s, const string& p) {
    int len1 = s.size(), len2 = p.size();
    vector<int> next = getNext(p);
    int i = 0, j = 0;
    while(i < len1 && j < len2) {
        if (s[i] == p[j]) {
            ++i;
            ++j;
        }
        else if (j == 0) ++i;
        // 当 j = 0 时，如果再回溯 j = -1
        // 所以，j = 0 其实已经表示本次以 i 开头的匹配宣告失败, 从下一位 i + 1 继续开始

        else j = next[j - 1] + 1;
        // 当 j != 0 时，说明回退 j 还有可能匹配上
        // 即 让模式串 向后移动 next[j - 1] + 1 位
    }
    if (j == len2) return i - j;
    else return -1;
}