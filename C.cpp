#include <bits/stdc++.h>
using namespace std;

long long a[600000];

void solve(int n, long long sum) {
    sort(a, a + 2 * n - 1);

    long long answer = 0, fail_count = 0;
    long long first_possible_sum = a[0] + a[2 * n - 3];
    answer = first_possible_sum - a[2 * n - 2];
    for (int i = 1; i < n - 1; i++) {
        if (a[i] + a[2 * n - 3 - i] != first_possible_sum) {
            fail_count++;
        }
    }
    
    if (answer < 1 || fail_count > 0) {
        long long second_possible_sum = a[0] + a[2 * n - 2];
        answer = second_possible_sum * n - sum, fail_count = 0;
        vector <long long> v;
        v.push_back(answer);
        for (int i = 0; i < 2 * n - 1; i++) {
            v.push_back(a[i]);
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++) {
            if (v[i] + v[2 * n - 1 - i] != second_possible_sum) {
                fail_count++;
            }
        }

        if (answer < 1 || fail_count > 0) {
            long long third_possible_sum = a[1] + a[2 * n - 2];
            answer = third_possible_sum - a[0], fail_count = 0;
            for (int i = 2; i < n; i++) {
                if (a[i] + a[2 * n - 1 - i] != third_possible_sum) {
                    fail_count++;
                }
            }

            if (answer < 1 || fail_count > 0) {
                cout << -1 << endl;
                return;
            }
        }

    }
    cout << answer << endl;
}

int main(void) {
    freopen("C_in.txt", "r", stdin);
    freopen("C_out.txt", "w", stdout);
    int t, n;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> n;
        long long sum = 0;
        for (int j = 0; j < 2 * n - 1; j++) {
            cin >> a[j];
            sum += a[j];
        }
        cout << "Case #" << i << ": ";
        if (n == 1) {
            cout << 1 << endl;
        }
        else {
            solve(n, sum);
        }
    }
}