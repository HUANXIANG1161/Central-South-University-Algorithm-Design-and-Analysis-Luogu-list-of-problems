// ======================================================================
// 洛谷 P1486  [NOI2004] 郁闷的出纳员
// 难度: 提高+    (题单顺序 39/69)
// 题目: https://www.luogu.com.cn/problem/P1486
// 记录: https://www.luogu.com.cn/record/282187687
// 结果: Accepted · 100 分 · 288 ms · 2416 KB · 提交于 2026-06-18 01:13
// 语言: C/C++（洛谷语言编号 28）
// ======================================================================

// ---------------------------- 题面 ----------------------------
//
// 【题目描述】
// OIER 公司是一家大型专业化软件公司，有着数以万计的员工。作为一名出纳员，我的任务之一便是统计每位员工的工资。这本来是一份不错的工作，但是令人郁闷的是，我们的老板反复无常，经常调整员工的工资。如果他心情好，就可能把每位员工的工资加上一个相同的量。反之，如果心情不好，就可能把当前在公司的所有员工的工资扣除一个相同的量。我真不知道除了调工资他还做什么其它事情。
// 
// 工资的频繁调整很让员工反感，尤其是集体扣除工资的时候，一旦某位员工发现自己的工资已经低于了合同规定的工资下界，他就会立刻气愤地离开公司，并且再也不会回来了。每位员工的工资下界都是统一规定的。每当一个人离开公司，我就要从电脑中把他的工资档案删去，同样，每当公司招聘了一位新员工，我就得为他新建一个工资档案。
// 
// 老板经常到我这边来询问工资情况，他并不问具体某位员工的工资情况，而是问现在工资第 $k$ 多的员工拿多少工资。每当这时，我就不得不对数万个员工进行一次漫长的排序，然后告诉他答案。
// 
// 好了，现在你已经对我的工作了解不少了。正如你猜的那样，我想请你编一个工资统计程序。怎么样，不是很困难吧？
// 
// 如果某个员工的初始工资低于最低工资标准，那么将不计入最后的答案内。
//
// 【输入格式】
// 第一行有两个整数 $n$ 和 $\min$。$n$ 表示下面有多少条命令，$\min$ 表示工资下界。
// 
// 接下来的 $n$ 行，每行一个字符 $x$ 和一个整数 $k$，表示一条命令。命令可以是以下四种之一：
// 
// - `I k`  新建一个工资档案，初始工资为 $k$。如果某员工的初始工资低于工资下界，他将立刻离开公司。
// - `A k`   把每位员工的工资加上 $k$。
// - `S k`   把每位员工的工资扣除 $k$。
// - `F k`    查询第 $k$ 多的工资。
// 
// 在初始时，可以认为公司里一个员工也没有。
//
// 【输出格式】
// 对于每条 `F` 命令，你的程序要输出一行，仅包含一个整数，为当前工资第  $k$ 多的员工所拿的工资数，如果 $k$ 大于目前员工的数目，则输出 $-1$。
// 
// 输出的最后一行包含一个整数，为离开公司的员工的总数。
// 
// 请注意，初始工资低于工资下界的员工不算做离开公司的员工。
//
// 【样例 #1】
// 输入:
// 9 10
// I 60
// I 70
// S 50
// F 2
// I 30
// S 15
// A 5
// F 1
// F 2
// 
// 输出:
// 10
// 20
// -1
// 2
// 
//
// 【提示】
// #### 数据规模与约定
// 
// 对于全部的测试点，保证：
// 
// - `I` 命令的条数不超过 $10^5$；
// - `A` 和 `S` 命令的总条数不超过 $100$；
// - `F` 命令的条数不超过 $10^5$；
// - 每次工资调整的调整量不超过 $10^3$；
// - 新员工的工资不超过 $10^5$。
// - $0 \leq n \leq 3 \times 10^5$，$0 \leq \text{min} \leq 10^9$，输入的所有数字均在 $32$ 位带符号整型范围内。
//
// ---------------------------- 代码 ----------------------------

#include <iostream>
#include <cstdlib>
#include <ctime>
#define ll long long
using namespace std;

const int MAXN = 100010;
struct Node {
    int key, pri, size;
    int ch[2];
} tr[MAXN];
int root, cnt;

int new_node(int key) {
    tr[++cnt].key = key;
    tr[cnt].pri = rand();
    tr[cnt].size = 1;
    tr[cnt].ch[0] = tr[cnt].ch[1] = 0;
    return cnt;
}

void pushup(int x) {
    tr[x].size = tr[tr[x].ch[0]].size + tr[tr[x].ch[1]].size + 1;
}

void split(int now, int key, int &a, int &b) {
    if (!now) {
        a = b = 0;
        return;
    }
    if (tr[now].key < key) {
        a = now;
        split(tr[now].ch[1], key, tr[now].ch[1], b);
        pushup(a);
    } else {
        b = now;
        split(tr[now].ch[0], key, a, tr[now].ch[0]);
        pushup(b);
    }
}

int merge(int a, int b) {
    if (!a || !b) return a + b;
    if (tr[a].pri > tr[b].pri) {
        tr[a].ch[1] = merge(tr[a].ch[1], b);
        pushup(a);
        return a;
    } else {
        tr[b].ch[0] = merge(a, tr[b].ch[0]);
        pushup(b);
        return b;
    }
}

void insert(int key) {
    int a, b;
    split(root, key, a, b);
    root = merge(merge(a, new_node(key)), b);
}

int get_kth(int now, int k) {
    if (!now) return 0;
    int left_size = tr[tr[now].ch[0]].size;
    if (k <= left_size) {
        return get_kth(tr[now].ch[0], k);
    } else if (k == left_size + 1) {
        return tr[now].key;
    } else {
        return get_kth(tr[now].ch[1], k - left_size - 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));

    int n, min_sal;
    cin >> n >> min_sal;
    int add = 0;
    ll leave = 0;

    while (n--) {
        char op;
        int k;
        cin >> op >> k;
        if (op == 'I') {
            if (k >= min_sal) {
                insert(k - add);
            }
        } else if (op == 'A') {
            add += k;
        } else if (op == 'S') {
            add -= k;
            int threshold = min_sal - add;
            int a, b;
            split(root, threshold, a, b);
            leave += tr[a].size;
            root = b;
        } else if (op == 'F') {
            int sz = tr[root].size;
            if (k > sz) {
                cout << "-1\n";
            } else {
                int val = get_kth(root, sz - k + 1);
                cout << val + add << '\n';
            }
        }
    }
    cout << leave << '\n';
    return 0;
}
