#include <bits/stdc++.h>
using namespace std;

char g[21][21];
bool vis[21][21];
set < pair<int,int> > s;
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void visit(int r, int c) {
    vis[r][c] = true;

    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (g[nr][nc] == '.') s.insert(make_pair(nr, nc));
    }

    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (g[nr][nc] == 'W' && !vis[nr][nc]) visit(nr, nc);
    }
}

void solve() {
    memset(vis, 0, sizeof vis);
    memset(g, 0, sizeof g);

    int r, c;
    cin >> r >> c;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> g[i][j];
        }
    }

    bool can = false;

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (g[i][j] == 'W' && !vis[i][j]) {
                visit(i, j);

                if (s.size() == 1) can = true;
                s.clear();
            }
        }
    }

    if (can) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main(void) {
    freopen("A1_in.txt", "r", stdin);
    freopen("A1_out.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}