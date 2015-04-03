#include<cstdio>
#include<vector>
#include<functional>
#include<algorithm>

typedef long long ll;
using namespace std;

long long n;


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int t;
	scanf("%d", &t);
	while (t--){
		int n, m;
		int ans = INT_MIN;
		scanf("%d %d", &n, &m);
		vector<vector<int> > data(n + 1, vector<int>(m + 1, 0));
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				scanf("%d", &data[i][j]);
				data[i][j] += data[i - 1][j] + data[i][j - 1] - data[i - 1][j - 1];
			}
		}

		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				int rows = i, columns = j;
				while (rows && columns){
					int sum = data[i][j] + data[rows - 1][columns - 1] - data[i][columns - 1] - data[rows - 1][j];
					ans = max(ans, sum);
					rows--;
					columns--;
				}
			}
		}
		printf("%d\n", ans);
	}
}