//Mateusz Nowak
#include <bits/stdc++.h>
using namespace std;
const int N=1e6;
int licznik=0;
queue<int>Q;
vector<int>wyn;
vector<vector<int>>g(N);
int tab[1000000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
 int kk;
 cin>>kk;
 int n,m;
 for(int H=0;H<kk;H++)
 {

     cin>>n>>m;
     for(int i=0;i<=n;i++)
     {
         g[i].clear();
         tab[i]=0;
     }
     wyn.clear();
     licznik=0;
     for(int i=0;i<m;i++)
     {
         int a,b;
         cin>>a>>b;
         tab[b]++;

         g[a].push_back(b);
     }
     for(int i=1;i<=n;i++)
     {
         if(tab[i]==0)
         {
             licznik++;
             Q.push(i);
         }
     }
     while(!Q.empty())
     {

         int node=Q.front();
         Q.pop();
         wyn.push_back(node);
for(int i=0;i<g[node].size();i++)
{
    int wierz=g[node][i];
    tab[wierz]--;
    if(tab[wierz]==0)
    {
        licznik++;
        Q.push(wierz);
    }
}
     }
     if(licznik==n)
     {
         cout<<"OK"<<endl;
     for(int i=0;i<n;i++)
     {
         cout<<wyn[i]<<" ";
     }
     cout<<endl;
     }
     else
     {
         cout<<"CYKL"<<endl;
     }
 }


}
/*
8 9
8 7
6 7
5 7
6 5
5 4
4 3
1 4
1 2
2 3
*/
