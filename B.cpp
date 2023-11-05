#include <bits/stdc++.h>
using namespace std;

void solve(int r, int c, int a, int b) {
    if (r > c) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}

int main(void) {
    freopen("B_in.txt", "r", stdin);
    freopen("B_out.txt", "w", stdout);
    int t;
    int r, c, a, b;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> r >> c >> a >> b;
        cout << "Case #" << i << ": ";
        solve(r, c, a, b);
    }
}