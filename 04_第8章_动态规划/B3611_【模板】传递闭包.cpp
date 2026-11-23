// ======================================================================
// 洛谷 B3611  【模板】传递闭包
// 难度: 普及    (题单顺序 50/69)
// 题目: https://www.luogu.com.cn/problem/B3611
// 记录: https://www.luogu.com.cn/record/281795809
// 结果: Accepted · 100 分 · 50 ms · 864 KB · 提交于 2026-06-14 03:42
// 语言: C/C++（洛谷语言编号 28）
// ======================================================================

// ---------------------------- 题面 ----------------------------
//
// 【题目描述】
// 给定一张点数为 $n$ 的有向图的邻接矩阵，图中不包含自环，求该有向图的传递闭包。
// 
// 一张图的邻接矩阵定义为一个 $n\times n$ 的矩阵 $A=(a_{ij})_{n\times n}$，其中
// 
// $$ a_{ij}=\left\{
// \begin{aligned}
// 1,i\ 到\ j\ 存在直接连边\\
// 0,i\ 到\ j\ 没有直接连边 \\
// \end{aligned}
// \right.
// $$
// 
// 一张图的传递闭包定义为一个 $n\times n$ 的矩阵 $B=(b_{ij})_{n\times n}$，其中
// 
// $$ b_{ij}=\left\{
// \begin{aligned}
// 1,i\ 可以直接或间接到达\ j\\
// 0,i\ 无法直接或间接到达\ j\\
// \end{aligned}
// \right.
// $$
//
// 【输入格式】
// 输入数据共 $n+1$ 行。
// 
// 第一行一个正整数 $n$。
// 
// 第 $2$ 到 $n+1$ 行每行 $n$ 个整数，第 $i+1$ 行第 $j$ 列的整数为 $a_{ij}$。
//
// 【输出格式】
// 输出数据共 $n$ 行。
// 
// 第 $1$ 到 $n$ 行每行 $n$ 个整数，第 $i$ 行第 $j$ 列的整数为 $b_{ij}$。
//
// 【样例 #1】
// 输入:
// 4
// 0 0 0 1
// 1 0 0 0
// 0 0 0 1
// 0 1 0 0
// 输出:
// 1 1 0 1
// 1 1 0 1
// 1 1 0 1
// 1 1 0 1
//
// 【提示】
// 对于 $100\%$ 的数据，$1\le n\le 100$，保证 $a_{ij}\in\{0,1\}$ 且 $a_{ii}=0$。
//
// ---------------------------- 代码 ----------------------------

#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include <cmath>
#include<cstring>
#define ll long long
#define INT_MAX 2147483640
#define INF 0x3f3f3f3f

using namespace std;

int neibor[110][110];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n ;
	for (int i = 1; i <= n; i++)//输入
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> neibor[i][j];
		}
	}


	for (int k = 1; k <= n; k++)//以k为中间点
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				neibor[i][j] |= neibor[i][k] & neibor[k][j];
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << neibor[i][j] << ' ';
		}
		cout << endl;
	}

	return 0;
}
