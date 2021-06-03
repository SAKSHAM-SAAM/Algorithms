// Minimum Jumps 
#include<bits/stdc++.h>
using namespace std;
// RECURSIVE SOLUTION
int minJumps(int arr[],int n)
{
    if(n==1) return 0;
    int res=INT_MAX;
    for(int i=0;i<=n-2;i++)
    {
        if(i+arr[i]>=n-1)
        {
            int sub_res=minJumps(arr,i+1);
            if(sub_res!=INT_MAX)
                res=min(sub_res+1,res);
        }
    }
    return res;
}
// Dynamic Solution
int DP(int arr[],int n)
{
    int dp[n];
    dp[0]=0;
    for(int i=1;i<n;i++)
    {
        dp[i]=INT_MAX;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(j+arr[j]>=i)
            {
                if(dp[j]!=INT_MAX)
                {
                    dp[i]=min(dp[j]+1,dp[i]);
                }
            }
        }
    }
    return dp[n];
}
void solve()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int res=minJumps(arr,n);
    cout<<res<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }           
    return 0;
}