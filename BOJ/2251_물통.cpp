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

struct bucket{
	int a, b, c;
	bucket(int a, int b, int c) : a(a), b(b), c(c)
	{}
};

bool visited[201][201][201];
int a, b, c;

int main()
{
	freopen("input.txt", "r", stdin);
	int send;
	int rest;
	cin >> a >> b >> c;
	queue<bucket> que;
	que.push(bucket(0, 0, c));
	while (!que.empty()) {
		bucket here = que.front();
		que.pop();
		if (here.a != 0) {

			send = min(here.b + here.a, b);
			rest = here.a - (send - here.b);

			if (!visited[rest][send][here.c]) {
				que.push(bucket(rest, send, here.c));
				visited[rest][send][here.c] = true;
			}
			send = min(here.c + here.a, c);
			rest = here.a - (send - here.c);

			if (!visited[rest][here.b][send]) {
				que.push(bucket(rest, here.b, send));
				visited[rest][here.b][send] = true;
			}
		}
		if (here.b != 0) {
			send = min(here.a + here.b, a);
			rest = here.b - (send - here.a);
			 
			if (!visited[send][rest][here.c]) {
				que.push(bucket(send, rest, here.c));
				visited[send][rest][here.c] = true;
			}
			send = min(here.c + here.b, c);
			rest = here.b - (send - here.c);

			if (!visited[here.a][rest][send]) {
				que.push(bucket(here.a, rest, send));
				visited[here.a][rest][send] = true;
			}
		}
		if (here.c != 0) {
			send = min(here.a + here.c, a);
			rest = here.c - (send - here.a);

			if (!visited[send][here.b][rest]) {
				que.push(bucket(send, here.b, rest));
				visited[send][here.b][rest] = true;
			}
			send = min(here.b + here.c, b);
			rest = here.c - (send - here.b);

			if (!visited[here.a][send][rest]) {
				que.push(bucket(here.a, send, rest));
				visited[here.a][send][rest] = true;
			}
		}
	}
	
	set<int> ans;
	for (int i = 0; i <= 200; i++)
		for (int j = 0; j <= 200; j++)
			if (visited[0][i][j])
				ans.insert(j);
	for (auto itor = ans.begin(); itor != ans.end(); itor++)
		cout << *itor << " ";
	puts("");
}