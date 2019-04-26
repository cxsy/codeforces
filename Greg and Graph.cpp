#include <iostream>
#include <vector>
using namespace std;

const int NMAX = 505;
int graph[NMAX][NMAX];
int del[NMAX];
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for (int r = 1; r <= n; r++)
    {
        for (int c = 1; c <= n; c++)
        {
            cin >> graph[r][c];
        }
    }
    for (int i = 0; i < n; i++)
    {
        cin >> del[i];
    }
    vector<int> ans(n);
    for (int d = n - 1; d >= 0; d--)
    {
        int k = del[d];
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (graph[i][k] + graph[k][j] < graph[i][j])
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
        int sum = 0;
        for (int p = d; p < n; p++)
        {
            for (int q = d; q < n; q++)
            {
                sum += graph[p][q];
            }
        }
        ans.push_back(sum);
    }
    while (ans.size() > 0)
    {
        cout << ans.back();
        cout << (ans.size() == 1 ? "\n" : " ");
        ans.pop_back();
    }
    return 0;
}
