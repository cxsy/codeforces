#include <iostream>
using namespace std;

const int mod = 1e8;
const int NMAX = 105;
const int KMAX = 15;

int dp[NMAX][2][KMAX];
int main(int argc, char const *argv[])
{
    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;
    dp[1][0][1] = 1;
    dp[0][1][1] = 1;
    for (int i = 2; i <= n1 + n2; i++)
    {
        int tmp[NMAX][2][KMAX] = {};
        for (int f = 0; f <= min(i - 1, n1); f++)
        {
            for (int se = 1; se <= min(f, k1); se++)
            {
                if (se < k1 && f < n1)
                {
                    tmp[f + 1][0][se + 1] = dp[f][0][se];
                }
                tmp[f][1][1] = (tmp[f][1][1] + dp[f][0][se]) % mod;
            }
            for (int se = 1; se <= min(i - 1 - f, k2); se++)
            {
                tmp[f + 1][0][1] = (tmp[f + 1][0][1] + dp[f][1][se]) % mod;
                if (se < k2)
                {
                    tmp[f][1][se + 1] = dp[f][1][se];
                }
            }
        }
        copy(&tmp[0][0][0], &tmp[0][0][0] + NMAX * 2 * KMAX, &dp[0][0][0]);
    }
    int ans = 0;
    for (int i = 1; i <= k1; i++)
    {
        ans = (ans + dp[n1][0][i]) % mod;
    }
    for (int i = 1; i <= k2; i++)
    {
        ans = (ans + dp[n1][1][i]) % mod;
    }
    cout << ans << "\n";
    return 0;
}