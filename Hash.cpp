//Mateusz Nowak
#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int N = 1e6;
const LL BASE = 27;
const LL MOD = 1e9 + 696969;

LL sHash[N];
LL pow27[N];

LL calcHash(string s) {
    LL hash = 0;

    for(char I : s) {
        hash *= BASE;
       // cout<<"hash "<<hash<<endl;
        hash += I-'a'+1;
        hash %= MOD;
    }

    return hash;
}
int main()
{
string a,b;
int w=0,wynik=0;
cin>>a>>b;
LL wHash= calcHash(a);
int res=0;
for(unsigned int i=0;i<b.length()-a.length()+1;i++)
{
    string t=b.substr(i,a.length());
    LL sHash=calcHash(t);
    if(wHash==sHash)
    {
        res++;
    }
}
cout<<res<<endl;
}
