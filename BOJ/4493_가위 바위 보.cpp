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
	int t;
	char winning[3][2] = { { 'S', 'P' }, { 'R', 'S' }, { 'P', 'R' } };
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		char player1, player2;
		int score1 = 0, score2 = 0;
		for (int i = 0; i < n; i++){
			cin >> player1 >> player2;
			for (int j = 0; j < 3; j++){
				if (winning[j][0] == player1 && player2 == winning[j][1])
					score1++;
				if (winning[j][0] == player2 && player1 == winning[j][1])
					score2++;
			}
		}
		if (score2 > score1) cout << "Player 2" << endl;
		else if (score1 > score2) cout << "Player 1" << endl;
		else cout << "TIE" << endl;

	}
}