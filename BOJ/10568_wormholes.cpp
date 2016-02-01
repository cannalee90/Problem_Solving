//
// Created by  이강호 on 2016. 2. 2..
// floyd

#include<stdio.h>
#include<iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstring>
#include <bitset>
#include <deque>
#include <queue>
#include <tuple>
#include <stack>
#include <unordered_set>
#include <map>

using namespace std;

#define INF 987654321

struct planet{
    long long  idx, x, y, z;
    double dis(const planet &b) const {
        return sqrt((x - b.x) * (x - b.x) + (y - b.y) * (y- b.y) + (z - b.z) * (z - b.z));
    }
};

int main() {
    freopen("/Users/kangho/Documents/Problem_Solving/input.txt", "r", stdin);
    int t, TC = 0;
    scanf("%d", &t);
    while(t--) {
        int n, m, q;
        scanf("%d", &n);
        vector<planet> planets;
        map<string, int> planetsIdx;
        vector<vector<double> > floyd(n, vector<double>(n, -1));
        for(int i = 0; i < n; i++) {
            string str;
            planet p;
            cin >> str >> p.x >> p.y >> p.z;
            p.idx = i;
            planetsIdx[str] = i;
            planets.push_back(p);
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                floyd[i][j] = planets[i].dis(planets[j]);

            }
        }

        scanf("%d", &m);
        for(int i = 0; i< m; i++) {
            string str1, str2;
            cin >> str1 >> str2;
            int u = planetsIdx[str1];
            int v = planetsIdx[str2];
            floyd[u][v] = 0;
        }

        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    floyd[i][j] = min(floyd[i][k] + floyd[k][j], floyd[i][j]);

                }
            }
        }
        scanf("%d", &q);
        printf("Case %d:\n",++TC);
        for(int i = 0; i< q; i++) {
            string str1, str2;
            cin >> str1 >> str2;
            int u = planetsIdx[str1];
            int v = planetsIdx[str2];
            printf("The distance from %s to %s is %.lf parsecs.\n", str1.c_str(), str2.c_str(), floyd[u][v]);
        }

    }
}
