#include <bits/stdc++.h>
using namespace std;

void solve(int s, int d, int k) {
    int buns = s * 2 + d * 2;
    int cheese = s + d * 2;
    int patties = s + d * 2;

    int buns_required = k + 1;
    int cheese_required = k;
    int patties_required = k;

    if (buns >= buns_required && cheese >= cheese_required && patties >= patties_required) {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
}

int main(void) {
    freopen("A1_in.txt", "r", stdin);
    freopen("A1_out.txt", "w", stdout);
    int t, s, d, k;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> s >> d >> k;
        cout << "Case #" << i << ": ";
        solve(s, d, k);
    }
}