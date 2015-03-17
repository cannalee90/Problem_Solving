#include <iostream>
#include <utility>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <limits.h>
#include <set>
#include <map>
#include <vector>
#include <stack>

typedef long long ll;

using namespace std;


class Sieve{
	long long n;
	vector<bool> P;
	vector<long long> Prime;
public:
	Sieve(long long n){
		P.resize(n + 1, true);
		this->n = n;
		for (long long i = 2; i <= n; i++){
			if (P[i]){
				Prime.push_back(i);
				for (long long j = i; j <= n; j += i){
					P[j] = false;
				}
			}
		}
	}
	long long size(){
		return Prime.size();
	}
	vector<long long> get_prime(){
		return Prime;
	}
};

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	long long n;
	const long long limit = 10000010;
	long long first, last;
	long long ans = 0;
	int idx = 0;
	cin >> first >> last;
	Sieve sieve(limit);
	vector<long long> Prime = sieve.get_prime();
	first = ceil(sqrt((double)first));
	vector<long long>::iterator itor = lower_bound(Prime.begin(), Prime.end(), first);
	for (int i = 0; i < Prime.size(); i++){
		if ((Prime[i] * Prime[i]) > first){
			idx = i;
			break;
		}
	}
	for (int i = ; i<Prime.size(); i++){
		long long number = (*itor);
		for (long long i = number * number; i <= last; i *= number){
			ans++;
		}
		if (number * number > last)
			break;
	}
	cout << ans << endl;
}