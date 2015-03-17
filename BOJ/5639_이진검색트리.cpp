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

int cnt;
int idx;
vector<int> preorder;
vector<int> inorder;
	
void traversal(int start, int final)
{
	if(start == final) return;
	for(int i = start; i<final; i++)
	{
		if(preorder[idx] == inorder[i])
		{
			idx++;
			if(start != i)	traversal(start, i);
			if(i + 1 != final) traversal(i + 1, final);
			cout << inorder[i] << endl;
			return;
		}
	}	
}

int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int t, n = 0, t1;
	while(cin >> t1){preorder.push_back(t1); n++;}
	inorder = preorder;
	sort(inorder.begin(), inorder.end());
	idx = 0;
	traversal(0, n);
}
