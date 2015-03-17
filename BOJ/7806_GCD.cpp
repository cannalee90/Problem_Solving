#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
 
#define INF
const long long  hash_value =  1000000000000000007;
                                
 
typedef long long ll;
using namespace std;
 
const int MAX = 1000000000;
 
 
int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
    int n, m;
    vector<int> PP;
	vector<bool> P(sqrt(MAX * 1.0) + 2);
    for(int i =2; i<=sqrt(MAX * 1.0) + 1; i++)
    {
        if(!P[i])
        {
            PP.push_back(i);
            for(int j = i; j<=sqrt(MAX * 0.1) + 1; j+=i)
            {
                P[j] = 1;
            }
        }
    }
    while(cin>> n >> m)
    {
		if(n == 0){ printf("1\n"); continue;}
        vector<pair<int, int>> Prime_factor;
        for(int i = 0; i<PP.size(); i++)
        {
            if(sqrt(m * 1.0) < PP[i]) break;
            if(m % PP[i] == 0)
            {
                Prime_factor.push_back(make_pair(PP[i], 0));
                while(m % PP[i] == 0)
                {
                    Prime_factor[Prime_factor.size() -1].second++;
                    m /= PP[i];
                }
            }
        }
        if(m != 1)
        {  
            Prime_factor.push_back(make_pair(m, 1));
        }
        vector<int> Prime_factor_1(Prime_factor.size() + 1);
        for(int j = 0; j<Prime_factor.size(); j++)
        {
            int idx = 1;
            while(n / (int)pow(Prime_factor[j].first * 1.0, idx) )
            {
                Prime_factor_1[j]+=n / (int)pow(Prime_factor[j].first * 1.0, idx) ;
                idx++;
            }
        }
        int ans = 1;
        for(int i = 0; i< Prime_factor.size(); i++)
        {
            if(Prime_factor[i].second != 0 && Prime_factor_1[i] != 0)
            {
                int factor = Prime_factor[i].first;
                ans *=  pow(factor * 1.0,   min(Prime_factor[i].second ,  Prime_factor_1[i]));
            }
        }
        printf("%d\n", ans);
    }
}