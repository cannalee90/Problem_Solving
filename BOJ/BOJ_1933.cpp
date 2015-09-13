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
#include <cmath>

typedef long long ll;
using namespace std;

#define pb push_back
#define mp(a, b) make_pair((a), (b));

class data{
public:
    int coor;
    int height;
    bool type;
    bool operator<(const data& a) const {
        if(this->coor == a.coor && a.type == this->type && a.type == 1)
            return this->height > a.height;
        if(this->coor == a.coor && a.type == this->type && a.type == 0)
            return this->height < a.height;
        if(this->coor == a.coor && a.type != this->type)
            return this->type > a.type;       
        return this->coor < a.coor;
    }

};

int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<data> vd(n * 2);
    for(int i = 0; i < n; ++i){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        vd[i].coor = a;
        vd[i].height = b;
        vd[i].type = true;
        vd[n + i].coor = c;
        vd[n + i].height = b;
        vd[n + i].type = false;
    }
    sort(vd.begin(), vd.end());
    multiset<int> vi;
    multiset<int>::iterator itor, itor2;
    vi.insert(0);
    int last;
    for(int i = 0; i < n * 2; i++){
        if(vd[i].type == 1){
            itor = vi.lower_bound(vd[i].height);
            if(itor == vi.end())
                printf("%d %d\n", vd[i].coor, vd[i].height);
            vi.insert(vd[i].height);
        }
        else{
            itor = vi.upper_bound(vd[i].height);
            itor2 = vi.lower_bound(vd[i].height);
            itor2++;
            if(itor == vi.end() && itor2 == itor){
                itor--;
                printf("%d %d\n", vd[i].coor, *(--itor));
                ++itor;
            }
            else
                itor--;
            vi.erase(itor);
        }
    }
}