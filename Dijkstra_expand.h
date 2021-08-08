#include <vector>
#include <queue>
using namespace std;
using ll = int;

struct Node{
  ll now;
  ll sub;
  ll cost;
};

struct Edge{
  ll from;
  ll to;
  ll cost;
};

bool operator<(const Node &a, const Node &b){
  if(a.cost != b.cost){
    return a.cost < b.cost;
  }else{
    return a.now < b.now;
  }
}
bool operator>(const Node &a, const Node &b){return (b < a);}
bool operator<=(const Node &a, const Node &b){return !(b < a);}
bool operator>=(const Node &a, const Node &b){return !(a < b);}

//vector<vector<Edge>> Graph(n);

vector<vector<ll>> Dijkstra(vector<vector<Edge>> &Graph, ll start, ll start_sub, ll sub_max){ //最小コスト
  priority_queue<Node, vector<Node>, greater<Node>> que;
  vector<vector<ll>> dist(Graph.size(), vector<ll>(sub_max, 1e16));

  dist.at(start).at(start_sub) = 0;
  que.push(Node{start, start_sub, 0});

  while(que.size()){
    Node node = que.top();
    que.pop();
    ll v = node.now;
    ll sv = node.sub;
    if(node.cost > dist.at(v).at(sv)) continue;
    for(Edge edge : Graph.at(v)){
      ll nv = edge.to;
      ll cost = edge.cost;
      ll nsv; //edit------------------------------------------
      if(dist.at(nv).at(nsv) > dist.at(v).at(sv) + cost){
        dist.at(nv).at(nsv) = dist.at(v).at(sv) + cost;
        que.push(Node{nv, nsv, dist.at(nv).at(nsv)});
      }
    }
  }
  return dist;
}
