#include <iostream>
#include <limits.h>
#include <climits>
#include <utility>
#include <fstream>
#include <string>
#include <string.h>
#include <functional>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>

typedef long long ll;
using namespace std;

int isPossible_squred(const int &time, const vector<int> &Pancakes, const int squred){
	priority_queue<int> pq;
	int ret = INT_MAX;
	int num_split = 0;
	for (int i = 0; i < Pancakes.size(); i++)
		pq.push(Pancakes[i]);
	for (int i = 0; i < time; i++){
		int mmax = pq.top();
		pq.pop();
		ret = min(mmax + num_split, ret);
		if (mmax == 9){
			pq.push(3);
			pq.push(3);
			pq.push(3);
			num_split++;
		}
		else if (mmax % 2 == 0){
			pq.push(mmax / 2);
			pq.push(mmax / 2);
		}
		else{
			if (mmax / 2 == 0) break;

			pq.push(mmax / 2);
			pq.push((mmax / 2) + 1);
		}
		num_split++;
	}
	if (ret > time)
		return -1;
	else
		return ret;
}

int isPossible(const int &time, const vector<int> &Pancakes){
	priority_queue<int> pq;
	int ret = INT_MAX;
	for (int i = 0; i < Pancakes.size(); i++)
		pq.push(Pancakes[i]);
	for (int i = 0; i < time; i++){
		int mmax = pq.top();
		pq.pop();
		ret = min(mmax + i, ret);
		if (mmax % 2 == 0){
			pq.push(mmax / 2);
			pq.push(mmax / 2);
		}
		else{
			if (mmax / 2 == 0) break;

			pq.push(mmax / 2);
			pq.push((mmax / 2) + 1);
		}
	}
	if (ret > time)
		return -1;
	else
		return ret;
}

int main(){
	int t;
	int caseNumber = 0;
	cin >> t;
	while (t--){
		int n;
		int left = 1;
		int right = INT_MIN;
		int ans;
		cin >> n;
		vector<int> Pancakes(n);
		for (int i = 0; i < n; i++){
			cin >> Pancakes[i];
			right = max(right, Pancakes[i]);
		}
		ans = right;
		for(int i = 1; i<=right; i++){
			int t1 = isPossible_squred(i, Pancakes, ans);
			int t2 = isPossible(i, Pancakes);
			if (t1 != -1){
				ans = i;
				break;
			}
			if (t2 != -1){
				ans = i;
				break;
			}

		}
		printf("Case #%d: %d\n", ++caseNumber, ans);

	}
}