#include<bits/stdc++.h>
using namespace std;
// Tabular Dynamic Programming 
// Bottom up approach
int tabularDP(int n)
{
    vector<int> tab(n+1,-1);
    tab[0]=0;
    tab[1]=1;
    for(int i=2;i<=n;i++)
    {
        tab[i]=tab[i-1]+tab[i-2];
    }
    return tab[n];
}
int main()
{
    int tt;
    scanf("%d",&tt);
    while(tt--)
    {
        int n;
        scanf("%d",&n);
        int res=tabularDP(n);
        cout<<res<<endl;
    }
    return 0;
}