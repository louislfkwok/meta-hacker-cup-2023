#include <bits/stdc++.h>
using namespace std;

map <int, bool> pressed;
set <int> pressed_set;

void solve(int Case) {
    int n, q, b;
    string s;
    cin >> n >> s >> q;
    for (int i = 0; i < q; i++) {
        cin >> b;
        if (pressed[b] == 0) {
            pressed_set.insert(b);
            pressed[b] = 1;
        }
        else {
            pressed_set.erase(b);
            pressed[b] = 0;
        }
    }
    for (auto it = pressed_set.begin(); it != pressed_set.end(); it++) {
        int step = *it;
        for (int j = step; j <= n; j += step) {
            if (s[j - 1] == '0') s[j - 1] = '1';
            else s[j - 1] = '0';
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '1') {
            ans++;
            for (int j = i; j <= n; j += i) {
                if (s[j - 1] == '1') s[j - 1] = '0';
                else s[j - 1] = '1';
            }
        }
    }
    cout << "Case #" << Case <<  ": " << ans << endl;
    pressed.clear();
    pressed_set.clear();
}

int main(void) {
    freopen("C1_in.txt", "r", stdin);
    freopen("C1_out.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}