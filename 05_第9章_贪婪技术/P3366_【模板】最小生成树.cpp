// ======================================================================
// 洛谷 P3366  【模板】最小生成树
// 难度: 普及    (题单顺序 59/69)
// 题目: https://www.luogu.com.cn/problem/P3366
// 记录: https://www.luogu.com.cn/record/282020423
// 结果: Accepted · 100 分 · 919 ms · 101092 KB · 提交于 2026-06-15 21:38
// 语言: C/C++（洛谷语言编号 28）
// ======================================================================

// ---------------------------- 题面 ----------------------------
//
// 【题目描述】
// 如题，给出一个无向图，求出最小生成树，如果该图不连通，则输出 `orz`。
//
// 【输入格式】
// 第一行包含两个整数 $N,M$，表示该图共有 $N$ 个结点和 $M$ 条无向边。
// 
// 接下来 $M$ 行每行包含三个整数 $X_i,Y_i,Z_i$，表示有一条长度为 $Z_i$ 的无向边连接结点 $X_i,Y_i$。
//
// 【输出格式】
// 如果该图连通，则输出一个整数表示最小生成树的各边的长度之和。如果该图不连通则输出 `orz`。
//
// 【样例 #1】
// 输入:
// 4 5
// 1 2 2
// 1 3 2
// 1 4 3
// 2 3 4
// 3 4 3
// 输出:
// 7
//
// 【提示】
// 数据规模：
// 
// 对于 $20\%$ 的数据，$N\le 5$，$M\le 20$。
// 
// 对于 $40\%$ 的数据，$N\le 50$，$M\le 2500$。
// 
// 对于 $70\%$ 的数据，$N\le 500$，$M\le 10^4$。
// 
// 对于 $100\%$ 的数据：$1\le N\le 5000$，$1\le M\le 2\times 10^5$，$1\le Z_i \le 10^4$，$1\le X_i,Y_i\le N$。
// 
// 
// 样例解释：
// 
//  ![](https://cdn.luogu.com.cn/upload/pic/2259.png)
// 
// 所以最小生成树的总边权为 $2+2+3=7$。
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

int g[5100][5100];
int n, m;
bool visit[5100];
int distant[5100];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	

	cin >> n >> m;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			g[i][j] = INF;
		}
		distant[i] = INF;
	}
	for (int i = 0; i < m; i++)
	{
		int x1, x2,v;
		cin >> x1 >> x2 >> v;
		g[x1][x2] = min(g[x1][x2], v);
		g[x2][x1] = min(g[x2][x1], v);
	}

	distant[1] = 0;
	int ans = 0;

	for (int i = 1; i <= n; i++)
	{
		int v = -1;

		for (int j = 1; j <= n; j++)
		{
			if (!visit[j] && (v == -1 || distant[j] < distant[v]))
			{
				v = j;
			}
		}
		if (distant[v] == INF)
		{
			cout << "orz";
			return 0;
		}

		visit[v] = 1;
		ans += distant[v];

		for (int k = 1; k <= n; k++)
		{
			if (visit[k] == 0)
			{
				distant[k] = min(distant[k], g[k][v]);
			}
		}
	}

	cout << ans;
	return 0;
}
