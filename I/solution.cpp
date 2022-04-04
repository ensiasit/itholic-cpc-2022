#include<iostream>
#include<bits/stdc++.h>

//Mohamed Nasser
//original : https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1150

using namespace std;
#define PI 3.14159265358979323846264

long double* solve(long double a) {
    long double* ans;
    ans = (long double*)malloc(3*sizeof(long double));
    long double sq = pow(a, 2);
    ans[0] = 4*sq*(1 - (PI/6) - (sqrt(3)/4));
    ans[1] = 4*sq*(-1 + (PI/12) + (sqrt(3)/2));
    ans[2] = sq - ans[0] - ans[1];
    return ans;
}

int main() {
    long double a;
    cin >>a;
    long double* answer = solve(a); 
    cout <<setprecision(15) <<answer[0] <<" " <<answer[1] <<" "<<answer[2] <<'\n';
    return 0;
}
