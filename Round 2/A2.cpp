#include <bits/stdc++.h>
using namespace std;

char g[3100][3100];
bool vis[3100][3100];
set < pair<int,int> > s;
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
map < pair<int,int>, int> mp;
int siz;

void visit(int r, int c) {
    siz++;
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
    mp.clear();

    int r, c;
    cin >> r >> c;

    for (int i = 0; i <= r + 1; i++) {
        for (int j = 0; j <= c + 1; j++) {
            g[i][j] = ' ';
            vis[i][j] = 0;
        }
    }

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> g[i][j];
        }
    }

    int ans = 0;

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (g[i][j] == 'W' && !vis[i][j]) {
                visit(i, j);

                if (s.size() == 1) {
                    pair <int,int> place = *s.begin();
                    mp[place] += siz;
                    ans = max(ans, mp[place]);
                }
                s.clear();
                siz = 0;
            }
        }
    }

    cout << ans << endl;
}

int main(void) {
    freopen("A2_in.txt", "r", stdin);
    freopen("A2_out.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}