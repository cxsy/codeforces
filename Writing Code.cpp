#include <iostream>
using namespace std;
const int NMAX = 505;
const int MMAX = 505;
const int BMAX = 505;
int bugs[NMAX], dp[MMAX][BMAX];
int main(int argc, char const *argv[])
{
    int n, m, b, mod;
    cin >> n >> m >> b >> mod;
    for (int i = 0; i < n; i++)
    {
        cin >> bugs[i];
    }
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; (1 << k) <= m; k++)
        {
            int ln = 1 << k;
            int bn = ln * bugs[i];
            for (int cl = m; cl >= ln; cl--)
            {
                for (int cb = b; cb >= bn; cb--)
                {
                    dp[cl][cb] = (dp[cl][cb] + dp[cl - ln][cb - bn]) % mod;
                }
            }
        }
    }
    int ans = 0;
    for (int bn = 0; bn <= b; bn++)
    {
        ans = (ans + dp[m][bn]) % mod;
    }
    cout << ans << "\n";
    return 0;
}
