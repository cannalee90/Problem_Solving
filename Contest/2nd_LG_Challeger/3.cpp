#include iostream
#include utility
#include functional
#include limits.h
#include fstream
#include string
#include string.h
#include queue
#include stdio.h
#include algorithm
#include set
#include map
#include vector
#include stack

typedef long long ll;
using namespace std;

#define INF 987654321

vectorvectorint  graph;
int n, t;
ll ans;



void solve() {

	vectorvectorint  floyd(n, vectorint(n, INF));
	vectorvectorint  temp(n, vectorint(n, INF));
	vectorvectorint  p(n, vectorint(n, -1));
	vectorvectorbool  check(n, vectorbool(n, false));
	for (int i = 0; i  n; i++){
		floyd[i][i] = 0;
	}
	for (int k = 0; k  n; k++) {
		for (int i = 0; i  n; i++) {
			for (int j = 0; j  n; j++) {
				if (i == j) continue;
				if (floyd[i][j]  graph[i][k] + graph[k][j]) {
					floyd[i][j] = graph[i][k] + graph[k][j];
					p[i][j] = k	;
				}
			}
		}
	}
	for (int i = 0; i  n; i++){
		for (int j = 0; j  n; j++){
			if (floyd[i][j]  graph[i][j]) {
				puts(-1);
				return;
			}
		}
	}
	for (int k = 0; k  n; k++) {
		for (int i = 0; i  n; i++) {
			for (int j = 0; j  n; j++) {
				if (i == j) continue;
				if (floyd[i][j] == floyd[i][k] + floyd[k][j] && (i != k) && (j != k)) {
					floyd[i][j] = -1;
					floyd[j][i] = -1;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i  n; i++) {
		for (int j = i + 1; j  n; j++) {
			if(floyd[i][j] != -1)
				ans += floyd[i][j];
		}
	}
	cout  ans  endl;
}


int main(){
	freopen(input.txt, r, stdin);
	
	scanf(%d, &t);
	while (t--){
		scanf(%d, &n);
		graph.assign(n, vectorint(n, 0));
		for (int i = 0; i  n; i++) {
			for (int j = i + 1; j  n; j++) {
				int num;
				scanf(%d, &num);
				graph[i][j] = num;
				graph[j][i] = num;
			}
		}
		solve();
	}
}
