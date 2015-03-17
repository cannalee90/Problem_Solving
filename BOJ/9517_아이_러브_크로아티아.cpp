#include <iostream>
#include <fstream>
#include <string>
#include<queue>
#include <algorithm>
#include <vector>
    
using namespace std;
  
int main()
{
    int p;
    int m;
    int time = 210;
    int t1;
    char t2;
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
    cin >> p;
    cin >> m;
    for(int i = 0; i<m; i++)
    {
        int total = 0;
        cin >> t1 >> t2;
        while(total != t1)
        {
            time --;
			total ++;
            if(time == -1){
				if(t2 == 'T' && total == t1)
				{
					p++;
					if(p == 9) p = 1;
				}
				cout << p << endl; return 0;
			}
        }
        if(t2 == 'T')
        {
            p++;
            if(p == 9) p = 1;
		}
	}
    cout << p << endl;

}