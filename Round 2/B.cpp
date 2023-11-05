#include <bits/stdc++.h>
using namespace std;

long long a[2000005];
long long b[2000005];
long long all[8000005];

void solve(int round)
{
    int n;
    cin >> n;

    long long sum = 0;
    long long cur = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        cur += a[i];
        all[i] = a[i];
        all[2 * n + i] = a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        sum += b[i];
        all[i + n] = b[i];
        all [3 * n + i] = b[i];
    }

    cout << "Case #" << round << ": ";

    if (sum % 2 == 1)
    {
        cout << -1 << endl;
        return;
    }

    long long avg = sum / 2;

    if (cur == avg)
    {
        int i = n - 1;
        bool failed = false;

        for (int j = 0; j < n; j++)
        {
            if (all[i - j] != all[i + 1 + j])
            {
                failed = true;
                break;
            }
        }

        if (!failed)
        {
            int mode;
            if (all[i] > all[i - n + 1]) {
                for (int j = 0; j < n / 2; j++)
                {
                    if (all[i - j] <= all[i - n + 1 + j])
                    {
                        failed = true;
                        break;
                    }
                }
            }
            else {
                failed = true;
            }

            if (!failed)
            {
                cout << i - n + 1 << endl;
                return;
            }
        }
    }

    for (int i = n; i < 3 * n; i++)
    {
        cur -= all[i - n];
        cur += all[i];
        if (cur == avg)
        {
            bool failed = false;

            for (int j = 0; j < n; j++)
            {
                if (all[i - j] != all[i + 1 + j])
                {
                    failed = true;
                    break;
                }
            }

            if (!failed)
            {
                if (all[i] > all[i - n + 1])
                {
                    for (int j = 0; j < n / 2; j++)
                    {
                        if (all[i - j] <= all[i - n + 1 + j])
                        {
                            failed = true;
                            break;
                        }
                    }
                }
                else
                {
                    failed = true;
                    continue;
                }

                if (!failed)
                {
                    cout << i - n + 1 << endl;
                    return;
                }
            }
        }
    }
    cout << -1 << endl;
}

int main(void)
{
    freopen("B_in.txt", "r", stdin);
    freopen("B_out.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve(i);
    }
}