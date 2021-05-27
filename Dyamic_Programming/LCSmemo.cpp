#include<bits/stdc++.h>
using namespace std;
int lcs(string s1,string s2,int n,int m,vector<vector<int>> &memo)
{
    if(memo[n][m]!=-1)
        return memo[n][m];
        
    if(n==0 || m==0)
        memo[n][m]=0;
        
    else
    {
        if(s1[n-1]==s2[m-1])
            memo[n][m] = 1 + lcs(s1,s2,n-1,m-1,memo);
        else
            memo[n][m] = max(lcs(s1,s2,n-1,m,memo),lcs(s1,s2,n,m-1,memo));
    }
    
    return memo[n][m];
}
void solve()
{
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.length();
    int m=s2.length();
    vector<vector<int>> memo(n+1,vector<int> (m+1,-1));
    cout<<lcs(s1,s2,n,m,memo)<<'\n';
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