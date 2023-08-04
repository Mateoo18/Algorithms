//Zliczanie wiekosci poddrzew
//Mateusz Nowak
#include <bits/stdc++.h>
 
using namespace std;
 
vector<vector<int> > g(1e6);
vector<int> treeSize(1e6);
 
 
int dfs(int s, int p) {
    int sum = 0;
 
    for(auto I : g[s]) {
        if(I != p) {
            sum += dfs(I, s);
        }
    }
    treeSize[s] = sum+1;
    return sum+1;
}
 
int main() {
    int n, a, b;
    cin >> n;
 
    for(int i = 0;i < n-1;++i) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int q;
    dfs(1, -1);
    cin >> q;
 
 
    while(q --> 0) {
        cin >> a >> b;
        if(treeSize[a] < treeSize[b])
            swap(a, b);
        cout << "Z " << b << " mozna dojsc do " << treeSize[b]-1 << " wierzcholkow." << endl;
        cout << "Z " << a << " mozna dojsc do " << treeSize[a]-treeSize[b]-1 << " wierzcholkow." << endl;
 
    }
 
    for(int i = 1;i <= n;++i) {
        cout << endl << endl << "Rozmiar podrzewa " << i << " wynosi: " << treeSize[i] << endl;
    }
 
 
 
    return 0;
}
