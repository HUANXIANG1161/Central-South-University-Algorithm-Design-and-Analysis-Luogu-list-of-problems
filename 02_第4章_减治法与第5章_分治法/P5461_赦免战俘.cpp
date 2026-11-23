// ======================================================================
// 洛谷 P5461  赦免战俘
// 难度: 普及    (题单顺序 22/69)
// 题目: https://www.luogu.com.cn/problem/P5461
// 记录: https://www.luogu.com.cn/record/281422327
// 结果: Accepted · 100 分 · 97 ms · 4744 KB · 提交于 2026-06-11 04:24
// 语言: C/C++（洛谷语言编号 28）
// ======================================================================

// ---------------------------- 题面 ----------------------------
//
// 【题目背景】
// 借助反作弊系统，一些在月赛有抄袭作弊行为的选手被抓出来了！
//
// 【题目描述】
// 现有 $2^n\times 2^n (n\le10)$ 名作弊者站成一个正方形方阵等候 kkksc03 的发落。kkksc03 决定赦免一些作弊者。他将正方形矩阵均分为 $4$ 个更小的正方形矩阵，每个更小的矩阵的边长是原矩阵的一半。其中左上角那一个矩阵的所有作弊者都将得到赦免，剩下 $3$ 个小矩阵中，每一个矩阵继续分为 $4$ 个更小的矩阵，然后通过同样的方式赦免作弊者……直到矩阵无法再分下去为止。所有没有被赦免的作弊者都将被处以棕名处罚。
// 
// 给出 $n$，请输出每名作弊者的命运，其中 $0$ 代表被赦免，$1$ 代表不被赦免。
//
// 【输入格式】
// 一个整数 $n$。
//
// 【输出格式】
// $2^n \times 2^n$ 的 01 矩阵，代表每个人是否被赦免。数字之间有一个空格。
//
// 【样例 #1】
// 输入:
// 3
// 输出:
// 0 0 0 0 0 0 0 1
// 0 0 0 0 0 0 1 1
// 0 0 0 0 0 1 0 1
// 0 0 0 0 1 1 1 1
// 0 0 0 1 0 0 0 1
// 0 0 1 1 0 0 1 1
// 0 1 0 1 0 1 0 1
// 1 1 1 1 1 1 1 1
//
// ---------------------------- 代码 ----------------------------

#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include <cmath>

using namespace std;

int n;
int a[1024 + 10][1024 + 10];

void mercy(int startcon, int startrow, int size)
{
	for (int i = startcon; i <= startcon+size-1; i++)
	{
		for (int j = startrow; j <= startrow+size-1; j++)
		{
			a[i][j] = 0;
		}
	}
}

void divide(int startcon, int startrow, int size)
{
	if (size == 1)return;
	int half = size / 2;
	mercy(startcon, startrow, half);
	divide(startcon, startrow + half, half);
	divide(startcon + half, startrow, half);
	divide(startcon + half, startrow + half, half);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	int conrow = pow(2, n);
	for (int i = 1; i <= conrow; i++)
	{
		for (int j = 1; j <= conrow; j++)
		{
			a[i][j] = 1;
		}
	}
	divide(1, 1, conrow);
	for (int i = 1; i <= conrow; i++)
	{
		for (int j = 1; j <= conrow; j++)
		{
			cout<<a[i][j]<<' ';
		}
		cout << endl;
	}
	return 0;
}
