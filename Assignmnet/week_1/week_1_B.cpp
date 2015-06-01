#include <cstdio>
#include <algorithm>
#include <vector>

typedef long long ll;
using namespace std;

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	const int limit =12000001;
	int n;

	vector<int> Prime;
	vector<bool> P(limit + 10, true);
	for (int i = 2; i <= limit; i++){
		if (P[i]){
			Prime.push_back(i);
			for (int j = i; j <= limit; j += i){
				P[j] = false;
			}
		}
	}

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int t;
		scanf("%d", &t);
		vector<int>::iterator itor = lower_bound(Prime.begin(), Prime.end(), t);
		printf("%d\n", itor - Prime.begin());
	}
}
