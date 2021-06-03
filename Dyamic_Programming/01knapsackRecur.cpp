// 0-1 knapsack recursive
#include<bits/stdc++.h>
using namespace std;
// RECURSIVE SOLUTION
int knapsack(int val[],int wt[],int cap,int n)
{
    if(n==0 || cap==0) return 0;
    if(wt[n-1]>cap)
    {
        return knapsack(val,wt,cap,n-1);
    }
    else
    {
        return max(knapsack(val,wt,cap,n-1), knapsack(val,wt,cap-wt[n-1],n-1) + val[n-1]);
    }
}
void solve()
{
    int n;
    cin>>n;
    int val[n];
    int wt[n];
    for(int i=0;i<n;i++)
    {
        cin>>val[i]>>wt[i];
    }
    int cap;cin>>cap;
    int profit=knapsack(val,wt,cap,n);
    cout<<profit<<endl;
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