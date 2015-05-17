#include <iostream>
#include <fstream>
#include <string>
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

class node{
public:
	node *number[12];
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
	if (N->number[str[idx] -'0'] == NULL)
		N->number[str[idx] - '0'] = new node();
	insert(str, idx + 1, N->number[str[idx] - '0']);
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t--){	
		node *root = new node();
		scanf("%d", &n);
		isPrefix = false;
		string str;
		for (int i = 0; i < n; i++){
			cin >> str;
			insert(str, 0, root);
			if (isPrefix)	break;
		}
		if (isPrefix)
			cout << "NO" << endl;
		if (!isPrefix)
			cout << "YES" << endl;
	}
}