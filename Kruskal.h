#include <vector>
#include <algorithm>
using namespace std;

vector<int> par;
//vector<Edge> Edges;
//vector<vector<Edge>> MinTree;

struct Edge{
  int from;
  int to;
  long cost;

  bool operator<(const Edge& o) const {
    return cost < o.cost;
  }
};

void Initpar(int n){
  par = vector<int>(n); 
  for(int i=0; i<n; i++) par.at(i) = i;
}

int root(int x){
  if(x == par.at(x)) return x;
  else par.at(x) = root(par.at(x));
}

void unite(int x, int y){
  int rx = root(x);
  int ry = root(y);
  if(rx == ry) return;
  par.at(ry) = rx;
}

bool same(int x, int y){
  return root(x) == root(y);
}

long Kruskal(vector<vector<Edge>> &MinTree, vector<Edge> &Edges){
  sort(Edges.begin(), Edges.end());
  int m = Edges.size();
  long sum_cost = 0;
  for(int i=0;i<m;i++){
    Edge ed = Edges.at(i);
    int v = ed.from;
    int nv = ed.to;
    if(same(v, nv)) continue;
    unite(v, nv);
    sum_cost += ed.cost;
    MinTree.at(v).push_back({v, nv, ed.cost});
    MinTree.at(nv).push_back({nv, v, ed.cost});
  }
  return sum_cost;
}