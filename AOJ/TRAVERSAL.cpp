#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#define INF 900000000


typedef long long ll;
using namespace std;

vector<int>result;
int cnt;
int idx;

vector<int> slice(vector<int> inorder, int begin, int end)
{
	vector<int> slicing;
		for(int i = begin; i<end; i++)
	{
		slicing.push_back(inorder[i]);
	}
	return slicing;
}

void traversal(vector<int> inorder, vector<int> &preorder)
{
	if(inorder.size() == 0) return;
	if(preorder[idx] == inorder[0] && inorder.size() == 1)
	{
		idx++;
		cout << inorder[0] << " ";
		return;
	}
	for(int i = 0; i<inorder.size(); i++)
	{
		if(preorder[idx] == inorder[i])
		{
			idx++;
			traversal(slice(inorder, 0, i), preorder);
			traversal(slice(inorder, i+ 1, inorder.size()), preorder);
			cout << inorder[i] << " ";
			return;
		}
	}
	
}

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int t;
	cin >> t;
	while(t--)
	{
		int n, t1;
		cin >> n;
		vector<int> preorder;
		vector<int> inorder;


		for(int i = 0; i<n; i++)
		{
			cin >> t1;
			preorder.push_back(t1);
		}
		for(int i = 0; i<n; i++)
		{
			cin >> t1;
			inorder.push_back(t1);
		}
		cnt = 0;
		idx = 0;
		traversal(inorder, preorder);
		cout << endl;
	}
}
