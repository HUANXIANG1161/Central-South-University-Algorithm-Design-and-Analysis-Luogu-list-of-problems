// ======================================================================
// 洛谷 P3378  【模板】堆
// 难度: 普及    (题单顺序 31/69)
// 题目: https://www.luogu.com.cn/problem/P3378
// 记录: https://www.luogu.com.cn/record/281528242
// 结果: Accepted · 100 分 · 1435 ms · 2448 KB · 提交于 2026-06-12 14:55
// 语言: C/C++（洛谷语言编号 28）
// ======================================================================

// ---------------------------- 题面 ----------------------------
//
// 【题目描述】
// 给定一个数列，初始为空，请支持下面三种操作：
// 
// 1. 给定一个整数 $x$，请将 $x$ 加入到数列中。
// 2. 输出数列中最小的数。
// 3. 删除数列中最小的数（如果有多个数最小，只删除 $1$ 个）。
// 
// 
// 
//
// 【输入格式】
// 第一行是一个整数，表示操作的次数 $n$。
// 接下来 $n$ 行，每行表示一次操作。每行首先有一个整数 $op$ 表示操作类型。
// - 若 $op = 1$，则后面有一个整数 $x$，表示要将 $x$ 加入数列。
// - 若 $op = 2$，则表示要求输出数列中的最小数。
// - 若 $op = 3$，则表示删除数列中的最小数。如果有多个数最小，只删除 $1$ 个。
//
// 【输出格式】
// 对于每个操作 $2$，输出一行一个整数表示答案。
//
// 【样例 #1】
// 输入:
// 5
// 1 2
// 1 5
// 2
// 3
// 2
// 
// 输出:
// 2
// 5
//
// 【提示】
// **【数据规模与约定】**
// - 对于 $30\%$ 的数据，保证 $n \leq 15$。
// - 对于 $70\%$ 的数据，保证 $n \leq 10^4$。
// - 对于 $100\%$ 的数据，保证 $1 \leq n \leq 10^6$，$1 \leq x \lt 2^{31}$，$op \in \{1, 2, 3\}$。
//
// ---------------------------- 代码 ----------------------------

#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include <cmath>
#include<cstring>
#define ll long long

using namespace std;

int heap[1000010];
int sise = 0, now;

void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
	return;
}

void add()
{
	int temp;
	cin >> temp;
	heap[++sise] = temp;
	now = sise;
	while (now != 1)
	{
		int next = now >> 1;
		if (heap[now] < heap[next])
		{
			swap(heap[now], heap[next]);
			now = next;
		}
		else break;
	}
	return;
}

void search()
{
	cout << heap[1] << endl;
	return;
}

void deletenode()
{
	swap(heap[sise], heap[1]);
	sise--;
	now = 1;
	while (true)
	{
		int left = now << 1;
		int right = now << 1 | 1;
		int min_pos = now; // 记录当前节点和左右孩子中最小的那个的位置

		// 如果左孩子存在，且比当前节点小
		if (left <= sise && heap[left] < heap[min_pos])
		{
			min_pos = left;
		}
		// 如果右孩子存在，且比当前最小的还小
		if (right <= sise && heap[right] < heap[min_pos])
		{
			min_pos = right;
		}

		// 如果当前节点已经是最小的，不用调整了，直接退出
		if (min_pos == now) break;

		// 否则和最小的孩子交换，继续向下调整
		swap(heap[now], heap[min_pos]);
		now = min_pos;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,op;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> op;
		if (op == 1)add();
		else if (op == 2)search();
		else deletenode();
	}
	return 0;
}
