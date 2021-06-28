#include<bits/stdc++.h>
using namespace std;
int util(int arr[],int n)
{
    int DP[n+1];
    DP[1]=arr[0];
    DP[2]=max(arr[0],arr[1]);
    for(int i=3;i<=n;i++)
    {
        DP[i]=max(arr[i-1]+DP[i-2],DP[i-1]);
    }
    return DP[n];
}
void solve()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int res=util(arr,n);
    cout<<res<<endl;
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