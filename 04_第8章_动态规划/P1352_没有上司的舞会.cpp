// ======================================================================
// 洛谷 P1352  没有上司的舞会
// 难度: 普及    (题单顺序 54/69)
// 题目: https://www.luogu.com.cn/problem/P1352
// 记录: https://www.luogu.com.cn/record/281795934
// 结果: Accepted · 100 分 · 49 ms · 1556 KB · 提交于 2026-06-14 05:15
// 语言: C/C++（洛谷语言编号 28）
// ======================================================================

// ---------------------------- 题面 ----------------------------
//
// 【题目描述】
// 某大学有 $n$ 个职员，编号为 $1\ldots n$。
// 
// 他们之间有从属关系，也就是说他们的关系就像一棵以校长为根的树，父结点就是子结点的直接上司。
// 
// 现在有个周年庆宴会，宴会每邀请来一个职员都会增加一定的快乐指数 $r_i$，但是呢，如果某个职员的直接上司来参加舞会了，那么这个职员就无论如何也不肯来参加舞会了。
// 
// 所以，请你编程计算，邀请哪些职员可以使快乐指数最大，求最大的快乐指数。
//
// 【输入格式】
// 输入的第一行是一个整数 $n$。
// 
// 第 $2$ 到第 $(n + 1)$ 行，每行一个整数，第 $(i+1)$ 行的整数表示 $i$ 号职员的快乐指数 $r_i$。
// 
// 第 $(n + 2)$ 到第 $2n$ 行，每行输入一对整数 $l, k$，代表 $k$ 是 $l$ 的直接上司。
//
// 【输出格式】
// 输出一行一个整数代表最大的快乐指数。
//
// 【样例 #1】
// 输入:
// 7
// 1
// 1
// 1
// 1
// 1
// 1
// 1
// 1 3
// 2 3
// 6 4
// 7 4
// 4 5
// 3 5
// 
// 输出:
// 5
// 
//
// 【提示】
// #### 数据规模与约定
// 
// 对于 $100\%$ 的数据，保证 $1\leq n \leq 6 \times 10^3$，$-128 \leq r_i\leq 127$，$1 \leq l, k \leq n$，且给出的关系一定是一棵树。
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

int value[16010];
int dp[16010][2];
int in_degree[16010];
vector<int> edge[16010];

void dfs(int x,int father)
{
	dp[x][1] = value[x];
	dp[x][0] = 0;

	for (int i = 0; i < edge[x].size(); i++)
	{
		if (edge[x][i] != father)
		{
			dfs(edge[x][i], x);
			dp[x][1] += dp[edge[x][i]][0];
			dp[x][0] += max(dp[edge[x][i]][0], dp[edge[x][i]][1]);
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> value[i];
	}

	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;

		edge[a].push_back(b);
		edge[b].push_back(a);

		in_degree[a]++;
	}

	int ans = -0x3f3f3f3f;
	int root;

	for (int i = 1; i <= n; i++)
	{
		if (in_degree[i] == 0)
		{
			root = i;
			break;
		}
	}

	dfs(root, 0);

	cout << max(dp[root][1], dp[root][0]);
	return 0;
}
