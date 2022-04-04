#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >>n;
    long long answer = 0;
    vector<int> a(100, 0);
    for (int i = 0; i<n; i++) {
            cin >>a[i];
            answer += a[i]*a[i];
    }
    answer -= a[n-1]*a[n-1] - 2*a[n-2];
    cout <<answer;
    return 0;
}