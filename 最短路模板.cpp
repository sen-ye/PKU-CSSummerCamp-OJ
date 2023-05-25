#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int NUM = 100;
// 存图方式一
int graph[NUM][NUM];
// 存图方式二
struct edge
{
    int from, to, w;
};
vector<edge> e[NUM]; // e[i] 存储第i个节点的连边
// Floyd最短路 适用于小图
const int INF = 0x3f3f3f3f;
int n, m; // n个节点 m条边
void floyd()
{
    int s = 1;
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; ++i)
            if (graph[i][k] != INF)
                for (int j = 1; j <= n; ++j)
                    if (graph[i][j] > graph[i][k] + graph[k][j])
                        graph[i][j] = graph[i][k] + graph[k][j];
    }
}
// dijkstra最短路
struct s_node
{
    int id, n_dis;
    s_node(int b, int c) {id = b; n_dis = c;}
    bool operator<(const s_node & a) const
    {return n_dis > a.n_dis;}
};
int pre[NUM]; // 记录先驱节点
void dijkstra()
{
    int s = 1;
    int dis[NUM];
    bool done[NUM];
    memset(dis, 0x3f, sizeof dis);
    memset(done, 0, sizeof done);
    dis[s] = 0;
    priority_queue<s_node> q;
    q.push(s_node(s, dis[s]));
    while (!q.empty())
    {
        s_node u = q.top(); q.pop();
        if (done[u.id]) continue;
        done[u.id] = true;
        for (int i = 0; i < e[u.id].size(); ++i)
        {
            edge y = e[u.id][i];
            if (done[y.to]) continue;
            if (dis[y.to] > y.w + u.n_dis)
            {
                dis[y.to] = y.w + u.n_dis;
                q.push(s_node(y.to, dis[y.to]));
                pre[y.to] = u.id;
            }
        }
    }
}
// bellman-ford最短路 可以判断负圈
edge edges[10005];
void bellman()
{
    int d[NUM];
    memset(d, 0x3f, sizeof d);
    int s = 1;
    d[s] = 0;
    int k = 0;
    bool update = true;
    while (update)
    {
        ++k;
        update = false;
        if (k > n)
        {
            cout << "有负圈" << endl;
            return;
        }
        for (int i = 0; i < 2*m; ++i)
        {
            int from = edges[i].from, to = edges[i].to, w = edges[i].w;
            if (d[from] > d[to] + w) d[from] = d[to] + w, update = true;
        }
    }
}
int main()
{

    return 0;
}