// ======================================================================
// 洛谷 B3644  【模板】拓扑排序 / 家谱树
// 难度: 普及    (题单顺序 18/69)
// 题目: https://www.luogu.com.cn/problem/B3644
// 记录: https://www.luogu.com.cn/record/281340506
// 结果: Accepted · 100 分 · 28 ms · 1072 KB · 提交于 2026-06-10 08:47
// 语言: C/C++（洛谷语言编号 28）
// ======================================================================

// ---------------------------- 题面 ----------------------------
//
// 【题目描述】
// 有个人的家族很大，辈分关系很混乱，请你帮整理一下这种关系。给出每个人的后代的信息。输出一个序列，使得每个人的后辈都比那个人后列出。
//
// 【输入格式】
// 第 $1$ 行一个整数 $N$（$1 \le N \le 100$），表示家族的人数。接下来 $N$ 行，第 $i$ 行描述第 $i$ 个人的后代编号 $a_{i,j}$，表示 $a_{i,j}$ 是 $i$ 的后代。每行最后是 $0$ 表示描述完毕。
//
// 【输出格式】
// 输出一个序列，使得每个人的后辈都比那个人后列出。如果有多种不同的序列，输出任意一种即可。
//
// 【样例 #1】
// 输入:
// 5
// 0
// 4 5 1 0
// 1 0
// 5 3 0
// 3 0
// 输出:
// 2 4 5 3 1
//
// ---------------------------- 代码 ----------------------------

#include <iostream>
#include <iomanip>
#include <cmath>
#include<stack>
#include<queue>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<int> after[110];//后代
int in[110];//入度
bool use[110];//使用过为1

int find_after(int dot)
{
	for (int i = 0; i < after[dot].size(); i++)
	{
		if (use[after[dot][i]] == 0 && in[after[dot][i]] == 0)return after[dot][i];//找到了输出下一个点
	}
	return -1;//没找到回大数组找
}

int find_whole() //回大数组找
{
	for (int i = 1; i < n; i++)
	{
		if (use[i]==0 && in[i] == 0)return i;
	}
}

void update_in(int dot)//更新入度
{
	for (int i = 0; i < after[dot].size(); i++)
	{
		in[after[dot][i]]--;
	}
}

int main() {
	cin >> n;
	queue<int> ans;
	for (int i = 1; i <= n;)//入后代vector
	{
		int con;
		cin >> con;
		if (con == 0)
		{
			i++;
			continue;
		}
		else
		{
			after[i].push_back(con);
			in[con]++;
		}
	}

	int dot;

	dot = find_whole();
	update_in(dot);
	ans.push(dot);
	use[dot] = 1;

	while (ans.size() != n)
	{
		dot = find_after(dot);
		if (dot != -1)
		{
			update_in(dot);
			ans.push(dot);
			use[dot] = 1;
		}
		else
		{
			dot = find_whole();
			update_in(dot);
			ans.push(dot);
			use[dot] = 1;
		}
	}

	while (!ans.empty())//输出答案队列
	{
		cout << ans.front()<<' ';
		ans.pop();
	}

	return 0;
}
