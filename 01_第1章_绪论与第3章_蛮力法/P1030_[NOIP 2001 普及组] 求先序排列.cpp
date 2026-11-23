// ======================================================================
// 洛谷 P1030  [NOIP 2001 普及组] 求先序排列
// 难度: 普及-    (题单顺序 5/69)
// 题目: https://www.luogu.com.cn/problem/P1030
// 记录: https://www.luogu.com.cn/record/281195554
// 结果: Accepted · 100 分 · 20 ms · 1064 KB · 提交于 2026-06-08 10:43
// 语言: C/C++（洛谷语言编号 28）
// ======================================================================

// ---------------------------- 题面 ----------------------------
//
// 【题目描述】
// 给出一棵二叉树的中序与后序排列。求出它的先序排列。（约定树结点用不同的大写字母表示，且二叉树的节点个数 $ \le 8$）。
// 
//
// 【输入格式】
// 共两行，均为大写字母组成的字符串，表示一棵二叉树的中序与后序排列。
// 
//
// 【输出格式】
// 共一行一个字符串，表示一棵二叉树的先序。
// 
//
// 【样例 #1】
// 输入:
// BADC
// BDCA
// 
// 输出:
// ABCD
// 
//
// 【提示】
// **【题目来源】**
// 
// NOIP 2001 普及组第三题
//
// ---------------------------- 代码 ----------------------------

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void before(string in, string after)
{
    if (in.size() > 0)
    {
        char root = after[after.size() - 1];
        cout << root;
        int k = in.find(root);
        before(in.substr(0, k), after.substr(0, k));
        before(in.substr(k + 1), after.substr(k, in.size() - 1 - k));
    }
}

int main(){
    string in, after;
    cin >> in >> after;
    before(in, after);
    return 0;
}
