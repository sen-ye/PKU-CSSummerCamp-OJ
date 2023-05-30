- [ 水题](#head1)
	- [ 寻找特殊年号(2023智能学院研究生上机测试)](#head2)
	- [Beautiful Year (Codeforces 271A)](#head3)
	- [ 数与字符串(2019计算机学科夏令营上机考试)](#head4)
	- [ 简单密码(2018研究生推免上机考试)](#head5)
	- [ 有趣的跳跃(2019研究生推免上机考试)](#head6)
	- [ 区间内的真素数(2018研究生推免上机考试)](#head7)
	- [ 因子分解(2017研究生推免上机考试)](#head8)
- [ DFS](#head9)
	- [ 括号生成(2023智能学院研究生上机测试)](#head10)
	- [ 岛屿周长(2017计算机学科夏令营上机考试)](#head11)
	- [ 马走日(2019信科研究生上机测试)](#head12)
	- [The Die Is Cast(2018计算机学科夏令营上机考试)](#head13)
- [ BFS](#head14)
	- [ 玩具摆放(2023智能学院研究生上机测试)](#head15)
	- [ 走迷宫(2019研究生推免上机考试)](#head16)
	- [ 拯救公主(2018研究生推免上机考试)](#head17)
	- [Prime Path(2017研究生推免上机考试)](#head18)
	- [ 抓住那头牛(2014研究生上机测试)](#head19)
- [ 并查集](#head20)
	- [The Suspects(2019信科研究生上机测试)](#head21)
	- [Wireless Network(2019研究生推免上机考试)](#head22)
	- [A Bug's Life(2018研究生推免上机考试)](#head23)
- [ 最短路](#head24)
	- [ 最短路(2023智能学院研究生上机测试)](#head25)
	- [Stockbroker Grapevine(2019信科研究生上机测试)](#head26)
	- [ Subway(2017计算机学科夏令营上机考试)](#head27)
- [ 最小生成树](#head28)
	- [ 丛林中的路(2016计算机学科夏令营上机考试)](#head29)
- [ 动态规划](#head30)
	- [ 酒鬼(2023智能学院研究生上机测试)](#head31)
	- [Jumping Cows(2019信科研究生上机测试)](#head32)
	- [ 开餐馆(2017大数据研究中心夏令营上机考试)](#head33)
- [ 数学](#head34)
	- [ 有多少种二叉树(2023智能学院研究生上机测试)](#head35)
# <span id="head1"> 水题</span>

## <span id="head2"> 寻找特殊年号(2023智能学院研究生上机测试)</span>

[OpenJudge - A:寻找特殊年号](http://bailian.openjudge.cn/ss2023zn/A/)

```c++
#include <iostream>
#include <algorithm>

using namespace std;
int y;
int main()
{
    cin >> y;
    for (int x = y + 1; ; x++)
    {
        int a1 = x % 10;
        int a2 = (x / 10) % 10;
        int a3 = (x / 100) % 10;
        int a4 = (x / 1000);
        if ((a1 + a2 + a3 + a4 == 20))
        {
            cout << x;
            break;
        }
    }
    return 0;
}
```

## <span id="head3">Beautiful Year (Codeforces 271A)</span>

[Problem - 271A - Codeforces](https://codeforces.com/problemset/problem/271/A)与上一题很相似

```c++
#include <iostream>
#include <algorithm>

using namespace std;
int y;
int main()
{
    cin >> y;
    for (int x = y + 1; ; x++)
    {
        int a1 = x % 10;
        int a2 = (x / 10) % 10;
        int a3 = (x / 100) % 10;
        int a4 = (x / 1000);
        if ((a1 != a2) && (a1 != a3) && (a1 != a4) && (a2 != a3) && (a2 != a4) && (a3 != a4))
        {
            cout << x;
            break;
        }
    }
    return 0;
}
```

## <span id="head4"> 数与字符串(2019计算机学科夏令营上机考试)</span>

[OpenJudge - A:数与字符串](http://bailian.openjudge.cn/xly2019/A/)

```c++
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string input;
int main()
{
    while (cin >> input)
    {
        if (input == "0")
            break;
        int len = input.length();
        string ans = "";
        bool flag = true;
        for (int i = 0; i < len -1; ++i)
        {
            if (input[i] != '9')
                flag = false;
            ans.push_back('9');
        }
        if (flag)
        {
            ans.push_back(input[len-1]);
        }
        cout << ans << endl;
    }
    return 0;
}
```

## <span id="head5"> 简单密码(2018研究生推免上机考试)</span>

[OpenJudge - 2767:简单密码](http://bailian.openjudge.cn/practice/2767?lang=en_US)

```c++
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
string input, ans;
int main()
{
    getline(cin, input);
    for (int i = 0; i < input.length(); ++i)
    {
        if (input[i] >= 'A' && input[i] <= 'Z')
            ans.push_back('A'+(input[i] - 'A' + 21) % 26);
        else
            ans.push_back(input[i]);
    }
    cout << ans;
    return 0;
}
```

## <span id="head6"> 有趣的跳跃(2019研究生推免上机考试)</span>

[OpenJudge - A:有趣的跳跃](http://bailian.openjudge.cn/tm2019/A/)

```c++
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <map>

using namespace std;

bool vis[5000];
int n;
int num[5000];
int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> num[i];
    if (n == 1)
        cout << "Jolly" << endl;
    else
    {
        bool flag = true;
        for (int i = 0; i < n - 1; ++i)
        {
            int diff = abs(num[i] - num[i + 1]);
            if (diff == 0 || diff > n - 1 || vis[diff])
            {
                flag = false;
                cout << "Not jolly" << endl;
                break;
            }
            vis[diff] = 1;
        }
        if (flag)
            cout << "Jolly" << endl;
    }
    return 0;
}
```

## <span id="head7"> 区间内的真素数(2018研究生推免上机考试)</span>

[OpenJudge - 23:区间内的真素数](http://noi.openjudge.cn/CH0113/23?lang=en_US)

```c++
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <map>

using namespace std;

bool prime[100005];
int invert(int a)
{
    int res = 0;
    while (a)
    {
        res *= 10;
        res += (a % 10);
        a /= 10;
    }
    return res;
}
void getprime()
{
    for (int i = 2; i <= 100000; ++i)
    {
        if (!prime[i])
        {
            for (int j = 2; i*j <= 100000; ++j)
                prime[i*j] = 1;
        }
    }
}
int M, N;
int main()
{
    cin >> M >> N;
    getprime();
    int num = 0;
    for (int i = M; i <= N; ++i)
    {
        if (!prime[i] && !prime[invert(i)])
        {
            if (num == 0)
            {
                num++;
                cout << i;
            }
            else
                cout << "," << i;
        }
    }
    if (num == 0)
        cout << "No";
    return 0;
}
```

## <span id="head8"> 因子分解(2017研究生推免上机考试)</span>

[OpenJudge - 22:因子分解](http://noi.openjudge.cn/CH0113/22?lang=en_US)

```c++
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <map>

using namespace std;

bool prime[105];
int n;
vector<int> primes;
void getprime()
{
    for (int i = 2; i <= 105; ++i)
    {
        if (!prime[i])
        {
            primes.push_back(i);
            for (int j = 2; i*j <= 105; ++j)
                prime[i*j] = 1;
        }
    }
}
void solve()
{
    vector<pair<int, int>> ans;
    getprime();
    for (int i = 0; i < primes.size(); ++i)
    {
        if (n % primes[i] == 0)
        {
            int exp = 0;
            while (n)
            {
                exp++;
                n /= primes[i];
                if (n % primes[i]) break;
            }
            ans.push_back(make_pair(primes[i], exp));
        }
    }
    for (int i = 0; i < ans.size(); ++i)
    {
        if (i) cout << "*";
        cout << ans[i].first;
        if (ans[i].second > 1)
            cout << "^" << ans[i].second;
    }
}
int main()
{
    cin >> n;
    solve();
    return 0;
}
```











# <span id="head9"> DFS</span>

## <span id="head10"> 括号生成(2023智能学院研究生上机测试)</span>

[OpenJudge - C:括号生成](http://bailian.openjudge.cn/ss2023jsj/C/)
[22. 括号生成 - 力扣（LeetCode）](https://leetcode.cn/problems/generate-parentheses/)

```c++
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n;
void dfs(string s, int left, int right)
{
    if (left < 0 || left > right)
        return;
    if (left == 0 && right == 0) {
        cout << s << endl;
        return;
    }
    dfs(s + '(', left - 1, right);
    dfs(s + ')', left, right - 1);
}
int main()
{
    cin >> n;
    dfs("", n, n);
    return 0;
}
```

## <span id="head11"> 岛屿周长(2017计算机学科夏令营上机考试)</span>

[OpenJudge - C:岛屿周长(matrix)](http://bailian.openjudge.cn/xly2017/C/)
[463. 岛屿的周长 - 力扣（LeetCode）](https://leetcode.cn/problems/island-perimeter/)

```c++
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <map>

using namespace std;

bool vis[120][120];
int plat[120][120];
int n, m, ans;
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
void dfs(int x, int y)
{
    vis[x][y] = 1;
    if (plat[x][y] == 0)
    {
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx > 0 && ny > 0 && plat[nx][ny]) ans++;
        }
        return;
    }
    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx <= n + 1 && ny >= 0 && ny <= m + 1 && !vis[nx][ny])
            dfs(nx, ny);
    }
}

int main()
{
    int sx, sy;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            cin >> plat[i][j];
            if (plat[i][j]) sx = i, sy = j;
        }
    dfs(sx, sy);
    cout << ans;
    return 0;
}
```

## <span id="head12"> 马走日(2019信科研究生上机测试)</span>

[OpenJudge - 4123:马走日](http://bailian.openjudge.cn/practice/4123/)

```c++
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <cstring>

using namespace std;

int n, m, x, y, T, ans=0;
bool vis[20][20];
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};
void dfs(int a, int b, int passed)
{
    vis[a][b] = 1;
    if (passed == n * m)
    {
        ans++;
        vis[a][b] = 0;
        return;
    }
    for (int i = 0; i < 8; ++i)
    {
        int nx = a + dx[i], ny = b + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny])
            dfs(nx, ny, passed+1);
    }
    vis[a][b] = 0;
}
int main()
{
    cin >> T;
    while (T--)
    {
        memset(vis, 0, sizeof vis);
        ans = 0;
        cin >> n >> m >> x >> y;
        dfs(x, y, 1);
        cout << ans << endl;
    }
    return 0;
}
```

## <span id="head13">The Die Is Cast(2018计算机学科夏令营上机考试)</span>

[OpenJudge - 1481:The Die Is Cast](http://bailian.openjudge.cn/practice/1481/)

```c++
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <cstring>

using namespace std;

int w, h, n, res;
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
char plot[60][60];
bool vis[60][60];
bool vis2[60][60];
vector<int> ans;
void ddfs(int x, int y)
{
    vis2[x][y] = 1;
    for (int i = 0; i < 4; ++i){
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < h && ny >= 0 && ny < w && !vis2[nx][ny] && plot[nx][ny] == 'X')
            ddfs(nx, ny);
    }
}
void dfs(int x, int y)
{
    vis[x][y] = true;
    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < h && ny >= 0 && ny < w && !vis[nx][ny])
        {
            if (plot[nx][ny] == '*') dfs(nx, ny);
            else if (plot[nx][ny] == 'X')
            {
                if (!vis2[nx][ny]){
                    res++;
                    ddfs(nx, ny);
                }
                dfs(nx, ny);
            }
        }
    }
}
int main()
{
    while (cin >> w >> h)
    {
        if (!w) break;
        n++;
        memset(vis, 0, sizeof vis);
        memset(vis2, 0, sizeof vis2);
        ans.clear();
        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j)
                cin >> plot[i][j];
        for (int i = 0; i < h; ++i){
            for (int j = 0; j < w; ++j)
            {
                if (plot[i][j] == '*' && !vis[i][j]) {
                    res = 0;
                    dfs(i, j);
                    ans.push_back(res);
                }
            }
        }
        cout << "Throw " << n << endl;
        sort(ans.begin(), ans.end());
        cout << ans[0];
        for (int i = 1; i < ans.size(); ++i)
            cout << " " << ans[i];
        cout << "\n" << endl;
    }
    return 0;
}
```

# <span id="head14"> BFS</span>

## <span id="head15"> 玩具摆放(2023智能学院研究生上机测试)</span>

[OpenJudge - G:玩具摆放](http://bailian.openjudge.cn/ss2023jsj/G/)
[P4289 [HAOI2008\]移动玩具 - 洛谷 | 计算机科学教育新生态 (luogu.com.cn)](https://www.luogu.com.cn/problem/P4289) （同一题）

```c++
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <map>

using namespace std;

char states[2][4][4];
map<string, bool> vis;
int nx[4] = {1, -1, 0, 0}, ny[4] = {0, 0, 1, -1};
struct state
{
    string s;
    int step;
};
string char2string(char c[4][4])
{
    string res = "";
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j) res.push_back(c[i][j]);
    return res;
}
void bfs()
{
    string init_string = char2string(states[0]);
    string end_string = char2string(states[1]);
    struct state a;
    a.s = init_string, a.step = 0;
    queue<state> Q;
    Q.push(a);
    vis[init_string] = true;
    while (!Q.empty())
    {
        struct state head = Q.front(); Q.pop();
        if (head.s == end_string)
        {
            cout << head.step << endl;
            break;
        }
        char now_state[4][4];
        for (int i = 0; i <4; ++i)
            for (int j = 0; j <4; ++j)
                now_state[i][j] = head.s[4*i+j];
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                if (now_state[i][j] == '1')
                {
                    for (int k = 0; k < 4; ++k)
                    {
                        int next_x = i + nx[k], next_y = j + ny[k];
                        if (next_x >= 0 && next_x < 4 && next_y >= 0 && next_y < 4 && now_state[next_x][next_y] == '0')
                        {
                            swap(now_state[i][j], now_state[next_x][next_y]);
                            string next_string = char2string(now_state);
                            if (vis.find(next_string) == vis.end())
                            {
                                vis[next_string] = 1;
                                struct state b;
                                b.s = next_string, b.step = head.step + 1;
                                Q.push(b);
                            }
                            swap(now_state[i][j], now_state[next_x][next_y]);
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    for (int i = 0; i <= 1; ++i)
        for (int j = 0; j < 4; ++j)
            for (int k = 0; k < 4; ++k) cin >> states[i][j][k];
    bfs();
    return 0;
}
```

## <span id="head16"> 走迷宫(2019研究生推免上机考试)</span>

[OpenJudge - 3752:走迷宫](http://bailian.openjudge.cn/practice/3752?lang=en_US)

```c++
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <map>

using namespace std;

int R, C;
char maze[50][50];
bool vis[50][50];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
struct pos{
    int x, y, step;
};
void bfs()
{
    queue<pos> q;
    struct pos start;
    start.x = 1, start.y = 1, start.step = 1;
    q.push(start);
    vis[1][1] = 1;
    while (!q.empty())
    {
        struct pos head = q.front();q.pop();
        int cx = head.x, cy = head.y;
        for (int i = 0; i < 4; ++i)
        {
            int nx = cx + dx[i], ny = cy + dy[i];
            if (nx > 0 && nx <= R && ny > 0 && ny <= C && !vis[nx][ny] && maze[nx][ny] == '.')
            {
                if (nx == R && ny == C)
                {
                    cout << head.step + 1;
                    return;
                }
                struct pos nex;
                nex.x = nx, nex.y = ny, nex.step = head.step + 1;
                vis[nx][ny] = 1;
                q.push(nex);
            }
        }
    }
}
int main()
{
    cin >> R >> C;
    for (int i = 1; i <= R; ++i)
        for (int j = 1; j <= C; ++j) cin >> maze[i][j];
    bfs();
    return 0;
}
```

## <span id="head17"> 拯救公主(2018研究生推免上机考试)</span>

[OpenJudge - C:拯救公主](http://bailian.openjudge.cn/tm2018/C/)

```c++
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <cstring>

using namespace std;

int N, M, V, k, sx, sy, ex, ey;
bool vis[105][105][12];
char plot[105][105];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
struct pos
{
    int x, y, power, direction, time_step;
};
void bfs()
{
    queue<struct pos> q;
    struct pos start = {sx, sy, V, 0, 0};
    q.push(start);
    while (!q.empty())
    {
        struct pos head = q.front(); q.pop();
        int xx = head.x, yy = head.y, pow = head.power, td = head.time_step, dir = head.direction;
        if (head.x == ex && head.y == ey)
        {
            cout << "Case #" << k << ": " << head.time_step << endl;
            return;
        }
        if (plot[xx][yy] == 'E')
        {
            for (int i = 2; i <= pow; ++i)
            {
                int nx = xx + i*dx[dir], ny = yy + i*dy[dir];
                nx = max(nx, 0), ny = max(ny, 0);
                nx = min(nx, N), ny = min(ny, M);
                if (plot[nx][ny] == '#' || vis[nx][ny][i]) continue;
                struct pos next_pos = {nx, ny, i, dir, td};
                q.push(next_pos);
            }
        }
        for (int i = 0; i < 4; ++i)
        {
            int nx = xx + dx[i], ny = yy + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && plot[nx][ny] != '#' && !vis[nx][ny][pow])
            {
                struct pos next_pos = {nx, ny, pow, i, td+1};
                q.push(next_pos);
            }
        }
    }
    cout << "Case #" << k << ": " << -1 << endl;
}
int main()
{
    while (cin >> N >> M >> V)
    {
        if (!N) break;
        k++;
        memset(vis, 0, sizeof vis);
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j) {
                cin >> plot[i][j];
                if (plot[i][j] == 'T') ex = i, ey = j;
                else if (plot[i][j] == 'S') sx = i, sy = j;
            }
        bfs();
    }
    return 0;
}
```

## <span id="head18">Prime Path(2017研究生推免上机考试)</span>

[OpenJudge - F:Prime Path](http://bailian.openjudge.cn/tm2017/F/)

```c++
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <cstring>
#include <sstream>

using namespace std;

int T;
bool prime[10005];
int p1, p2;
string s1, s2;
void isPrime()
{
    for (int i = 2; i <= 10000; ++i)
    {
        if (!prime[i])
        {
            for (int j = 2; i*j <= 10000; ++j)
                prime[i*j] = true;
        }
    }
}
void bfs()
{
    queue<pair<string, int>> q;
    q.push(make_pair(s1, 0));
    map<string, bool> vis;
    vis[s1] = true;
    while (!q.empty())
    {
        pair<string, int> head = q.front(); q.pop();
        string head_s = head.first;
        if (head_s == s2)
        {
            cout << head.second << endl;
            return;
        }
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 10; ++j)
            {
                if (i == 0 && j == 0) continue;
                string new_s = head_s;
                new_s[i] = '0' + j;
                int new_digit;
                stringstream ss1(new_s);
                ss1 >> new_digit;
                if (vis.find(new_s) == vis.end() && !prime[new_digit])
                {
                    vis[new_s] = true;
                    q.push(make_pair(new_s, head.second+1));
                }
            }
        }
    }
}
int main()
{
    isPrime();
    cin >> T;
    while (T--)
    {
        stringstream ss;
        cin >> p1 >> p2;
        ss << p1; ss >> s1;
        ss.clear();
        ss << p2; ss >> s2;
        bfs();
    }
    return 0;
}
```

## <span id="head19"> 抓住那头牛(2014研究生上机测试)</span>

[OpenJudge - 4001:抓住那头牛](http://bailian.openjudge.cn/practice/4001/)

```c++
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <cstring>

using namespace std;

bool vis[100005];
int N, K;
void bfs()
{
    queue<pair<int, int>> q;
    q.push(make_pair(N, 0));
    vis[N] = 1;
    while (!q.empty())
    {
        pair<int, int> head = q.front(); q.pop();
        if (head.first == K)
        {
            cout << head.second << endl;
            break;
        }
        if (head.first - 1 >= 0 && !vis[head.first -1])
        {
            vis[head.first - 1] = 1;
            q.push(make_pair(head.first-1, head.second+1));
        }
        if (head.first+1 <= 100000 && !vis[head.first+1])
        {
            vis[head.second+1] = 1;
            q.push(make_pair(head.first+1, head.second+1));
        }
        if (head.first*2 <= 100000 && !vis[head.first*2])
        {
            vis[head.first*2] = 1;
            q.push(make_pair(head.first*2, head.second+1));
        }
    }
}
int main()
{
    cin >> N >> K;
    bfs();
    return 0;
}
```

# <span id="head20"> 并查集</span>

## <span id="head21">The Suspects(2019信科研究生上机测试)</span>

[OpenJudge - 1611:The Suspects](http://bailian.openjudge.cn/practice/1611/)

```c++
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <cstring>
#include <sstream>

using namespace std;

int fa[300005];
int n, m, k, a, b;
inline void init()
{
    for (int i = 0; i < n; ++i) fa[i] = i;
}
int find(int x)
{
    return fa[x] == x ? x : (fa[x] = find(fa[x]));
}
void merge(int i, int j)
{
    fa[find(i)] = find(j);
}
int main()
{
    while (cin >> n >> m)
    {
        if (!n) break;
        init();
        for (int i = 0; i < m; ++i)
        {
            cin >> k;
            cin >> a;
            for (int j = 1; j < k; ++j)
            {
                cin >> b;
                merge(a, b);
            }
        }
        int sus = find(0), ans= 0;
        for (int i = 0; i < n; ++i)
            if (sus == find(i)) ans++;
        cout << ans << endl;
    }
    return 0;
}
```

## <span id="head22">Wireless Network(2019研究生推免上机考试)</span>

[OpenJudge - 2236:Wireless Network](http://bailian.openjudge.cn/practice/2236/)

```c++
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <cstring>
#include <sstream>

using namespace std;

int N, d, a, b;
char op;
struct node
{
    int x, y;
}nodes[1005];
int fa[1005];
bool ok[1005];
inline void init()
{
    for (int i = 0; i <= 1005; ++i) fa[i] = i;
}
int find(int x)
{
    return fa[x] == x ? fa[x] : (fa[x] = find(fa[x]));
}
void merge(int i, int j)
{
    fa[find(i)] = find(j);
}
int dis(node& a, node& b)
{
    return (a.x - b.x)*(a.x - b.x) + (a.y-b.y)*(a.y-b.y);
}
int main()
{
    scanf("%d%d", &N, &d);
    for (int i = 1; i <= N; ++i)
        scanf("%d%d", &nodes[i].x, &nodes[i].y);
    init();
    while (~scanf("%c", &op))
    {
        if (op == 'O')
        {
            scanf("%d", &a);
            ok[a] = true;
            for (int i = 1; i <= N; ++i)
            {
                if (i == a) continue;
                if (ok[i] && dis(nodes[a], nodes[i]) <= d*d) merge(a, i);
            }
        }
        else if (op == 'S')
        {
            scanf("%d%d", &a, &b);
            int faa = find(a), fab = find(b);
            if (faa == fab && ok[a] && ok[b]) printf("SUCCESS\n");
            else printf("FAIL\n");
        }
    }
    return 0;
}
```

## <span id="head23">A Bug's Life(2018研究生推免上机考试)</span>

[OpenJudge - 2492:A Bug's Life](http://bailian.openjudge.cn/practice/2492/)s

```c++
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <cstring>
#include <sstream>

using namespace std;

int T, n, m, x, y;
int fa[4005];
inline void init()
{
    for (int i = 1; i <= 2*n; ++i) fa[i] = i;
}
int find(int x)
{
    return fa[x] == x ? fa[x] : (fa[x] = find(fa[x]));
}
void merge(int i, int j)
{
    fa[find(i)] = find(j);
}
int main()
{
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t)
    {
        bool flag = false;
        scanf("%d%d", &n, &m);
        init();
        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d", &x, &y);
            if (flag) continue;
            if (find(x) == find(y)) {flag = true; continue;}
            merge(x, y + n);
            merge(y, x + n);
        }
        if (flag)
        {
            printf("Scenario #%d:\n", t);
            printf("Suspicious bugs found!\n\n");
        }
        else
        {
            printf("Scenario #%d:\n", t);
            printf("No suspicious bugs found!\n\n");
        }
    }
    return 0;
}
```

# <span id="head24"> 最短路</span>

## <span id="head25"> 最短路(2023智能学院研究生上机测试)</span>

[OpenJudge - F:最短路](http://bailian.openjudge.cn/ss2023zn/F/)

```c++
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <cstring>
#include <sstream>

using namespace std;
const int INF = 0x3f3f3f3f;
int T, n, m, S;
struct edge
{
    int from, to, w;
}e[20005];
int dis[10005];
void bellman()
{
    memset(dis, 0x3f, sizeof dis);
    dis[S] = 0;
    int k = 0;
    bool update = true;
    while (update)
    {
        update = false;
        k++;
        if (k > n)
        {
            cout << "Error" << endl;
            return;
        }
        for (int i = 0; i < m; ++i)
        {
            edge y = e[i];
            if (dis[y.to] > dis[y.from] + y.w) dis[y.to] = dis[y.from] + y.w, update = true;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (i) cout << " ";
        if (dis[i] == INF) cout << "NULL";
        else cout << dis[i];
    }
    cout << endl;
}
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n >> m >> S;
        for (int i = 0; i < m;++i)
            cin >> e[i].from >> e[i].to >> e[i].w;
        bellman();
    }
    return 0;
}
```

## <span id="head26">Stockbroker Grapevine(2019信科研究生上机测试)</span>

[OpenJudge - 1125:Stockbroker Grapevine](http://bailian.openjudge.cn/practice/1125/)

```C++
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <cstring>
#include <sstream>

using namespace std;

const int INF = 0x3f3f3f3f;
int graph[105][105];
int n, m, p, t;
void floyd()
{
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            if (graph[i][k] != INF)
                for (int j = 1; j <= n; ++j)
                    if (graph[i][j] > graph[i][k] + graph[k][j])
                        graph[i][j] = graph[i][k] + graph[k][j];
    int min_dis = INF, ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        int max_dis = 0;
        for (int j = 1; j <= n; ++j)
        {
            if (i == j) continue;
            max_dis = max(max_dis, graph[i][j]);
        }
        if (max_dis < min_dis)
        {
            min_dis = max_dis;
            ans = i;
        }
    }
    if (ans == 0)
        cout << "disjoint" << endl;
    else
        cout << ans << " " << min_dis << endl;
}
int main()
{
    while (cin >> n && n)
    {
        memset(graph, 0x3f, sizeof graph);
        for (int i = 1; i <= n; ++i)
        {
            cin >> m;
            for (int j = 0; j < m; ++j)
            {
                cin >> p >> t;
                graph[i][p] = t;
            }
        }
        floyd();
    }
    return 0;
}
```

## <span id="head27"> Subway(2017计算机学科夏令营上机考试)</span>

[OpenJudge - 2502:Subway](http://bailian.openjudge.cn/practice/2502/)

```c++
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <cstring>
#include <sstream>
#include <cmath>

using namespace std;

const int INF = 0X3f3f3f3f;

double dis(int ax, int ay, int bx, int by)
{
    double diffx = ax - bx, diffy = ay - by;
    return sqrt(diffx*diffx + diffy*diffy);
}
int sx, sy, ex, ey, xx, yy, n, j;
double graph[405][405];
int x[405], y[405];
void floyd()
{
    for (int k = 1; k < n; ++k)
        for (int i = 1; i < n; ++i)
            for (int m = 1; m < n; ++m)
                if (graph[i][m] > graph[i][k] + graph[k][m])
                    graph[i][m] = graph[i][k] + graph[k][m];
    cout << round(graph[1][2]);
}
int main()
{
    scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
    n = 3, j = 0;
    x[1] = sx, x[2] = ex, y[1] = sy, y[2] = ey;
    graph[1][2] = graph[2][1] = dis(sx, sy, ex, ey) / 10000.0 * 60.0;
    while (~scanf("%d%d", &xx, &yy))
    {
        if (xx == -1) j = 0;
        else
        {
            x[n] = xx, y[n] = yy;
            for (int i = 1; i <= n -1; ++i) graph[i][n] = graph[n][i] = dis(x[i], y[i], x[n], y[n]) / 1000.0 * 6.0;
            for (int i = n - 1; i >= n - j; --i) graph[i][n] = graph[n][i] = dis(x[i], y[i], x[n], y[n]) / 4000.0 * 6.0;
            ++n, j = 1;
        }
    }
    floyd();
    return 0;
}
```

# <span id="head28"> 最小生成树</span>

## <span id="head29"> 丛林中的路(2016计算机学科夏令营上机考试)</span>

[OpenJudge - 1251:丛林中的路](http://bailian.openjudge.cn/practice/1251/)

```c++
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <cstring>
#include <sstream>
#include <cmath>

using namespace std;

int n, a, b, m, dis, cnt;
int fa[30];
char c1, c2;
struct Edge
{
    int u, v, w;
}edge[100];
void init()
{
    cnt = 0;
    for (int i = 0; i < 30; ++i) fa[i] = i;
}
int find(int x)
{
    return fa[x] == x ? fa[x] : (fa[x] = find(fa[x]));
}
bool cmp(Edge a, Edge b){return a.w < b.w;}
int solve()
{
    int ans = 0;
    sort(edge, edge + cnt, cmp);
    for (int i = 0; i < cnt; ++i)
    {
        int u = find(edge[i].u), v = find(edge[i].v);
        if (u == v) continue;
        fa[u] = v;
        ans += edge[i].w;
    }
    return ans;
}
int main()
{
    while (cin >> n && n)
    {
        init();
        for (int i = 0; i < n - 1; ++i)
        {
            cin >> c1 >> m;
            a = c1 - 'A';
            for (int j = 0; j < m; ++j)
            {
                cin >> c2 >> dis;
                b = c2 - 'A';
                edge[cnt] = {a, b, dis};
                cnt++;
            }
        }
        cout << solve() << endl;
    }
    return 0;
}
```

# <span id="head30"> 动态规划</span>

## <span id="head31"> 酒鬼(2023智能学院研究生上机测试)</span>

[OpenJudge - E:酒鬼](http://bailian.openjudge.cn/ss2023zn/E/)





## <span id="head32">Jumping Cows(2019信科研究生上机测试)</span>

[OpenJudge - D:Jumping Cows](http://bailian.openjudge.cn/ss2019/D/)





## <span id="head33"> 开餐馆(2017大数据研究中心夏令营上机考试)</span>

[OpenJudge - E:开餐馆](http://bailian.openjudge.cn/dsj2017xly/E/)





# <span id="head34"> 数学</span>

## <span id="head35"> 有多少种二叉树(2023智能学院研究生上机测试)</span>

[OpenJudge - D:有多少种二叉树](http://bailian.openjudge.cn/ss2023zn/D/)
[「算法入门笔记」卡特兰数 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/97619085)

```c++
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <cstring>
#include <sstream>
#include <cmath>

using namespace std;


int main()
{
    int n;
    long long ans = 1;
    cin >> n;
    for (int i = 2; i <= n; ++i)
        ans = ans * (4 * i - 2) / (i + 1);
    cout << ans;
    return 0;
}
```
