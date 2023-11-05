#include <bits/stdc++.h>
using namespace std;

void solve(int Case) {
    vector <int> prime_factors;
    int p;
    cin >> p;
    int num = p;
    for (int i = 2; i <= sqrt(p); i++) {
        if (p % i == 0) {
            prime_factors.push_back(i);
            p /= i;
            i--;
        }
    }
    prime_factors.push_back(p);

    int sum = 0;
    for (int i = 0; i < prime_factors.size(); i++) {
        sum += prime_factors[i];
    }

    cout << "Case #" << Case << ": ";
    if (sum > 41) {
        cout << -1 << endl;
    }
    else if (num < 41) {
        if (1 + 41 - num > 100) {
            cout << -1 << endl;
            return;
        }
        cout << 41 - num + 1;
        for (int i = 0; i < 41 - num; i++) {
            cout << ' ' << 1;
        }
        cout << ' ' << num << endl;
    }
    else if (sum == 41) {
        cout << prime_factors.size();
        for (int i = 0; i < prime_factors.size(); i++) {
            cout << ' ' << prime_factors[i];
        }
        cout << endl;
    }
    else {
        for (int i = 0; i < 41 - sum; i++) {
            prime_factors.push_back(1);
        }
        cout << prime_factors.size();
        for (int i = 0; i < prime_factors.size(); i++) {
            cout << ' ' << prime_factors[i];
        }
        cout << endl;
    }
}

int main(void) {
    freopen("B1_in.txt", "r", stdin);
    freopen("B1_out.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}