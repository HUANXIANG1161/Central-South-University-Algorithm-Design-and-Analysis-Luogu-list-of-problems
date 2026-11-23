// ======================================================================
// 洛谷 P2440  木材加工
// 难度: 普及    (题单顺序 19/69)
// 题目: https://www.luogu.com.cn/problem/P2440
// 记录: https://www.luogu.com.cn/record/281341251
// 结果: Accepted · 100 分 · 147 ms · 936 KB · 提交于 2026-06-10 09:22
// 语言: C/C++（洛谷语言编号 28）
// ======================================================================

// ---------------------------- 题面 ----------------------------
//
// 【题目背景】
// 要保护环境。
//
// 【题目描述】
// 木材厂有 $n$ 根原木，现在想把这些木头切割成 $k$ 段长度**均**为 $l$ 的小段木头（木头有可能有剩余）。
// 
// 当然，我们希望得到的小段木头越长越好，请求出 $l$ 的最大值。
// 
// 木头长度的单位是 $\text{cm}$，原木的长度都是正整数，我们要求切割得到的小段木头的长度也是正整数。
// 
// 例如有两根原木长度分别为 $11$ 和 $21$，要求切割成等长的 $6$ 段，很明显能切割出来的小段木头长度最长为 $5$。
//
// 【输入格式】
// 第一行是两个正整数 $n,k$，分别表示原木的数量，需要得到的小段的数量。
// 
// 接下来 $n$ 行，每行一个正整数 $L_i$，表示一根原木的长度。
//
// 【输出格式】
// 仅一行，即 $l$ 的最大值。
// 
// 如果连 $\text{1cm}$ 长的小段都切不出来，输出 `0`。
//
// 【样例 #1】
// 输入:
// 3 7
// 232
// 124
// 456
// 输出:
// 114
//
// 【提示】
// #### 数据规模与约定
// 
// 对于 $100\%$ 的数据，有 $1\le n\le 10^5$，$1\le k\le 10^8$，$1\le L_i\le 10^8(i\in[1,n])$。
//
// ---------------------------- 代码 ----------------------------

#include <iostream>
#include <iomanip>
#include <cmath>
#include<stack>
#include<queue>
#include<algorithm>
#include<vector>
#include<numeric>

using namespace std;

int n, k, num;
int a[100010];

void bi_search(int left, int right)
{
	for(int i=0;i<=100;i++)
	{
		num = 0;
		int mid = (left + right) / 2;
		for (int i = 0; i < n; i++)
		{
			num += a[i] / mid;
		}
		if (num < k)
		{
			right=mid;
		}
		else if (num >= k)
		{
			left = mid;
		}
	}
	cout << left;
	return;
}

int main()
{
	cin >> n >> k;
	int max_length=0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		max_length = max(max_length, a[i]);
	}
	int l;
	long long sum = accumulate(a, a + n, 0LL);
	if (sum < k)
	{
		cout << 0;
		return 0;
	}

	bi_search(1, max_length);
	return 0;
}
