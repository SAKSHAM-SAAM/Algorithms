#include<bits/stdc++.h>
using namespace std;
void solve()
{
    string s1,s2;
    cin>>s1>>s2;
    int n=s2.length();
    int m=s1.length();
    int dp[m+1][n+1];
    
    for(int i=0;i<=m;i++)
        dp[i][0]=0;
    
    for(int j=0;j<=n;j++)
        dp[0][j]=0;
        
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(s1[i-1]==s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    
    cout<<dp[m][n];
}
int main()
{
    int tt;
    cin>>tt;
    
    while(tt--)
    {
        solve();
    }
    return 0;
}