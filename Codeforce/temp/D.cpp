#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits.h>
#include <functional>
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

int n, m, test;
int ans = 0;
int dp[10][2];
vector<int> num;
vector<int> bad_prime;


int GCD(int a, int b){
	int temp = a % b;
	while (temp){
		a = b;
		b = a;
		temp = a % b;
	}
	return b;
}


int isPossible(int idx){
	int gcd = num[0];
	for (int i = 1; i < idx; i++)
		gcd = GCD(gcd, idx);
	return gcd;
}


int get_beauty(int idx){
	int beauty = 0;
	int bad = 0;
	int gcd = isPossible(idx);
	vector<int> vi = num;
	for (int i = 0; i < idx; i++)
		vi[i] /= gcd;
	for (int i = 0; i<n; i++){
		int temp = vi[i];
		for (int j = 2; j <=temp; j++){
			while (temp % j == 0){
				temp /= j;
				if (binary_search(bad_prime.begin(), bad_prime.end(), j))
					bad++;
				else
					beauty++;
			}
		}
		if (temp != 1){
			if (binary_search(bad_prime.begin(), bad_prime.end(), temp))
				bad++;
			else
				beauty++;
		}
	}
	return beauty - bad;
}

void sol(int pos, int c){
	if (pos == n) return;
	int a = get_beauty(pos);
	cout << pos << " " << c << " " << a << endl;
	if (a > ans) ans = a;

	for (int i = pos; i < n; i++){
		int gcd = isPossible(i);
		if (gcd != 1){
			sol(i + 1, 1);
		}
		sol(i + 1, 0);
	}
}


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	cin >> n >> m;
	num = vector<int>(n);
	bad_prime = vector<int>(m);
	for (int i = 0; i < n; i++) 	cin >> num[i];	
	for (int i = 0; i < m; i++) 	cin >> bad_prime[i];
	sol(0, 0);
	cout << ans << endl;
}