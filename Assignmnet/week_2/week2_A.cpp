#include <stdio.h>
#include <vector>
#include <cstring>

typedef long long ll;

using namespace std;


int main(){
	int n;
	int ans = 0;
	int x1, y1, y2, x2;
	bool board[1010][1010];

	scanf("%d", &n);
//	memset(board, 0, sizeof(board));

	for (int t = 0; t < n; t++){
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		x2 += x1;
		y2 += y1;
		for (int i = y1; i < y2; i++){
			for (int j = x1; j < x2; j++){
				if (!board[i][j]){
					board[i][j] = true;
					ans++;
				}
			}
		}
	}
	printf("%d\n", ans);
}
