#include <vector>
#include <queue>
using namespace std;

struct Node{
  int now;
  //int sub;
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
//sは始点
vector<long> Dijkstra(vector<vector<Edge>> &Graph, int s){ //最小コスト
  priority_queue<Node, vector<Node>, greater<Node>> que;
  vector<long> dist(Graph.size(), 1e16);

  dist.at(s) = 0;
  que.push(Node{s, 0});

  while(que.size()){
    Node node = que.top();
    que.pop();
    int v = node.now;
    if(node.cost > dist.at(v)) continue;
    for(Edge edge : Graph.at(v)){
      int nv = edge.to;
      long cost = edge.cost;
      if(dist.at(nv) > dist.at(v) + cost){
        dist.at(nv) = dist.at(v) + cost;
        que.push(Node{nv, dist.at(nv)});
      }
    }
  }
  for(int i=0;i<dist.size();i++){
    if(dist.at(i) > 9*1e15) dist.at(i) = -1;
  }
  return dist;
}