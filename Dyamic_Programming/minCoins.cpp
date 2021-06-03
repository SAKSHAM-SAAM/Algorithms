// minimum coins exchange
#include<bits/stdc++.h>
using namespace std;
int recur(int coins[],int n,int val)
{
    if(val<0) return -1;
    if(val==0) return 0;
    int res=INT_MAX;
    for(int i=0;i<n;i++)
    {
        int tmp=recur(coins,n,val-coins[i]);
        if(tmp!=-1)
        {
            res=min(res,tmp+1);
        }
    }
    return res;
}
// Dynamic Programming
int getMin(int arr[], int m, int value) 
{ 
    int dp[value + 1];      
    dp[0] = 0; 

    for (int i = 1; i <= value; i++) 
        dp[i] = INT_MAX;
        
    for (int i = 1; i <= value; i++) 
    { 
        for (int j = 0; j < m; j++) 
        if (arr[j] <= i) 
        { 
            int sub_res = dp[i - arr[j]]; 
            if (sub_res != INT_MAX && sub_res + 1 < dp[i]) 
                dp[i] = sub_res + 1;       
        } 
    } 
    return dp[value];  
}  
void solve()
{
    int n;
    cin>>n;
    int coins[n];
    for(int i=0;i<n;i++)
    {
        cin>>coins[i];
    }
    int val;
    cin>>val;
    int res=getMin(coins,n,val);
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