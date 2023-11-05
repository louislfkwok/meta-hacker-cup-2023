#include <bits/stdc++.h>
using namespace std;

void solve(long long a, long long b, long long c) {
    double single_deck_cost = (double) a;
    double double_deck_cost = (double) b / 2;
    long long k = 0;

    if (single_deck_cost <= double_deck_cost) {
        k = c / a;
    }
    else {
        k = c / b * 2;
        c -= c / b * b;
        
        if (c >= a) {
            k += c / a;
            c -= c / a * a;
        }
        else {
            if (b < a) {
                k--;
            }
            else {
                k -= 2;
                c += b;
                k += c / a;
            }
        }

    }

    if (k < 0) {
        k = 0;
    }

    cout << k << endl;
}

int main(void) {
    freopen("A2_in.txt", "r", stdin);
    freopen("A2_out.txt", "w", stdout);
    int t;
    long long a, b, c;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> a >> b >> c;
        cout << "Case #" << i << ": ";
        solve(a, b, c);
    }
}