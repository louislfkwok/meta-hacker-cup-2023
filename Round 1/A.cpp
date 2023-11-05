#include <bits/stdc++.h>
using namespace std;

long long x[100005];

void solve(int Case) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    sort(x, x + n);

    double start = (double) (x[0] + x[1]) / 2;
    double end = (double) (x[n - 2] + x[n - 1]) / 2;
    double answer = end - start;

    if (n == 5) {
        start = (double) (x[0] + x[2]) / 2;
        end = (double) (x[3] + x[4]) / 2;
        answer = end - start;

        start = (double) (x[0] + x[1]) / 2;
        end = (double) (x[2] + x[4]) / 2;
        answer = max(answer, end - start);
    }

    cout << fixed << "Case #" << Case << ": " << answer << endl;
}

int main(void) {
    freopen("A_in.txt", "r", stdin);
    freopen("A_out.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}