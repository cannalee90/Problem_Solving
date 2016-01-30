//
// Created by  이강호 on 2016. 1. 31..
//

#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include <cstring>
#include <deque>
#include <queue>
#include <tuple>

using namespace std;

int n, m;

struct person {
    string name;
    int kor, eng, math;
};

int main() {
    freopen("/Users/kangho/Documents/Problem_Solving/input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<person> people(n);
    for(int i = 0;i < n; i++) {
        cin >> people[i].name >> people[i].kor >> people[i].eng >> people[i].math;
    }
    sort(people.begin(), people.end(), [](const person &a, const person &b){
        return make_tuple(-a.kor, a.eng, -a.math, a.name) < make_tuple(-b.kor, b.eng, -b.math, b.name);
    });
    for(auto person : people) {
        cout << person.name << endl;
    }
}

