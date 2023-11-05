#include <bits/stdc++.h>
using namespace std;

int parent[1000005];
int children[1000005];
set <string> v[1000005];
set <string> s;
bool vis[1000005];
bool found = false;

void search(int node, string topic) {
    vis[node] = true;
    if (v[node].count(topic) == 0) {
        if (!vis[parent[node]]) {
            search(parent[node], topic);
        }
    }
    else {
        found = true;
        return;
    }
}

void solve() {
    int n, m;
    string topic;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        cin >> parent[i];
        children[parent[i]]++;
    }
    vector <int> childless;
    for (int i = 1; i <= n; i++) {
        if (children[i] == 0) {
            childless.push_back(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        cin >> m;
        for (int j = 0; j < m; j++) {
            cin >> topic;
            v[i].insert(topic);
            s.insert(topic);
        }
    }
    int ans = 0;
    for (auto it = s.begin(); it != s.end(); it++) {
        bool failed = false;
        for (int i = 1; i <= n; i++) {
            vis[i] = false;
        }
        for (int i = 0; i < childless.size(); i++) {
            found = false;
            search(childless[i], *it);
            if (!found) {
                failed = true;
                break;
            }
        }
        if (!failed) {
            ans++;
        }
    }
    cout << ans << endl;

    for (int i = 1; i <= n; i++) v[i].clear();
    s.clear();
    for (int i = 1; i <= n; i++) {
        children[i] = 0;
    }
}

int main(void) {
    freopen("C_in.txt", "r", stdin);
    freopen("C_out.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}