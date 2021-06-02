// Longest increasing Subsequence variation
// Making bridges 
#include<bits/stdc++.h>
using namespace std;
// MACROS definition
#define pb push_back
bool cmp(pair<int,int> &a, pair<int,int> &b)
{
    if(a.second == b.second)
        return a.first<b.first;
    return a.second < b.second;
}
void solve()
{
    int n;
    cin>>n;
    vector<pair<int,int>> cities;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        cities.pb({a,b});
    }
    // Solution
    int lis[n]={0};
    lis[0]=1;
    sort(cities.begin(),cities.end(),cmp);
    for(int i=1;i<n;i++)
    {
        lis[i]=1;
        for(int j=0;j<i;j++)
        {
            if(cities[i].first >= cities[j].first)
            {
                lis[i]=max(lis[i], 1+lis[j]);
            }
        }
    }
    int res=lis[0];
    for(int i=1;i<n;i++)
    {
        res=max(res,lis[i]);
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
TEST CASE :
Example :
    cities of one side {first}
    0 1 2 3 4 5
- - - - - - - - - 

River

- - - - - - - - -
    1 2 3 4 5 6
    cities on other side {Second}

    1
    4
    6 2
    4 3
    2 6
    1 5

*/