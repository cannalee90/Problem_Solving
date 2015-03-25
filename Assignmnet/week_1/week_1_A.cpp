#include <iostream>
#include <utility>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include<limits.h>

#include <set>
#include <map>
#include <vector>
#include <stack>

typedef long long ll;

using namespace std;


int main(){
	int test;
	scanf("%d", &test);
	while (test--){
		int n;
		scanf("%d", &n);
		long long people_in_bus = 0;
		long long ans = INT_MIN;
		for (int i = 0; i < n; i++){
			int get_in;
			int get_out;
			scanf("%d %d", &get_out, &get_in);
			people_in_bus += get_in - get_out;
			ans = max(people_in_bus, ans);
		}
		printf("%lld\n", ans);
	}
}
