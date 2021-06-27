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
// Dynamic Solution
/*
    In the solution, We first declare a profit array of capacity "cap+1"
    so last index == cap, which is the provided capacity of the bag.
    Now, we set the capacity of cap[0]=0 as, "No bag No profit".
    We loop from 1 to capacity now where in each iteration we run a
    nested loop which runs for each item available for pick-up.
    We examine if bag has capacity to take this item in, if not 
    profit are same for now as last capacity of bag, 


*/
int knapsackDP(int val[],int wt[],int cap,int n)
{
    int DP[n+1][cap+1];
    // Row
    for(int i=0;i<=n;i++) // slowly increasing the number of elements considered
    {   // Column
        for(int w=0;w<=cap;w++) // All bag sizes are compared 
        {
            if(w==0 || i==0)
            {
                DP[i][w]=0;
            }
            else if(wt[i-1] <= w)
            {
                DP[i][w]=max(val[i-1] + DP[i-1][w-wt[i-1]], DP[i-1][w]);
            }else{
                // Same bag size, but element considered one less
                DP[i][w] = DP[i-1][w];
            }
        }
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