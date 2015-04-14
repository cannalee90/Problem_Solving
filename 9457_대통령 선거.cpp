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

bool print_max(const vector<int> &arr, int n, int a){
	for (int i = 1; i < arr.size(); i++){
		if (arr[i] > n / 2){
			cout << i << " " << a << endl;
			return true;
		}
	}
	return false;
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	while (t--){
		int n, m;
		cin >> n >> m;
		vector<int> candidate(n + 1, 0);
		vector<vector<int> > prefer(m + 1,vector<int>(n,0));
		vector<int> count(n + 1, 0);

		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				cin >> prefer[i][j];

		for (int i = 0; i < m; i++)
			count[prefer[i][0]]++;

		int first_m = - 1, first_p = -1, second_p = -1, second_m = -1;
		
		for (int i = 1; i <=n; i++){
			if (first_m < count[i]){
				first_p = i;
				first_m = count[i];
			}
		}

		for (int i = 1; i <= n; i++){
			if (second_m < count[i] && first_p != i){
				second_p = i;
				second_m = count[i];
			}
		}

		if (print_max(count, m, 1)) continue;
		count.clear();
		count.resize(n + 1, 0);

		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				int vote = prefer[i][j];
				if (vote == first_p || vote == second_p){
					count[vote]++;
					break;
				}
			}
		}

		print_max(count, m, 2);
	}
}