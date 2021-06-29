#include<bits/stdc++.h>
using namespace std;
int util(int arr[],int n)
{
    int DP[n][n];

}
void solve()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int ans=util(arr,n);
    cout<<ans<<endl;
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
/*
tt>
1
4
2 1 3 4
--- Very important problem
*/