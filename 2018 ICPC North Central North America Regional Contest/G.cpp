#pragma GCC diagnostic ignored "-Wunused-parameter"
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

#define INP "solve"
#define OUT "solve"

const long long INF_LL = 1e17;
const int INF = 1e9 + 100;
const int MOD = 1e9 + 7;
const int Base = 30;
const double EPS = 1e-9;
const int BLOCK = 1000;
const int dx[6] = {0, 0, 1, -1, 1, -1};
const int dy[6] = {1, -1, 0, 0, 1, -1};

void open_file() {
    #ifdef THEMIS
        freopen(INP ".inp","r",stdin);
        freopen(OUT ".out","w",stdout);
    #endif // THEMIS
}

const int maxN = 5e3 + 10;

typedef array<int, 3> ar3;
typedef pair<long long, ar3> i2;
vector<ar3> adj[maxN];

void sol() {
    int n, m, k1, k2;
    cin >> n >> m >> k1 >> k2;
    for (int i = 1; i <= m; i++) {
        int u, v, w, c;
        cin >> u >> v >> w >> c;
        adj[u].push_back({v, w, c});
        adj[v].push_back({u, w, c});
    }

    auto dijkstra = [&](int s, vector<vector<vector<long long> > > &dist) {
        priority_queue<i2, vector<i2>, greater<i2> > Q;
        dist[s][0][0] = 0;
        Q.push({0, {s, 0, 0}});
        while ((int)Q.size() != 0) {
            i2 A = Q.top(); Q.pop();
            long long du = A.first;
            int u = A.second[0];
            int x = A.second[1];
            int y = A.second[2];
            if (du != dist[u][x][y]) continue;
            for (auto [v, w, c] : adj[u]) {
                if (c == 0) {
                    if (dist[v][x][y] > du + w) {
                        dist[v][x][y] = du + w;
                        Q.push({du + w, {v, x, y}});
                    }
                }
                if (c == 1) {
                    if (x < k1 && dist[v][x + 1][y] > du + w) {
                        dist[v][x + 1][y] = du + w;
                        Q.push({du + w, {v, x + 1, y}});
                    }
                }
                if (c == 2) {
                    if (y < k2 && dist[v][x][y + 1] > du + w) {
                        dist[v][x][y + 1] = du + w;
                        Q.push({du + w, {v, x, y + 1}});
                    }
                }
            }
        }
    };
    vector<vector<vector<long long> > > dist(n + 1, vector<vector<long long> > (k1 + 1, vector<long long>(k2 + 2, INF_LL)));
    vector<vector<vector<long long> > > dist2 = dist;
    int s, t;
    cin >> s >> t;
    dijkstra(s, dist);
    dijkstra(t, dist2);
    long long res = INF_LL;
    for (int u = 0; u <= k1; u++) {
        for (int v = 0; v <= k2; v++) {
            res = min(res, dist[t][u][v] + dist2[t][k1 - u][k2 - v]);
        }
    }
    if (res == INF_LL) cout << -1;
    else cout << res;
}

void solve() {
    int T;
    //cin >> T;
    T = 1;
    int TestCase = 0;
    while (T--) {
        TestCase += 1;
        //cout << "Case #" << TestCase << ":" << ' ';
        ///cout << "Case #" << TestCase << '\n';
        sol();
    }
}
int main(int argc,char *argv[]) {
    //srand(time(nullptr));
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    open_file();
    solve();
}
