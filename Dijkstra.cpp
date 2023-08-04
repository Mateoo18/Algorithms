//Mateusz Nowak
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
const int INF=99999999;
vector<pair<int,int> >graf[N];
int odl[1000000];
main(){
 int n,m,a,b,c,k;
 cin>>k;
 for(int hh=0;hh<k;hh++)
 {
 cin>>n>>m;
 for(int i=0;i<n;i++)
 {
     odl[i]=0;

     graf[i].clear();
 }
 for(int i=0;i<m;i++)
 {
     cin>>a>>b>>c;
     a--;b--;
     graf[a].push_back({b,c});
 }
 for(int i=0;i<n;i++)
 {
     odl[i]=INF;
 }
 priority_queue<pair<int,int>>kolej;
 kolej.push({0,0});
 odl[0]=0;
 while(!kolej.empty())
 {
     int d_x=-kolej.top().first;
     int x=kolej.top().second;
     kolej.pop();
     if(d_x!=odl[x])
        continue;
     for(auto edge:graf[x])
     {
         int y=edge.first;
         int len=edge.second;
         if(d_x+len<odl[y])
         {
             odl[y]=d_x+len;
             kolej.push({-odl[y],y});
         }
     }
 }

if(odl[n-1]!=99999999) cout<<odl[n-1]<<endl;
else cout<<"BRAK"<<endl;
}}
