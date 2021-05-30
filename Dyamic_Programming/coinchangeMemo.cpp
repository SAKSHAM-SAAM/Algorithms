#include<bits/stdc++.h>
using namespace std;
void solve()
{
    // inputs
    int n;
    cin>>n;
    int coins[n];
    for(int i=0;i<n;i++)
    {
        cin>>coins[i];
    }
    int sum;
    cin>>sum;
    // solution
    int dp[sum+1][n+1];
    for(int i=0;i<=n;i++)
    {
        dp[0][i]=1;
    }
    for(int i=0;i<=sum;i++)
    {
        dp[i][0]=0;
    }
    //rows represent all combination till sum
    for(int i=1;i<=sum;i++)
    {   // j-1 represents all indexs for coins
        for(int j=1;j<=n;j++)
        {
            dp[i][j]=dp[i][j-1];
            if(coins[j-1]<=i)
            {
                dp[i][j]+=dp[i-coins[j-1]][j];
            }
        }
    }
    cout<<dp[sum][n]<<" \n";
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