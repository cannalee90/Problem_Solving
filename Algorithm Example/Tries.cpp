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

int n, m, t;
bool isPrefix;
vector<string> data;

class node{
public:
	node *number[26];
	bool isEnd;
	node(){
		for (int i = 0; i < 26; i++)
			this->number[i] = NULL;
		this->isEnd = false;
	}
};

void insert(string str, int idx, node *N){
	if (N->isEnd == true){
		isPrefix = true;
		return;
	}
	if (str.size() == idx){
		
		N->isEnd = true;
		return;
	}

	if (N->number[str[idx] - '0'] == NULL)
		N->number[str[idx] - '0'] = new node();
	insert(str, idx + 1, N->number[str[idx] - '0']);
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);
#endif
	string str;
	scanf("%d", &t);
	while (t--){
		int n;
		node *root = new node();
		cin >> n;
		isPrefix = false;
		vector<string> data;
		for (int i = 0; i < n; i++){
			cin >> str;
			data.push_back(str);
		}
		sort(data.begin(), data.end());
		for(int i = 0; i<n; i++)
			insert(data[i], 0, root);
		
		if (isPrefix) cout << "NO" << endl;
		if (!isPrefix)	cout << "YES" << endl;
	}
}