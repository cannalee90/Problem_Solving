#include <cstdio>	
#include <iostream>
#include <algorithm>

typedef long long ll;
using namespace std;

ll find_lcm(ll a, ll b){
	while (b % a){
		ll temp = a;
		a = b % a;
		b = temp;
	}
	return a;

}

int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	while (n--){
		ll a, b;
		scanf("%lld %lld", &a, &b);
		if (a > b) 
			swap(a, b);
		ll lcm = find_lcm(a, b);
		printf("%lld %lld\n", a * b / lcm, lcm);
	}
}