#include <iostream>
#include <string>

typedef long long ll;

using namespace std;

int graph[8][2] = { { 7, 1 }, { 2, 8 }, { 3, 8 }, { 3, 4 }, { 7, 5 }, { 6, 5 }, { 3, 0 }, { 8, 0 } };

int main(){
	int t;
	cin >> t;
	while (t--){
		int here = 0;
		int idx = 0;
		string str;
		cin >> str;
		while(idx != str.size() && here != 8){
			int there = str[idx++] - '0';
			here = graph[here][there];
		}
		if (here == 0 || here == 4 || here == 5 || here == 6)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}