#include<bits/stdc++.h>
using namespace std;
int util(int arr[],int i,int j)
{
    if(i+1==j) return 0;
    int res=INT_MAX;
    for(int k=i+1;k<j;k++)
    {
        res=min(res,util(arr,i,k)+ util(arr,k,j)+ arr[i]*arr[j]*arr[k]);
    }
    return res;
}
void solve()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    int res=util(arr,0,n-1);
    cout<<res<<"\n";
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
Input>

Output>

*/