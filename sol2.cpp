#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> AL;                           
vi taken;                                 
priority_queue<ii> pq;

class UnionFind {                              
private:
  vi p, rank, setSize;                         
public:
  UnionFind(int N) {
    p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
    rank.assign(N, 0);                         
    setSize.assign(N, 1);                                                    
  }

  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

  void unionSet(int i, int j) {
    if (isSameSet(i, j)) return;                 
    int x = findSet(i), y = findSet(j);          
    if (rank[x] > rank[y]) swap(x, y);           
        p[x] = y;                                    
    if (rank[x] == rank[y]) ++rank[y];           
        setSize[y] += setSize[x];                                                      
  }

  // cantidad total de ciudades que no pertenecen 
  // a la misma componente conexa del 1 index-1
  int cantCitiesDisconected(int totalCities){
      int rootPrincipalCity = findSet(0);
      int c = 0;

      for (int i = 0; i < totalCities; i++){
          if (findSet(i) != rootPrincipalCity) c++;
      }

      return c;
  }
};

void process(int u) { 
  taken[u] = 1;
  for (auto &[v, w] : AL[u])
    if (!taken[v])
      pq.push({-w, -v});                         
}    

int main() {
    int n, p, l; 
    cin >> n >> p >> l;

    int calc = (n * (n-1)) / 2;

    AL.assign(n, vii());
    UnionFind UF(n);

    for (int i = 0; i < calc; i++){
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        if (w <= l){
            AL[u].emplace_back(v, w);
            AL[v].emplace_back(u, w);
            UF.unionSet(u, v);
        }
    }

    taken.assign(n, 0);
    process(0);

    long long mst_cost = 0, num_taken = 0;
    while (!pq.empty()) {                          
        auto [w, u] = pq.top(); pq.pop();          
        w = -w; u = -u;                            
        if (taken[u]) continue;                    
        mst_cost += w;                             
        process(u);                                
        ++num_taken;                               
        if (num_taken == n-1) break;               
    }
    
    cout << p*mst_cost << ' ' << UF.cantCitiesDisconected(n) << '\n';

    return 0;
}
