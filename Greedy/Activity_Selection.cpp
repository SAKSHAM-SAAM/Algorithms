#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> a,pair<int,int> b)
{
    return a.second < b.second;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        // number of activities 
        int n; cin>>n;
        vector<pair<int,int>> act;
        for(int i=0;i<n;i++)
        {
            // a-> start time && b-> end time
            int a,b;
            cin>>a>>b;
            act.push_back({a,b});
        }
        sort(act.begin(),act.end(),cmp);
        /*
        for(auto x:act)
        {
            cout<<x.first<<" "<<x.second<<'\n';
        }
        */
        // number of activities selected
        int sel=0;
        int prev=-1;
        cout<<"activities choosen ->\n";
        for(int i=0;i<n;i++)
        {
            if(act[i].first >= prev)
            {
                sel++;
                cout<<act[i].first<<" "<<act[i].second<<endl;
                prev=act[i].second;
            }
        }
        cout<<"total activities done:"<<sel<<endl;
        cout<<"-- -- -- -- --\n";
    }
    return 0;
}