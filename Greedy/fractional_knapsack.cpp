#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int fract;
        int price;
        int weight;

        node(int p,int wt)
        {
            price=p;
            weight=wt;
            fract=int(price/weight);
        }
};
bool cmp(node &a,node &b){
    return a.fract > b.fract;
}
void solve()
{
    int n;
    cin>>n;
    vector<node> val;
    for(int i=0;i<n;i++)
    {
        int price,weight;
        cin>>weight>>price;
        node tmp=node(price,weight);
        val.push_back(tmp);
    }
    sort(val.begin(),val.end(),cmp);
    cout<<'\n';
    for(auto x:val)
    {
        cout<<x.fract<<" "<<x.price<<" "<<x.weight<<'\n';
    }
    cout<<"--- ---- -----\n";
    int loot=0;
    int cap;
    cin>>cap;
    for(int i=0;i<n;i++)
    {
        if(cap==0) break;
        if(cap >= val[i].weight)
        {
            cap=cap-val[i].weight;
            val[i].weight=0;
            loot=loot+val[i].price;
        }else{
            loot = loot + val[i].fract*cap;
            cap=0;
        }
    }
    cout<<"maximum loot ->"<<loot<<'\n';
}
int main()
{
    // number of testcases
    int t;cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}