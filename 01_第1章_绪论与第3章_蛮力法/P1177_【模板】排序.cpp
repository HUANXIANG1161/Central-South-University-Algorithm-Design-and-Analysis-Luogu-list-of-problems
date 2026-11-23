// ======================================================================
// 洛谷 P1177  【模板】排序
// 难度: 普及-    (题单顺序 9/69)
// 题目: https://www.luogu.com.cn/problem/P1177
// 记录: https://www.luogu.com.cn/record/281965333
// 结果: Accepted · 100 分 · 66 ms · 988 KB · 提交于 2026-06-15 08:44
// 语言: C/C++（洛谷语言编号 28）
// ======================================================================

// ---------------------------- 题面 ----------------------------
//
// 【题目描述】
// 将读入的 $N$ 个数从小到大排序后输出。
//
// 【输入格式】
// 第一行为一个正整数 $N$。
// 
// 第二行包含 $N$ 个空格隔开的正整数 $a_i$，为你需要进行排序的数。
// 
//
// 【输出格式】
// 将给定的 $N$ 个数从小到大输出，数之间空格隔开。
// 
//
// 【样例 #1】
// 输入:
// 5
// 4 2 4 5 1
// 输出:
// 1 2 4 4 5
//
// 【提示】
// 对于 $20\%$ 的数据，有 $1 \leq N \leq 10^3$；
// 
// 对于 $100\%$ 的数据，有 $1 \leq N \leq 10^5$，$1 \le a_i \le 10^9$。
// 
//
// ---------------------------- 代码 ----------------------------

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int a[100000];

void quick_sort(int left, int right)
{
    if(left >= right) return;
    int p = a[(left+right)/2];
    int l = left, r = right;
    while(l <= r)
    {
        while(a[l] < p) l++;
        while(a[r] > p) r--;
        if(l <= r)
        {
            int t = a[l];
            a[l] = a[r];
            a[r] = t;
            l++;
            r--;
        }
    }
    quick_sort(left, r);
    quick_sort(l, right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    quick_sort(0,n-1);
    for(int i=0;i<n;i++) cout << a[i]<<' ';
    return 0;
}
