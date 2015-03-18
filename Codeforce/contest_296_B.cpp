#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <limits.h>

typedef long long ll;
using namespace std;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	string a, b;
	int ans = 0;
	int n;
	cin >> n;
	cin >> a >> b;
	vector<vector<int > > checking(30, vector<int>(30, -1));
	for (int i = 0; i < n; i++){
		if (a[i] != b[i])
		{
			ans++;
			checking[a[i] - 'a'][b[i] - 'a'] = i;
		}
	}
	for (int i = 0; i < 26; i++){
		for (int j = 0; j < 26; j++){
			if (checking[i][j] != -1 && checking[j][i] != -1){
				cout << ans - 2 << endl;
				printf("%d %d\n", checking[i][j] + 1, checking[j][i] + 1);
				return 0;
			}
		}
	}
	for (int i = 0; i < 26; i++){
		for (int j = 0; j < 26; j++){
			if (checking[i][j] != -1){
				for (int k = 0; k < 26; k++){
					if (checking[j][k] != -1)
					{
						cout << ans - 1 << endl;
						printf("%d %d\n", checking[i][j] + 1, checking[j][k] + 1);
						return 0;
					}
				}
			}
		}
	}
	cout << ans << endl << "-1 -1" << endl;
}