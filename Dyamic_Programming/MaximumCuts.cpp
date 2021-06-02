// Maximum Cuts
#include<bits/stdc++.h>
using namespace std;
/*  Recursive function_ 
    for reference during implementation and 
    study of Dynamic solution
*/
int maxCut(int rod,int a,int b,int c)
{
    if(rod < 0) return -1;
    if(rod == 0) return 0;
    int mx = max(maxCut(rod-a,a,b,c),max(maxCut(rod-b,a,b,c),maxCut(rod-c,a,b,c)));
    if(mx==-1) return mx;
    return 1+mx;
}
void solve()
{
    int rod;
    int a,b,c;
    cin>>rod>>a>>b>>c;
    int res=maxCut(rod,a,b,c);
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