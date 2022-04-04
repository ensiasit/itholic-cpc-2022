#include<iostream>
#include<bits/stdc++.h>

using namespace std;

long double Q(int x, int y, int z) {
    long double res = 1.0*(x*y + x*z + y*z);
    return res;
}

int a, b, c;
long double p, q, r;

vector<vector<vector<long double>>> proba(107,
    vector<vector<long double>>(107,
        vector<long double>(107,
            -1)));


long double solve(int x, int y, int z) {
    if (proba[x][y][z] != -1)
        return proba[x][y][z];
    long double probability = 0;
    if (x < a) {
        if (y != 0)
            probability += ((1-p)*(1.0*(x+1)*y)/Q(x+1, y, z))*solve(x+1, y, z);
        if (z != 0)
            probability += (r*(1.0*(x+1)*z)/Q(x+1, y, z))*solve(x+1, y, z);
    }
    if (y < b) {
        if (x != 0)
            probability += (p*(1.0*(y+1)*x)/Q(x, y+1, z))*solve(x, y+1, z);
        if (z != 0)
            probability += ((1-q)*(1.0*(y+1)*z)/Q(x, y+1, z))*solve(x, y+1, z);
    }
    if (z < c) {
        if (x != 0)
            probability += ((1-r)*(1.0*(z+1)*x)/Q(x, y, z+1))*solve(x, y, z+1);
        if (y != 0)
            probability += (q*(1.0*(z+1)*y)/Q(x, y, z+1))*solve(x, y, z+1);
    }
    proba[x][y][z] = probability;
    return probability;
}

int main() {
    cin >>a;
    cin >>b;
    cin >>c;
    cin >>p;
    cin >>q;
    cin >>r;
    proba[a][b][c] = 1;
    proba[0][0][0] = 0;
    long double pa = 0;
    long double pb = 0;
    long double pc = 0;
    for (int i=1; i<=a; i++)
        pa += solve(i, 0, 0);
    for (int i=1; i<=b; i++)
        pb += solve(0, i, 0);
    for (int i=1; i<=c; i++)
        pc += solve(0, 0, i);
    printf("%.15Lf %.15Lf %.15Lf", pa, pb, pc);
    return 0;
}