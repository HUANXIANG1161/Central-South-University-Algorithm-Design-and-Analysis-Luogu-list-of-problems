// ======================================================================
// 洛谷 P1257  平面上的最接近点对
// 难度: 普及-    (题单顺序 10/69)
// 题目: https://www.luogu.com.cn/problem/P1257
// 记录: https://www.luogu.com.cn/record/281263314
// 结果: Accepted · 100 分 · 146 ms · 1072 KB · 提交于 2026-06-09 01:28
// 语言: C/C++（洛谷语言编号 28）
// ======================================================================

// ---------------------------- 题面 ----------------------------
//
// 【题目描述】
// 给定平面上 $n$ 个点，找出其中的一对点的距离，使得在这 $n$ 个点的所有点对中，该距离为所有点对中最小的。
//
// 【输入格式】
// 第一行一个整数 $n$，表示点的个数。
// 
// 接下来 $n$ 行，每行两个整数 $x,y$，表示一个点的行坐标和列坐标。
//
// 【输出格式】
// 仅一行，一个实数，表示最短距离，四舍五入保留 $4$ 位小数。
//
// 【样例 #1】
// 输入:
// 3
// 1 1
// 1 2
// 2 2
// 
// 输出:
// 1.0000
// 
//
// 【提示】
// #### 数据规模与约定
// 
// 对于 $100\%$ 的数据，保证 $2 \leq n \leq 10^4$，$0 \leq x, y \leq 10^9$。
//
// ---------------------------- 代码 ----------------------------

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#define INT_MAX 2147483647
using namespace std;

struct dot {
	int x, y;
};

dot a[10010];

int main() {
	int n;
	cin >> n;
	double ans = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].x >> a[i].y;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			double distance = sqrt(pow(a[i].x - a[j].x, 2) + pow(a[i].y - a[j].y, 2));
			if (distance < ans)ans = distance;
		}
	}
	cout <<fixed<<setprecision(4)<< ans;
	return 0;
}
