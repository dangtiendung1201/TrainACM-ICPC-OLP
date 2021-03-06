#pragma GCC diagnostic ignored "-Wunused-parameter"

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
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

void open_file() {
    #ifdef THEMIS
        freopen(INP ".inp","r",stdin);
        freopen(OUT ".out","w",stdout);
    #endif // THEMIS
}

const int maxN = 1e6 + 10;

string s[maxN];
int First[maxN], Last[maxN];
void sol() {
    cin >> s[0];
    int n;
    cin >> n;
    vector<string> canChoose;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        First[s[i][0] - 'a']++;
        if (s[i][0] == s[0].back()) canChoose.push_back(s[i]);
    }
    if ((int)canChoose.size() == 0) {
        cout << "?";
        return;
    }
    for (string s : canChoose) {
        First[s[0] - 'a']--;
        if (First[s.back() - 'a'] == 0) {
            cout << s << "!";
            return;
        }
        First[s[0] - 'a']++;
    }
    cout << canChoose[0];
}

void solve() {
    int T;
    ///cin >> T;
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
