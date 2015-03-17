#include <iostream>
#include <fstream>
#include <string>
#include<queue>
#include<stdio.h>
#include <algorithm>
#include <vector>
   
using namespace std;

int tree[30][2];

void postorder(int node)
{
	printf("%c", node + 'A' -1);
	if(tree[node][0] != 0)
		postorder(tree[node][0]);
	if(tree[node][1] != 0)
		postorder(tree[node][1]);

}

void preorder(int node)
{
	if(tree[node][0] != 0)
		preorder(tree[node][0]);
	if(tree[node][1] != 0)
		preorder(tree[node][1]);
	printf("%c", node + 'A' -1);
}
void inorder(int node)
{
	if(tree[node][0] != 0)
		inorder(tree[node][0]);
	printf("%c", node + 'A' -1);
	if(tree[node][1] != 0)
		inorder(tree[node][1]);

}


int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
	int n;
	char t1,t2,t3;
	cin >> n;
	for(int i = 0; i<n; i++)
	{
		cin >> t1 >> t2 >> t3;
		if(t2 != '.')
			tree[t1-'A' + 1][0] = t2 - 'A' + 1;
		if(t3 != '.')
			tree[t1-'A' + 1][1] = t3 - 'A' + 1;
	}
	postorder(1);
	cout << endl;
	inorder(1);
	cout << endl;
	preorder(1);
	cout << endl;

}