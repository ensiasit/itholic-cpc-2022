/**
 * @file E.cpp
 * @author Hamza Ben Yazid
 * @originalProblem https://www.spoj.com/problems/PERIOD/
 */

#include<cstdio>
#include<iostream>
#include<string>
#include<cstdlib>
#include<queue>
#include<stack>
#include<utility>
#include<string>
#include<cstring>
#include<set>
#include<cmath>
#include<vector>
#include<fstream>
#include<map>
#include<list>
#include<algorithm>

typedef long long int LLD;
typedef unsigned long long int LLU;

using namespace std;

void checkIfPeriodic(string s, int n, int pos){
	if(n == 0)
		return;
	int res = pos + 1 - n;
	if((pos + 1) % res != 0)
		return;
	printf("%d %d\n", pos + 1, (pos + 1) / res);
}

void prepareLPSArray(string pattern){
    /* Returns the length of longest suffix which is also prefix of the string.
       Since, we have appended original string to its reverse, we would be able
       to get the length of longest suffix of original string which is also a 
       palindrome. Below is the basic implementation of prefix array calculation 
       used in KMP algorithm. */

    int len = pattern.length();
    vector<int> lsp(len);
    lsp[0] = 0;
    for(int j=0, i=1;i<len;i++){
        if(pattern[i] == pattern[j]){
            lsp[i] = j + 1;
            j++;
        }
        else{
            while(true){
                if(j == 0 || pattern[j] == pattern[i])
                    break;
                j = lsp[j-1];
            }
            if(pattern[j] == pattern[i]){
                lsp[i] = j + 1;
                j++;
            }
            else
                lsp[i] = 0;
        }
        /*
        if(n == 0)
		return;
	int res = pos + 1 - n;
	if((pos + 1) % res != 0)
		return;
	printf("%d %d\n", pos + 1, (pos + 1) / res);*/
		if(lsp[i] == 0)
			continue;
		int res = i + 1 - lsp[i];
		if((i + 1) % res != 0)
			continue;
		printf("%d %d\n", i + 1, (i + 1) / res);
    }
}

int main(){
	int n;
	string s;
	cin>>n;
	cin >> s;
	prepareLPSArray(s);
    return 0;
}