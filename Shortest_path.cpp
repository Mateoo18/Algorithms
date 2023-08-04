//Mateusz Nowak 3LO tarnow

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const int N=1e6;
vector<bool> visited(N);
vector<vector<int>> g(N);
int path[1000000];
void bfs(int s)
{
    queue<int>q;
    q.push(s);
    visited[s]=true;
    while(!q.empty())
        {
            int cur=q.front();
            q.pop();
         //   cout<<"jestem: "<<cur<<endl;
            for(int i=0;i<g[cur].size();i++)
            {
               if(!visited[g[cur][i]])
                {
                 //   cout<<"obecnie: "<<g[cur][i]<<endl;
                    path[g[cur][i]]=cur;
                    q.push(g[cur][i]);
                    visited[g[cur][i]]=true;
                }
            }
        }
}
int main()
{
    int n,m,a,b,obec;
    cin>>n>>m;
    path[1]=-1;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cin>>obec;
    bfs(1);
    for(int i=0;i<n;i++)
    {
//cout<<i<< " "<<path[i]<<endl;         
    }
    while(obec!=-1)
    {
        cout<<obec<<" ";
    obec=path[obec];
    }
    
}
