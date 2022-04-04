/**
 * @file D.cpp
 * @author Hamza Ben Yazid
 * @originalProblem https://codeforces.com/problemset/problem/550/B
 */

#include <bits/stdc++.h>
#define N 15
#define INF 10e6+7
using namespace std;

int main(){
    int n,l,r,x;
    cin>>n>>l>>r>>x;
    vector<int> c = vector<int>(n,0);
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    bitset<N> problemset ;
    int ways = 0;
    int someDiff;
    int maxDiff;
    int minDiff;
    while(problemset.count()<=n){
        someDiff = 0;
        maxDiff = 0;
        minDiff = INF;
        for(int i=0;i<N;i++){
            if(problemset[i]){
                someDiff+=c[i];
                maxDiff=max(maxDiff,c[i]);
                minDiff=min(minDiff,c[i]);
            }
        }
        if(maxDiff-minDiff>=x && someDiff>=l && someDiff<=r){
            ways++;
        }
        if(problemset.count()==n){
            break;
        }
        //incrementing the bitset
        problemset = bitset<N>(problemset.to_ulong()+1ULL);
    }
    cout<<ways;
    return 0;
}

