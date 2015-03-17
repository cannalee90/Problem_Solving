#include <iostream>
#include <utility>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include<limits.h>

#include <set>
#include <map>
#include <vector>
#include <stack>

typedef long long ll;

using namespace std;


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	string data;
	while (cin >> data){
		if (data == "#")
			break;
		if (data.back() == 'e'){
			int cnt = 0;
			for (int i = 0; i < data.size() - 1; i++){
				cout << data[i];
				if (data[i] == '1')
					cnt++;
			}
			if (cnt % 2 == 0)
				cout << "0";
			else
				cout << "1";
		}
		if (data.back() == 'o'){
			int cnt = 0;
			for (int i = 0; i < data.size() - 1; i++){
				cout << data[i];
				if (data[i] == '1')
					cnt++;
			}
			if (cnt % 2 == 1)
				cout << "0";
			else
				cout << "1";
		}
		cout << endl;
	}
}
