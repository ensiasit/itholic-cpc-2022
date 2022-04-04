/**
 * @file J.cpp
 * @author Hamza Ben Yazid
 * @originalProblem https://codeforces.com/problemset/problem/429/B
 */
#include <bits/stdc++.h>
using namespace std;
int f[1003][1003][5][2], a[1003][1003], x, i, dx[5] = {0, 1, 1, -1, -1}, dy[5] = {0, 1, -1, -1, 1}, s, t, n, m, j, k;
int main()
{
    cin >> n >> m;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
    for (k = 1; k <= 4; k++)
        for (i = (dx[k] == 1) ? 1 : n; i >= 1 && i <= n; i += dx[k])
            for (j = (dy[k] == 1) ? 1 : m; j >= 1 && j <= m; j += dy[k])
            {
                f[i][j][k][0] = max(f[i - dx[k]][j][k][0], f[i - dx[k]][j][k][1]) + a[i - dx[k]][j];
                f[i][j][k][1] = max(f[i][j - dy[k]][k][0], f[i][j - dy[k]][k][1]) + a[i][j - dy[k]];
            }
    for (i = 2; i <= n - 1; i++)
        for (j = 2; j <= m - 1; j++)
        {
            s = max(s, f[i][j][1][0] + f[i][j][2][1] + f[i][j][3][0] + f[i][j][4][1]);
            s = max(s, f[i][j][1][1] + f[i][j][2][0] + f[i][j][3][1] + f[i][j][4][0]);
        }
    cout << s;
    return 0;
}
