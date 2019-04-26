#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool dp[2][2];
int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 1; i < n; i++)
    {
        if ((s[i - 1] == 'A' && s[i] == 'B' && dp[0][1]) || (s[i - 1] == 'B' && s[i] == 'A' && dp[0][0]))
        {
            cout << "YES\n";
            return 0;
        }
        dp[0][0] = dp[1][0] || (i >= 2 && s[i - 2] == 'A' && s[i - 1] == 'B');
        dp[0][1] = dp[1][1] || (i >= 2 && s[i - 2] == 'B' && s[i - 1] == 'A');
        dp[1][0] = dp[1][0] || (s[i - 1] == 'A' && s[i] == 'B');
        dp[1][1] = dp[1][1] || (s[i - 1] == 'B' && s[i] == 'A');
    }
    cout << "NO\n";
    return 0;
}