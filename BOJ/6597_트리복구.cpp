#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#define INF 10000007
#define INF 10000009
#define INF 900000000


typedef long long ll;
using namespace std;

int idx;
string preorder, inorder;

void traversal(string inorder)
{
	if(inorder.size() == 0) return;
	for(int i = 0; i<inorder.size(); i++)
	{
		if(preorder[idx] == inorder[i])
		{
			idx++;
			traversal(inorder.substr(0, i));
			traversal(inorder.substr(i + 1, inorder.size() - i));
			cout << inorder[i];
		}
	}
}

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	while(cin >> preorder >> inorder)
	{
		idx =0;
		preorder.push_back('.');
		traversal(inorder);
		cout << endl;
		preorder.clear();
		inorder.clear();
	}
}
