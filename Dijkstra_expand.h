#include <vector>
#include <queue>
using namespace std;


struct Node{
  int now;
  int sub;
  long cost;
};

struct Edge{
  int from;
  int to;
  long cost;
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

vector<vector<long>> Dijkstra(vector<vector<Edge>> &Graph, int start, int start_sub, int sub_max){ //最小コスト
  priority_queue<Node, vector<Node>, greater<Node>> que;
  vector<vector<long>> dist(Graph.size(), vector<long>(sub_max, 1e16));

  dist.at(start).at(start_sub) = 0;
  que.push(Node{start, start_sub, 0});

  while(que.size()){
    Node node = que.top();
    que.pop();
    int v = node.now;
    int sv = node.sub;
    if(node.cost > dist.at(v).at(sv)) continue;
    for(Edge edge : Graph.at(v)){
      int nv = edge.to;
      long cost = edge.cost;
      int nsv; //edit------------------------------------------
      if(dist.at(nv).at(nsv) > dist.at(v).at(sv) + cost){
        dist.at(nv).at(nsv) = dist.at(v).at(sv) + cost;
        que.push(Node{nv, nsv, dist.at(nv).at(nsv)});
      }
    }
  }
  return dist;
}
