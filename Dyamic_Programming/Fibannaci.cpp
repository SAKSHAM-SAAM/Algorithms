#include<bits/stdc++.h>
using namespace std;
/* recursive 
int recur(int n)
{
    if(n==1 || n==0) return 1;
    else return recur(n-1)+recur(n-2);
}
*/
// Dynamic Programming
// using memoization
int util(vector<int> &dp,int x)
{
    if(dp[x]==-1)
    {
        int res;
        if(x==0 || x==1) return 1;
        else res = util(dp,x-1) + util(dp,x-2);
        dp[x]=res;
    }
    return dp[x];
}
int DP(int n)
{
    vector<int> dp(n+1,-1);
    return util(dp,n);
}
int main()
{
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        int ans = DP(n);
        cout<<ans<<"\n";
    }
    return 0;
}