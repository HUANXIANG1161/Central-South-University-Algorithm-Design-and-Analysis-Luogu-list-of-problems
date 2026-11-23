// ======================================================================
// 洛谷 P1546  [USACO3.1] 最短网络 Agri-Net
// 难度: 普及    (题单顺序 60/69)
// 题目: https://www.luogu.com.cn/problem/P1546
// 记录: https://www.luogu.com.cn/record/282030923
// 结果: Accepted · 100 分 · 43 ms · 1064 KB · 提交于 2026-06-16 02:57
// 语言: C/C++（洛谷语言编号 28）
// ======================================================================

// ---------------------------- 题面 ----------------------------
//
// 【题目背景】
// Farmer John 被选为他们镇的镇长！他其中一个竞选承诺就是在镇上建立起互联网，并连接到所有的农场。当然，他需要你的帮助。
// 
//
// 【题目描述】
// FJ 已经给他的农场安排了一条高速的网络线路，他想把这条线路共享给其他农场。为了用最小的消费，他想铺设最短的光纤去连接所有的农场。
// 
// 你将得到一份各农场之间连接费用的列表，你必须找出能连接所有农场并所用光纤最短的方案。每两个农场间的距离不会超过 $10^5$。
//
// 【输入格式】
// 第一行农场的个数 $N$（$3 \leq N \leq 100$）。
// 
// 接下来是一个 $N \times N$ 的矩阵，表示每个农场之间的距离。理论上，他们是 $N$ 行，每行由 $N$ 个用空格分隔的数组成，实际上，由于每行 $80$ 个字符的限制，因此，某些行会紧接着另一些行。当然，对角线将会是 $0$，因为不会有线路从第 $i$ 个农场到它本身。
//
// 【输出格式】
// 只有一个输出，其中包含连接到每个农场的光纤的最小长度。
// 
//
// 【样例 #1】
// 输入:
// 4
// 0 4 9 21
// 4 0 8 17
// 9 8 0 16
// 21 17 16 0
// 输出:
// 28
//
// 【提示】
// 题目翻译来自NOCOW。
// 
// USACO Training Section 3.1
// 
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

int g[110][110];
int n;
bool visit[110];
int distant[110];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> g[i][j];
		}
	}
	for (int i = 0; i <= n; i++)
	{
		distant[i] = INF;
	}

	distant[1] = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int v = -1;

		for (int k = 1; k <= n; k++)
		{
			if (!visit[k] && (v == -1 || distant[k] < distant[v]))
			{
				v = k;
			}
		}

		visit[v] = 1;
		ans += distant[v];

		for (int k = 1; k <= n; k++)
		{
			if (!visit[k])
			{
				distant[k] = min(distant[k], g[k][v]);
			}
		}

	}

	cout << ans;
	return 0;
}
