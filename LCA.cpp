//Mateusz Nowak
#include <bits/stdc++.h>
 
using namespace std;
 
vector <vector<int> > g(1000000);
int Ancestor[1000000][21];
int ojciec[1000000];
int gle[1000000];
int ct = 0;
 
void dfs(int s, int p)
{
    cout<<" ojciec[s]"<< ojciec[s]<<endl;
    ojciec[s] = p;
    cout<<" gle[s]"<< gle[s]<<endl;
    cout<<"s"<<s<<endl;
    gle[s] = ct;
    ++ct;
    for(auto I : g[s])
    {
        cout<<"I"<<I<<endl;
        if(I != p)
        {
            cout<<s;
        dfs(I, s);
        }
    }
    --ct;
}
 
void makeAncestor(int n)
{
    
    for(int x = 1;x <= n;++x)
    {
        Ancestor[x][0] = ojciec[x];
        cout<<"ojciec[x]"<<ojciec[x]<<endl;
    }
    for(int k = 1;k <= 20;++k)
    {
        for(int x = 1;x <= n;++x)
        {
            Ancestor[x][k] = Ancestor[Ancestor[x][k - 1]][k - 1];
            cout<<" Ancestor[x][k]"<<Ancestor[Ancestor[x][k - 1]][k - 1]<<endl;
        }
    }
}
 
int LCA(int A, int B)
{
    cout<<"A"<<A<<"B"<<B<<endl;
    if(gle[B] < gle[A])
    {
        cout<<"gle[A]"<<gle[A]<<"gle[B]"<<gle[B]<<endl;
        swap(A, B);
        
    }
    for(int k = 20;k >= 0;--k)
    {
        if(gle[Ancestor[B][k]] >= gle[A])
        {
        cout<<"gle[Ancestor[B][k]]"<<gle[Ancestor[B][k]]<<endl;
             B = Ancestor[B][k];
        }
    }
    if(A == B)
        return A;
    for(int k = 20;k >= 0;--k)
    {
        if(Ancestor[A][k] != Ancestor[B][k])
        {
            A = Ancestor[A][k];
            B = Ancestor[B][k];
            cout<<" Ancestor[A][k]"<< Ancestor[A][k]<<endl;
            cout<<" Ancestor[B][k]"<< Ancestor[B][k]<<endl;
        }
    }
    return ojciec[A];    
}
 
int main()
{
    int n, a, b;
    cin >> n;
 
    for(int i = 0;i < n-1;++i)
    {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cout<<"DFS"<<endl;
    dfs(1,1);
    cout<<"makeancetor"<<endl;
    makeAncestor(n);
    int q;
    cin >> q;
    
    
    while(q --> 0)
    {
        cin >> a >> b;
        cout << gle[a]+gle[b]-2*gle[LCA(a, b)] << endl;
    }
    cout<<"gle"<<endl;
    for(int i=0;i<20;i++)
{
    cout<<gle[i];
}

    return 0;
}
