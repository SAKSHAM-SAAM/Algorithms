#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        char label;
        int freq;
        Node* left;
        Node* right;
        Node(char c,int f)
        {
            this->label=c;
            this->freq=f;
            left=right=NULL;
        }
};
struct cmp{
    bool operator()(Node* a,Node* b)
    {
        return (a->freq > b->freq);
    }
};
void print(Node* root, string s="")
{
    if(root==NULL) return;
    if(root->label!='$') cout<<root->label<<" : "<<s<<endl;
    print(root->left,s+"0");
    print(root->right,s+"1");  
}
void Huffman(char label[],int freq[],int n)
{
    priority_queue<Node*, vector<Node*>,cmp> pq;
    Node *left,*right,*top;

    for(int i=0;i<n;i++)
    {
        pq.push(new Node(label[i],freq[i]));
    }

    while(pq.size()>1)
    {
        left = pq.top();
        pq.pop();

        right= pq.top();
        pq.pop();

        top=new Node('$', left->freq+right->freq);
        top->left=left;
        top->right=right;

        pq.push(top);
    }

    print(pq.top(),"");
}
void solve()
{
    // Input all data 
    int n;
    cin>>n;
    char label[n];
    int freq[n];
    for(int i=0;i<n;i++)
    {
        cin>>label[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>freq[i];
    }
    // Evaluate data
    Huffman(label,freq,n);
}
int main()
{
    int t;
    cin>>t;
    {
        solve();
    }
    while(t--)
    return 0;
}