#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <math.h>
using namespace std;
  
int step[10002];
int dp[3][10002];
    
int max(int a, int b, int c)
{
    int mmax=a;
    if ( mmax<b ) mmax=b;
    if ( mmax<c ) mmax=c;
    
    return mmax;
}
int main()
{
#ifdef _CONSOLE
    freopen("input.txt", "r", stdin);
#endif
  
    int n;

    cin>>n;
    
    for ( int i=0; i<n; i++ )
        cin>>step[i];
    
    if ( n==1 ) cout << step[0] << endl;
    else if ( n>=2 ) {
        dp[0][0]=dp[2][0]=0;
        dp[1][0]=step[0];
    
        for ( int i=1;  i<n; i++ ) {
            dp[0][i]=step[i]+dp[2][i-1];
            dp[1][i]=step[i]+dp[0][i-1];
            dp[2][i]=step[i]+dp[1][i-1];
        }
		cout << max(dp[0][n-1],dp[1][n-1], dp[2][n-1]);
    }
      
}