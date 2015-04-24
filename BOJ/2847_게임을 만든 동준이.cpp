#include <iostream>
#include <utility>
#include <limits.h>
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


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	ll ans = 0;

	cin >> n;
	vector<int> score(n);


	for (int i = 0; i < n; i++)
		cin >> score[i];

	for (int i = 1; i < n; i++){
		for (int j = i; j >= 1; j--){
			if (score[j - 1] >= score[j]){
				ans += (score[j - 1] - (score[j] - 1));
				score[j - 1] = score[j] - 1;
			}
			else
				break;
		}
	}
	cout << ans << endl;

}