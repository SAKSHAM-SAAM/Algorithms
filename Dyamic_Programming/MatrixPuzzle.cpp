// CodeChef practice H1
#include<bits/stdc++.h>
using namespace std;
// Global Declarations
unordered_map<int,int> M;
const int dx[] = {1, 0};
const int dy[] = {0, 1};
const int primehash[] = {2, 3, 5, 7, 11, 13, 17};
// Inline Declarations
inline bool in(int x,int y){ if(x>=0 && x<3 && y>=0 && y<3) return true; return false;}
inline int uniqueid(node st)
{
    int res = 0;
    for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) res = res * 10 + st.data[i][j];

    return res;
}
inline bool isprime(int n)
{
    for (int i = 0; i < 9; i++) if (primehash[i] == n) return true;
    return false;
}
// Matrix Declaration
struct node
{
    int data[3][3];
};
queue<node> Q;
// Functions

void BFsearch(node s)
{
    M[uniqueid(s)] = 1;
    Q.push(s);

    while (!Q.empty())
    {
        node curr = Q.front();
        int currint = uniqueid(curr);
        Q.pop();
        // Rows
        for (int i = 0; i < 3; i++)
            //Columns
            for (int j = 0; j < 3; j++)
                // bfs 
                for (int k = 0; k < 2; k++)
                {
                    int x = i + dx[k], y = j + dy[k];

                    if (in(x, y) && isprime(curr.data[i][j] + curr.data[x][y]))
                    {
                        node tmp = curr;
                        swap(tmp.data[i][j], tmp.data[x][y]);
                        int hashval = uniqueid(tmp);

                        if (M[hashval]) continue;

                        M[hashval] = M[currint] + 1;
                        Q.push(tmp);
                    }
                }
    }
}
int main()
{
    cin.sync_with_stdio(0);

    int cnt = 1;
    node s;
    for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) s.data[i][j] = cnt++;
    BFsearch(s);

    int t;
    cin >> t;

    while (t--)
    {
        for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) cin >> s.data[i][j];

        printf("%dn", M[uniqueid(s)] - 1);
    }

    return 0;
}