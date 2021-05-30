#include<bits/stdc++.h>
using namespace std;
int editRecur(string s1,string s2,int n,int m)
{
    // as n==0 we need to delete all m chars in s2 string 
    if(n==0) return m;
    // as m==0 we need to delete all n chars in s1 string 
    if(m==0) return n;
    if(s1[n-1]==s2[m-1])
    {
        // no action required as characters match
        return editRecur(s1,s2,n-1,m-1);
    }else{
        // mismatch makes us do one action and it can be any : insert , delete or replace
        //           insert new char to s1   delete char from s1        replace thus both move 
        return 1+min(editRecur(s1,s2,n,m-1), min(editRecur(s1,s2,n-1,m),editRecur(s1,s2,n-1,m-1)));
    }
}
void solve()
{
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.length();
    int m=s2.length();
    int ans=editRecur(s1,s2,n,m);
    cout<<ans<<'\n';
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