#include <vector>
#include <algorithm>
using namespace std;
using ll = int;

vector<ll> par;
//vector<Edge> Edges;
//vector<vector<Edge>> Mllree;

struct Edge{
  ll from;
  ll to;
  ll cost;

  bool operator<(const Edge& o) const {
    return cost < o.cost;
  }
};

void Initpar(ll n){
  par = vector<ll>(n); 
  for(ll i=0; i<n; i++) par.at(i) = i;
}

ll root(ll x){
  if(x == par.at(x)) return x;
  else par.at(x) = root(par.at(x));
}

void unite(ll x, ll y){
  ll rx = root(x);
  ll ry = root(y);
  if(rx == ry) return;
  par.at(ry) = rx;
}

bool same(ll x, ll y){
  return root(x) == root(y);
}

ll Kruskal(vector<vector<Edge>> &Mllree, vector<Edge> &Edges){
  sort(Edges.begin(), Edges.end());
  ll m = Edges.size();
  ll sum_cost = 0;
  for(ll i=0;i<m;i++){
    Edge ed = Edges.at(i);
    ll v = ed.from;
    ll nv = ed.to;
    if(same(v, nv)) continue;
    unite(v, nv);
    sum_cost += ed.cost;
    Mllree.at(v).push_back({v, nv, ed.cost});
    Mllree.at(nv).push_back({nv, v, ed.cost});
  }
  return sum_cost;
}