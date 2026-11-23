// ======================================================================
// 洛谷 P2758  编辑距离
// 难度: 普及    (题单顺序 52/69)
// 题目: https://www.luogu.com.cn/problem/P2758
// 记录: https://www.luogu.com.cn/record/281795891
// 结果: Accepted · 100 分 · 64 ms · 14636 KB · 提交于 2026-06-14 04:31
// 语言: C/C++（洛谷语言编号 28）
// ======================================================================

// ---------------------------- 题面 ----------------------------
//
// 【题目描述】
// 设 $A$ 和 $B$ 是两个字符串。我们要用最少的字符操作次数，将字符串 $A$ 转换为字符串 $B$。这里所说的字符操作共有三种：
// 
// 1. 删除一个字符；
// 2. 插入一个字符；
// 3. 将一个字符改为另一个字符。
// 
// $A, B$ 均只包含小写字母。
// 
//
// 【输入格式】
// 第一行为字符串 $A$；第二行为字符串 $B$；字符串 $A, B$ 的长度均小于 $2000$。
// 
//
// 【输出格式】
// 只有一个正整数，为最少字符操作次数。
// 
//
// 【样例 #1】
// 输入:
// sfdqxbw
// gfdgw
// 
// 输出:
// 4
// 
//
// 【提示】
// 对于 $100 \%$ 的数据，$1 \le |A|, |B| \le 2000$。
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

int dp[2100][2100];


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string a1, a2;
	cin >> a1 >> a2;
	int len1 = a1.size();
	int len2 = a2.size();

	for (int i = 0; i <= len1; i++)
	{
		dp[i][0] = i;
	}
	for (int i = 0; i <= len2; i++)
	{
		dp[0][i] = i;
	}
	for (int i = 1; i <= len1; i++)
	{
		for (int j = 1; j <= len2; j++)
		{
			if (a1[i - 1] == a2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1];
			}
			else
			{
				dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1])+1;
			}
		}
	}

	cout << dp[len1][len2];
	return 0;
}
