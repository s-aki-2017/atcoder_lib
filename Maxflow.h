#include<vector>
using namespace std;

struct Edge{
  int to;
  long cap;
  int rev;
};

void add_edge(vector<vector<Edge>> &Graph, int from, int to, long cap){
  Graph.at(from).push_back({to, cap, Graph.at(to).size()});
  Graph.at(to).push_back({from, 0, Graph.at(from).size()-1});
}

long dfs(vector<vector<Edge>> &Graph, vector<bool> &seen, int v, int t, long f){
  if(v == t) return f;
  seen.at(v) = true;
  for(Edge &ed : Graph.at(v)){
    int nv = ed.to;
    if(seen.at(nv) || ed.cap == 0) continue;
    long d = dfs(Graph, seen, nv, t, min(f, ed.cap));
    //assert(d >= 0); //assert
    if(d > 0){
      ed.cap -= d;
      Graph.at(nv).at(ed.rev).cap += d;
      return d;
    }
  }
  return 0;
}

long Maxflow(vector<vector<Edge>> &Graph, int s, int t){
  long sum = 0;
  while(1){
    vector<bool> seen(Graph.size(), false);
    long f = dfs(Graph, seen, s, t, 1e16);
    if(f == 0) return sum;
    sum += f;
    //assert(f > 0); //assert
    //assert(sum > 0); //assert
  }
}

