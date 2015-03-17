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
	int n;
	vector<bool> P;
	vector<int> Prime;
public:
	Sieve(int n){
		P.resize(n + 1, true);
		this->n = n;
		for (int i = 2; i<= n; i++){
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


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	const int limit = 1000000;
	Sieve sieve(limit);
	vector<int>Prime = sieve.get_prime();

	while (true){
		int n;
		cin >> n;
		if (!n)
			return 0;
		for (int i = 0; i < n; i++){
			int number = Prime[i];
			if (number > n / 2){
				cout << "Goldbach's conjecture is wrong" << endl;
				break;
			}
			vector<int>::iterator itor = lower_bound(Prime.begin(), Prime.end(), n - number);
			if (*itor == n - number){
				printf("%d = %d + %d\n", n, number, *itor);
				break;
			}
		}
	}
}
