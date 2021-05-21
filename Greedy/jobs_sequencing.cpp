#include<bits/stdc++.h>
using namespace std;
class Job{
    public:
        string id;
        int dead;
        int profit;
        Job(string x,int d,int p)
        {
            this->id = x;
            this->dead=d;
            this->profit=p;
        }
};
bool cmp(Job &a,Job &b)
{
    return a.profit > b.profit;
}
void solve()
{
    int n;
    cin>>n;
    vector<Job> seq;
    string id;
    int d,p;
    for(int i=0;i<n;i++)
    {
        cin>>id;
        cin>>d>>p;
        seq.push_back(Job(id,d,p));
    }
    sort(seq.begin(),seq.end(),cmp);

    vector<int> res;
    vector<bool> slot(n,false);

    for(int i=0;i<n;i++)
    {
        for(int j=min(seq[i].dead,n)-1;j>=0;j--)
        {
            if(slot[j]==false)
            {
                slot[j]=true;
                res.push_back(i);
                break;
            }
        }
    }
    cout<<" PROFITS ->\n";
    for(auto x:res)
    {
        cout<<seq[x].id<< " "<<seq[x].profit<<'\n';
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