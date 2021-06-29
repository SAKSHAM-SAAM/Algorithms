#include<bits/stdc++.h>
using namespace std;
int util(int arr[],int n,int key)
{
    int DP[n+1][key+1];
    for(int i=0;i<=n;i++) DP[i][0]=1;
    for(int i=1;i<=key;i++) DP[0][i]=0;
    for(int i=1;i<=n;i++)  // index of array considered
        for(int j=1;j<=key;j++) // sum considered
        {
            // if sum considered is less than array element considered 
            // do not consider that element 
            if(j<arr[i-1]) DP[i][j]=DP[i-1][j];
            else DP[i][j]=DP[i-1][j]+DP[i-1][j-arr[i-1]];
        }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=key;j++)
        {
            cout<<DP[i][j]<<" ";
        }
        cout<<endl;
    }
    return DP[n][key];
}

void solve()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int key;cin>>key;
    int ans=util(arr,n,key);
    cout<<ans<<" ";
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
index:    0  1  2
array:  { 2, 5, 3 }
sum  :  5

table >
sum :      0  1  2  3  4  5
index
    0    |1 |0 |0 |0 |0 |0 |
    1    |1 |0 |1 |0 |0 |0 |
    2    |1 |0 |1 |0 |0 |1 |
    3    |1 |0 |1 |1 |0 |2 |
*/