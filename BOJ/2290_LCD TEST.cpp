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


void get_width(int h, int w, int n, vector<vector<char> > &v){
	for (int i = w; i <w + n; i++){
		v[h][i] = '-';
	}
}

void get_height(int h, int w, int n, vector<vector<char> > &v){
	for (int i = h; i < h + n; i++){
		v[i][w] = '|';
	}
}


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

#endif
	int n;
	string str;
	cin >> n >> str;
	vector<vector<char > > ans(n * 2 + 3);
	for (int i = 0; i < str.size(); i++){
		vector<vector<char> > v(n * 2 + 3, vector<char>(n + 2, '.'));
		int cur = str[i] - '0';
		if (cur == 0){
			get_width(0, 1, n, v);
			get_width(n * 2 + 3 - 1, 1, n, v);
			get_height(1, 0, n, v);
			get_height(n * 1 + 3 - 1, 0, n, v);
			get_height(1, n + 2 - 1, n, v);
			get_height(n * 1 + 3 - 1, n + 2 - 1, n, v);

		}
		else if (cur == 1){
			get_height(1, n + 2 - 1, n, v);
			get_height(n * 1 + 3 - 1, n + 2 - 1, n, v);
		}
		else if (cur == 2){
			get_width(0, 1, n, v);
			get_width(n * 1 + 3 - 2, 1, n, v);
			get_width(n * 2 + 3 - 1, 1, n, v);
			get_height(1, n + 2 - 1, n, v);
			get_height(n * 1 + 3 - 1, 0, n, v);


		}
		else if (cur == 3){
			get_width(0, 1, n, v);
			get_width(n * 1 + 3 - 2, 1, n, v);
			get_width(n * 2 + 3 - 1, 1, n, v);
			get_height(1, n + 2 - 1, n, v);
			get_height(n * 1 + 3 - 1, n + 2 - 1, n, v);

		}
		else if (cur == 4){
			get_width(n * 1 + 3 - 2, 1, n, v);
			get_height(1, n + 2 - 1, n, v);
			get_height(1, 0, n, v);
			get_height(n * 1 + 3 - 1, n + 2 - 1, n, v);

		}
		else if (cur == 5){
			get_width(0, 1, n, v);
			get_width(n * 1 + 3 - 2, 1, n, v);
			get_width(n * 2 + 3 - 1, 1, n, v);
			get_height(1, 0, n, v);
			get_height(n * 1 + 3 - 1, n + 2 - 1, n, v);

		}
		else if (cur == 6){
			get_width(0, 1, n, v);
			get_width(n * 1 + 3 - 2, 1, n, v);
			get_width(n * 2 + 3 - 1, 1, n, v);
			get_height(1, 0, n, v);
			get_height(n * 1 + 3 - 1, n + 2 - 1, n, v);
			get_height(n * 1 + 3 - 1, 0, n, v);


		}
		else if (cur == 7){
			get_width(0, 1, n, v);
			get_height(1, n + 2 - 1, n, v);
			get_height(n * 1 + 3 - 1, n + 2 - 1, n, v);

		}
		else if (cur == 8){
			get_width(0, 1, n, v);
			get_width(n * 1 + 3 - 2, 1, n, v);
			get_width(n * 2 + 3 - 1, 1, n, v);
			get_height(1, n + 2 - 1, n, v);
			get_height(1, 0, n, v);
			get_height(n * 1 + 3 - 1, n + 2 - 1, n, v);
			get_height(n * 1 + 3 - 1, 0, n, v);


		}
		else if (cur == 9){
			get_width(0, 1, n, v);
			get_width(n * 1 + 3 - 2, 1, n, v);
			get_width(n * 2 + 3 - 1, 1, n, v);
			get_height(1, n + 2 - 1, n, v);
			get_height(1, 0, n, v);
			get_height(n * 1 + 3 - 1, n + 2 - 1, n, v);

		}
		for (int k = 0; k < v.size(); k++){
//			ans[k].push_back(' ');
			for (int j = 0; j < v[k].size(); j++){
				ans[k].push_back(v[k][j]);
			}
			ans[k].push_back(' ');

		}
	}
	for (int i = 0; i < ans.size(); i++){
		for (int j = 0; j < ans[i].size(); j++){
			if (ans[i][j] == '.') 
				cout << " ";
			else 
				cout << ans[i][j];
		}
		
		cout << endl;
	}

}