#include <iostream>
#include <climits>
#include <utility>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>

typedef long long ll;
using namespace std;

inline bool isPossible(int length, vector<ll> &cutting, ll &k){
	int point = 0;
	int life = length;
	int cnt = 0;
	for (int i = 1; i < cutting.size();){
		if ((point + life) - cutting[i] >= 0){
			life -= cutting[i] - point;
			point = cutting[i];
			i++;
		}
		else{
			cnt++;
			life = length;
		}
		if (cnt > k) return false;
	}
	return true;
}
inline bool isFirst(int length, vector<ll> &cutting, int &begin, ll &k){
	int point = cutting[begin];
	int life = length;
	int cnt = 0;
	for (int i = begin + 1; i < cutting.size();){
		if ((point + life) - cutting[i] >= 0){
			life -= cutting[i] - point;
			point = cutting[i];
			i++;
		}	
		else{
			cnt++;
			life = length;
		}
		if (cnt == k) return false;
	}
	return true;
}


int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	ll l, k, c;
	cin >> l >> k >> c;
	ll ans = l;
	ll left = 1;
	ll right = l;
	vector<ll> cutting(k + 1,0);
	for (int i = 1; i <= k; i++)
		scanf("%d", &cutting[i]);
	cutting.push_back(l);
	sort(cutting.begin(), cutting.end());
	while (left <= right){
		ll length = (left + right) / 2;
		if (isPossible(length, cutting, c)){
			right = length - 1;
			ans = min(length, ans);
		}
		else
			left = length + 1;
	}
	for (int i = 1; i < cutting.size(); i++){
		if (isFirst(ans, cutting, i, c)){
			cout << ans << " " << cutting[i] << endl;
			return 0;
		}
	}
}