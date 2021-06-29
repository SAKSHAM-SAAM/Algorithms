#include<bits/stdc++.h>
using namespace std;
int util(int arr[],int n,int key)
{
    if(n==0)
    {
        if(key==0) return 1;
        else return 0;
    }
    return util(arr,n-1,key)+util(arr,n-1,key-arr[n-1]);
}
void solve()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int key;cin>>key;
    int ans=util(arr,n,key);
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