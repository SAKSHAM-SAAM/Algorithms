// LIS variation
// Maximum sum increasing subsequence
#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int msis[n];
    for(int i=0;i<n;i++)
    {
        msis[i]=arr[i];
        for(int j=0;j<=i;j++)
        {
            if(arr[i]>arr[j])
            {
                msis[i]=max(msis[i],arr[i]+msis[j]);
            }
        }
    }
    int res=1;
    for(int i=0;i<n;i++)
    {
        res=max(res,msis[i]);
    }
    cout<<res<<'\n';
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
TEST CASE:
IN  >   1
        6
        1 2 20 4 5 30
OUT >   53
*/