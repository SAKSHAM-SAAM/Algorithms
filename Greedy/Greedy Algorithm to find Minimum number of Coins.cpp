#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    vector<int> coins(n);
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        cin>>coins[i];
    }

    sort(coins.begin(),coins.end(),greater<int>());
    int V;cin>>V;
    for(int i=0;i<n;i++)
    {
        while(V>=coins[i])
        {
            V=V-coins[i];
            ans.push_back(coins[i]);
        }
    }

    for(auto x:ans)
    {
        cout<<x<<" ";
    }
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