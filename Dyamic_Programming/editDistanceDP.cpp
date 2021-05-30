#include<bits/stdc++.h>
using namespace std;
void solve()
{
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.length();
    int m=s2.length();
    int DP[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        DP[i][0]=i;
    }
    for(int i=1;i<=m;i++)
    {
        DP[0][i]=i;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                DP[i][j]=DP[i-1][j-1];
            }else{
                DP[i][j]=1+min(DP[i-1][j], min(DP[i][j-1], DP[i-1][j-1]));
            }
        }
    }
    cout<<DP[n][m]<<endl;
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