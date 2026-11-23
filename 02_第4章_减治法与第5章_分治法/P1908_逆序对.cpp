// ======================================================================
// 洛谷 P1908  逆序对
// 难度: 普及    (题单顺序 21/69)
// 题目: https://www.luogu.com.cn/problem/P1908
// 记录: https://www.luogu.com.cn/record/281422311
// 结果: Accepted · 100 分 · 873 ms · 4436 KB · 提交于 2026-06-11 04:06
// 语言: C/C++（洛谷语言编号 28）
// ======================================================================

// ---------------------------- 题面 ----------------------------
//
// 【题目描述】
// 猫猫 TOM 和小老鼠 JERRY 最近又较量上了，但是毕竟都是成年人，他们已经不喜欢再玩那种你追我赶的游戏，现在他们喜欢玩统计。
// 
// 最近，TOM 老猫查阅到一个人类称之为“逆序对”的东西，这东西是这样定义的：对于给定的一段正整数序列，逆序对就是序列中 $a_i>a_j$ 且 $i<j$ 的有序对。知道这概念后，他们就比赛谁先算出给定的一段正整数序列中逆序对的数目。注意序列中可能有重复数字。
// 
// **Update：数据已加强。**
//
// 【输入格式】
// 第一行，一个数 $n$，表示序列中有 $n$ 个数。
// 
// 第二行 $n$ 个数，表示给定的序列。序列中每个数字不超过 $10^9$。
//
// 【输出格式】
// 输出序列中逆序对的数目。
//
// 【样例 #1】
// 输入:
// 6
// 5 4 2 6 3 1
// 
// 输出:
// 11
//
// 【提示】
// 对于 $25\%$ 的数据，$n \leq 2500$。
// 
// 对于 $50\%$ 的数据，$n \leq 4 \times 10^4$。
// 
// 对于所有数据，$1 \leq n \leq 5 \times 10^5$。
// 
// 应该不会有人 $O(n^2)$ 过 50 万吧 —— 2018.8 chen_zhe。
//
// ---------------------------- 代码 ----------------------------

#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>

using namespace std;

int  n;
int a[500010], b[500010];
long long ans = 0;

void merge_sort(int left, int mid, int right)
{
	int lh = left, rh = mid + 1, count = left;
	while (lh <= mid && rh <= right)
	{
		if (a[lh] <= a[rh])
		{
			b[count] = a[lh];
			lh++;
			count++;
		}
		else
		{
			ans += mid - lh + 1;
			b[count] = a[rh];
			rh++;
			count++;
		}
	}
	while (lh <= mid)
	{
		b[count++] = a[lh++];
	}
	while (rh <= right)
	{
		b[count++] = a[rh++];
	}
	for (int p = left; p <= right; p++) a[p] = b[p];
}

void m_sort(int left, int right)
{
	if (left >= right)return;
	int mid = (left + right) / 2;
	m_sort(left, mid);
	m_sort(mid + 1, right);
	merge_sort(left, mid, right);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	m_sort(1, n);
	cout << ans;
	return 0;
}
