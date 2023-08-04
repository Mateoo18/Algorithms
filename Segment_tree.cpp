#include <iostream>
using namespace std;
const int M = 1 << 20;
int tab[2*M];
void insert(int a,int v)
{
a+=M;
while(a!=0)
{
  tab[a]+=v;
  a/=2;
}
}
void insert_po(int a,int v,int odej)
{
a+=M;
while(a!=0)
{
     tab[a]-=odej;
  tab[a]+=v;
  a/=2;
}
}
int  query(int a, int b)
{
  a+=M;
  b+=M;
  int wynik=tab[a];
  if(a!=b)
  {
    wynik+=tab[b];
  }
  while(a/2!=b/2)
  {
    if(a%2==0)wynik+=tab[a+1];
    if(b%2==1)wynik+=tab[b-1];
    a/=2;
    b/=2;
  }
  return wynik;
}
int main() {
  int n,q,a,b,zn,v,x;
  cin>>n>>q;
for(int i=0;i<n;i++)
  {
      cin>>x;
      insert(i,x);



  }

for(int i=0;i<q;i++)
{
cin>>zn;
if(zn==1)
{
  cin>>a>>b;
  cout<<query(a-1,b-1)<<endl;
}
else
{
    int odej;

    cin>>a>>v;
    odej=tab[a-1+M];
  insert_po(a-1,v,odej);
}


}

}
/*
8 3
8 2 4 3 2 1 7 5
*/
