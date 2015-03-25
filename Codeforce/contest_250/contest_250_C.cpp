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

class edge{
public:
	int here;
	int there;
	int weight;
	edge(int here, int there, int weight){
		this->here = here;
		this->there = there;
		this->weight = weight;
	}
	bool operator <(const edge &a) const
	{
		return this->weight > a.weight;
	}
};