#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);
void solve()
{
    int floor,egg;
    cin>>floor>>egg;
    int DP[floor+1][egg+1];
    for (int  i = 1; i <= egg; i++)
    {
        /* code */
        DP[0][i]=0;
        DP[1][i]=1;
    }
    for (int i = 1; i <= floor; i++)
    {
        /* code */
        DP[i][1]=i;
    }
    for(int i=2;i<=floor;i++) // Rows
    {
        for(int j=2;j<=egg;j++) // Columns 
        {
            DP[i][j] = INT_MAX;
            for(int k=1;k<=i;k++) // traverse previous rows
            {
                DP[i][j]=min(DP[i][j],1+max(DP[k-1][j-1],DP[i-k][j]));
            }
        }
    }
    int res=DP[floor][egg];
    cout<<res<<endl;
}
int main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
// Working >
/*
    Explanation >
    Suppose there is a building with 5 floors. We are to drop egg from each floor to check whether it breaks or not.
    Conditions to know before experiment >
    …..An egg that survives a fall can be used again. 
    …..A broken egg must be discarded. 
    …..The effect of a fall is the same for all eggs. 
    …..If an egg breaks when dropped, then it would break if dropped from a higher floor. 
    …..If an egg survives a fall then it would survive a shorter fall. 
    …..It is not ruled out that the first-floor windows break eggs, nor is it ruled out that the 5th-floor do not cause an egg to break.
    __________________
    |   5th floor    |
    |   4th floor    |
    |   3rd floor    |
    |   2nd floor    |
    |   1st floor    |
    |   Gnd floor    |
    ---------------------------|
    steps to solution > 
    drop from floor zero >either egg breaks or not 
                            > if it break , zero is threshold else proceed.
*/