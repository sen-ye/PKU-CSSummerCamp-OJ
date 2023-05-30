#include <iostream>
#include <algorithm>

using namespace std;
int fa[100];
struct Edge{
    int u, v, w;
} edge[10000];
inline void init()
{
    for (int i = 0; i < 100; ++i) fa[i] = i;
}
int find(int x)
{
    return fa[x] == x ? fa[x] : (fa[x] = find(fa[x]));
}
bool cmp(Edge a, Edge b){return a.w < b.w;}
int main()
{
    int ans = 0;
    init();
    // read edges
    sort(edge, edge + 10000, cmp);
    for (int i = 0; i < 10000; ++i)
    {
        int a = find(edge[i].u);
        int b = find(edge[i].v);
        if (a == b) continue;
        ans += edge[i].w;
        fa[a] = b;
    }
    cout << ans;
    return 0;
}