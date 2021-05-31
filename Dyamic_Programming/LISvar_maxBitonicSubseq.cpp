// Longest Incresing Subsequence variation
// Maximum Length Bitonic Subsequence
/*
    WHAT IS "BITONIC"?
>   A sequence which first increases, then decreases. Increasing or decreasing part
    can be empty.
*/
#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    // Solution
    // for increasing Subsequence
    int lis[n];
    lis[0]=1;
    for(int i=1;i<n;i++)
    {
        lis[i]=1;
        for(int j=0;j<=i;j++)
        {
            if(arr[i]>arr[j])
            {
                lis[i]=max(lis[i],1+lis[j]);
            }
        }
    }
    // for decreasing subsequence
    int lds[n];
    lds[n-1]=1;
    for(int i=n-2;i>=0;i--)
    {
        lds[i]=1;
        for(int j=n-1;j>=i;j--)
        {
            if(arr[i]>arr[j])
            {
                lds[i]=max(lds[i],1+lds[j]);
            }
        }
    }
    int res=1;
    for(int i=0;i<n;i++)
    {
        res=max(res,lds[i]+lis[i]-1);
    }
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
/*
TEST CASE
>   1
    8
    1 11 2 10 4 5 2 1
>   6 
Explanation > 
    1 2 10 5 2 1 or 1 2 10 4 2 1 
    ^ ^ ^  v v v
*/