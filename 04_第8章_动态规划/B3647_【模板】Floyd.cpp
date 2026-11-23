// ======================================================================
// 洛谷 B3647  【模板】Floyd
// 难度: 普及    (题单顺序 49/69)
// 题目: https://www.luogu.com.cn/problem/B3647
// 记录: https://www.luogu.com.cn/record/281795774
// 结果: Accepted · 100 分 · 55 ms · 1064 KB · 提交于 2026-06-14 03:23
// 语言: C/C++（洛谷语言编号 28）
// ======================================================================

// ---------------------------- 题面 ----------------------------
//
// 【题目描述】
// 给出一张由 $n$ 个点 $m$ 条边组成的无向连通图。
// 
// 求出所有点对 $(i,j)$ 之间的最短路径。
//
// 【输入格式】
// 第一行为两个整数 $n,m$，分别代表点的个数和边的条数。
// 
// 接下来 $m$ 行，每行三个整数 $u,v,w$，代表 $u,v$ 之间存在一条边权为 $w$ 的边。
//
// 【输出格式】
// 输出 $n$ 行每行 $n$ 个整数。
// 
// 第 $i$ 行的第 $j$ 个整数代表从 $i$ 到 $j$ 的最短路径。
//
// 【样例 #1】
// 输入:
// 4 4
// 1 2 1
// 2 3 1
// 3 4 1
// 4 1 1
// 输出:
// 0 1 2 1
// 1 0 1 2
// 2 1 0 1
// 1 2 1 0
//
// 【提示】
// 对于 $100\%$ 的数据，$n \le 100$，$m \le 4500$，任意一条边的权值 $w$ 是正整数且 $1 \leqslant w \leqslant 1000$。
// 
// **数据中可能存在重边。**
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

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)//初始化邻接矩阵
	{
		for (int j = 1; j <= n; j++)
		{
			neibor[i][j] = neibor[j][i] = INF;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		neibor[i][i] = 0;
	}

	for (int i = 0; i < m; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		neibor[x][y] = min(neibor[x][y], w);
		neibor[y][x] = min(neibor[y][x], w); // 无向图双向赋值
	}

	for (int k = 1; k <= n; k++)//以k为中间点
	{
		for (int i = 1; i <= n; i++)
		{
			if (i == k)continue;//对应k的行和列不用更新
			for (int j = 1; j <= n; j++)
			{
			    if (j == k)continue;//对应k的行和列不用更新
				if (i == j)continue;//自己到自己的点不用更新

				neibor[i][j] = min(neibor[i][j], neibor[i][k] + neibor[k][j]);
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
