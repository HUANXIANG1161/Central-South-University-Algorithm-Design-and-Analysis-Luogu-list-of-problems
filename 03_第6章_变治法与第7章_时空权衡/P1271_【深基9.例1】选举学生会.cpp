// ======================================================================
// 洛谷 P1271  【深基9.例1】选举学生会
// 难度: 普及-    (题单顺序 29/69)
// 题目: https://www.luogu.com.cn/problem/P1271
// 记录: https://www.luogu.com.cn/record/281509153
// 结果: Accepted · 100 分 · 605 ms · 4696 KB · 提交于 2026-06-12 02:34
// 语言: C/C++（洛谷语言编号 28）
// ======================================================================

// ---------------------------- 题面 ----------------------------
//
// 【题目描述】
// 学校正在选举学生会成员，有 $n$（$1 \le n\le 999$）名候选人，每名候选人编号分别从 $1$ 到 $n$，现在收集到了 $m$（$1 \le m \le 2000000$）张选票，每张选票都写了一个候选人编号。现在想把这些堆积如山的选票按照投票数字从小到大排序。设第 $i$（$1 \le i \le m$）张选票上的数字为 $a_i$，则保证有 $1 \le a_i \le n$。
//
// 【输入格式】
// 输入 $n$ 和 $m$ 以及 $m$ 个选票上的数字。
//
// 【输出格式】
// 求出排序后的选票编号。
//
// 【样例 #1】
// 输入:
// 5 10
// 2 5 2 2 5 2 2 2 1 2
// 输出:
// 1 2 2 2 2 2 2 2 5 5
//
// ---------------------------- 代码 ----------------------------

#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include <cmath>
#include<cstring>

using namespace std;

int a[2000010];

void quick_sort(int left, int right)
{
	if (left >= right)return;
	int mid = rand() % (right - left + 1) + left;
	int t = a[mid];
	a[mid] = a[left];
	int lh = left, rh = right;
	while (lh < rh)
	{
		while (lh < rh && a[rh] >= t)
		{
			rh--;
		}
		a[lh] = a[rh];
		while (lh < rh && a[lh] <= t)
		{
			lh++;
		}
		a[rh] = a[lh];
	}
	a[lh] = t;
	quick_sort(left, lh);
	quick_sort(lh + 1, right);
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	srand(time(0));
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a[i];
	}
	quick_sort(0, m - 1);
	for (int i = 0; i < m; i++)
	{
		cout << a[i]<<' ';
	}
	return 0;
}
