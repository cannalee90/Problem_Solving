#include <iostream>
#include <utility>
#include <limits.h>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>

typedef long long ll;
using namespace std;


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);

#endif
	int t;
	cin >> t;
	getchar();
	while (t--){
		char a;
		int num = 0;
		vector<int> signal;
		while ((a = getchar()) != '\n'){
			if (a == -1) break;
			if (a == ' '){
				signal.push_back(num);
				num = 0;
			}
			else{
				num *= 10;
				num += a - '0';
			}
		}
		signal.push_back(num);
		vector<int> compare;
		compare.push_back(signal[0]);
		int lens = signal.size();
		int idx = 1;
		bool isPrint = false;
		while(idx < lens){
			bool isSame = true;
			int pos = 0;
			int com_lens = compare.size();
			for (int j = idx; j < lens; j++){
				if (signal[j] != compare[pos]){
					for (int k = idx; k <= j; k++)
						compare.push_back(signal[k]);
					idx = j + 1;
					isSame = false;
					break;
				}
				pos++;
				pos %= com_lens;
			}
			if (isSame){
				for (int i = 0; i < compare.size(); i++)
					printf("%d ", compare[i]);
				printf("\n");
				isPrint = true;
				break;
			}
		}
		if (isPrint) continue;
		compare.clear();
		for (int i = 0; i < lens; i++){
			bool isSame = true;
			int pos = 0;
			compare.push_back(signal[i]);
			int com_lens = compare.size();
			for (int j = i + 1; j < lens; j++){
				if (compare[pos++] != signal[j]){
					isSame = false;
					break;
				}
				pos %= com_lens;
			}
			if (isSame){
				for (int i = 0; i < compare.size(); i++)
					printf("%d ", compare[i]);
				printf("\n");
				isPrint = true;
				break;
			}

		}
	}
}