#include <iostream>
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

class Sieve{
	int n;
	vector<bool> P;
	vector<int> Prime;
public:
	Sieve(int n){
		P.resize(n + 1, true);
		this->n = n;
		for (int i = 2; i <= n; i++){
			if (P[i]){
				Prime.push_back(i);
				for (int j = i; j <= n; j += i){
					P[j] = false;
				}
			}
		}
	}
	int size(){
		return Prime.size();
	}
	vector<int> get_prime(){
		return Prime;
	}
};

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n, m;
	const int limit = 1000000;
	Sieve sieve(limit);
	vector<int> Prime = sieve.get_prime();
	
	cin >> n >> m;
	int ans = 0;
	for (int i = n; i <=m; i++){
		int number = i;
		int L = sqrt((double)number);
		int prime_count = 0;
		for (int j = 0; Prime[j] <= L; j++){
			while(number % Prime[j] == 0){
				number = number / Prime[j];
				prime_count ++ ;
				L = sqrt((double)number);
			}
		}
		if (number != 1) 
			prime_count++;
		if (binary_search(Prime.begin(), Prime.end(), prime_count))
			ans++;
	}
	cout << ans << endl;
}
