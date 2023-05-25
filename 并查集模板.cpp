#include <iostream>

using namespace std;

const int MAXN = 10000;
int fa[MAXN]; // 存储每个元素父节点

// init
inline void init()
{
    for (int i = 1; i <=MAXN; ++i) fa[i] = i;
}
// 查询
int find(int x)
{
    return fa[x] == x ? x : (fa[x] = find(fa[x]));
}
// 合并
void merge(int i, int j)
{
    fa[find(i)] = find(j);
}
int main()
{

    return 0;
}

