#include<bits/stdc++.h>
using namespace std;
int lcs(int arr[],int n)
{
    int cnt[n];
    cnt[0]=1;
    for(int i=1;i<n;i++)
    {
        cnt[i]=1;
        for(int j=0;j<=i;j++)
        {
            if(arr[i]>arr[j])
            {
                cnt[i]=max(cnt[i],cnt[j]+1);
            }
        }
    }
    int res=1;
    for(int i=0;i<n;i++)
    {
        res=max(cnt[i],res);
    }
    return res;
}
void solve()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    // longest increasing subsequnce
    int ans=lcs(arr,n);
    cout<<ans<<endl;
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
TEST AREA:

test case >
>   1
    5
    2 3 1 4 5

arr=2 3 1 4 5
cnt=1 2 1 3 4
res=4

OUT:
>   4
*/