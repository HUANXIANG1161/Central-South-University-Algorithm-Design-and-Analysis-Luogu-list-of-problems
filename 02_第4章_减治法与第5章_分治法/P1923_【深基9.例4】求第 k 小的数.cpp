// ======================================================================
// 洛谷 P1923  【深基9.例4】求第 k 小的数
// 难度: 普及-    (题单顺序 17/69)
// 题目: https://www.luogu.com.cn/problem/P1923
// 记录: https://www.luogu.com.cn/record/281339285
// 结果: Accepted · 100 分 · 1588 ms · 39512 KB · 提交于 2026-06-10 04:17
// 语言: C/C++（洛谷语言编号 28）
// ======================================================================

// ---------------------------- 题面 ----------------------------
//
// 【题目描述】
// 输入 $n$ 个数字 $a_i$，输出这些数字中第 $k$ 小的数。最小的数是第 $0$ 小。
// 
// 请尽量不要使用 `nth_element` 来写本题，因为本题的重点在于练习分治算法。
//
// 【输入格式】
// 第一行有两个整数，分别表示 $n$ 和 $k$。
// 
// 第二行有 $n$ 个整数，第 $i$ 个数表示 $a_i$。
//
// 【输出格式】
// 一个整数，表示第 $k$ 小的数。
//
// 【样例 #1】
// 输入:
// 5 1
// 4 3 2 1 5
// 
// 输出:
// 2
// 
//
// 【提示】
// 对于 $100\%$ 的数据，$1\le a_i<{10}^9$，$1 \le n < 5\times 10^6$，$0 \le k < n$，且 $n$ 为奇数。
//
// ---------------------------- 代码 ----------------------------

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int n, k;
int a[5000010],b[5000010];

void merge_sort(int left,int right)
{
    int mid = (left + right) / 2;
    int lh = left, rh = mid + 1, count = left;
    while (lh <= mid && rh <= right)
    {
        if (a[lh] <= a[rh])
        {
            b[count] = a[lh];
            count++;
            lh++;
        }
        else
        {
            b[count] = a[rh];
            count++;
            rh++;
        }
    }
    while (lh < mid + 1)
    {
        b[count] = a[lh];
        count++;
        lh++;
    }
    while (rh < right+1)
    {
        b[count] = a[rh];
        count++;
        rh++;
    }
    for (int i = left, j = left; i <= right; i++, j++)
    {
        a[j] = b[i];
    }
    return;
}

void m_sort(int left,int right)
{
    if (left >= right) return;
    int mid = (left + right) / 2;
    m_sort(left, mid);
    m_sort(mid + 1, right);
    merge_sort(left, right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for (int i =1; i <= n; i++)
    {
        cin>>a[i];
    }
    m_sort(1,n);
    cout << a[k+1];
    return 0;
}
