#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios::sync_with_stdio(0);cin.tie(0);
int util(int arr[],int n)
{
    if(n==1) return arr[0];
    else if(n==2) return max(arr[0],arr[1]);
    else
        return max(util(arr,n-1) ,util(arr,n-2)+arr[n-1] );
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
    IOS;
    int tt;
    cin>>tt;
    while(tt--){
        solve();
    }
    return 0;
}
/*
TESTCASE:
Input >
    1
    10 5 15 20
Output>
    30
*/