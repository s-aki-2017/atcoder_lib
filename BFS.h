#include<queue>
using namespace std;
using ll = int;


void bfs(vector<vector<char>> &data, ll sx, ll sy){
  ll h = data.size();
  ll w = data.at(0).size();
  queue<pair<ll,ll>> que;
  vector<vector<ll>> dist(h, vector<ll>(w, -1));
  que.push(pair<ll,ll>(sx, sy));
  dist.at(sx).at(sy) = 0;

  ll dx[4] = {1, -1, 0, 0};
  ll dy[4] = {0, 0, 1, -1};

  while(que.size()){
    pair<ll,ll> P = que.front();
    ll x = P.first;
    ll y = P.second;
    que.pop();
    for(ll i=0;i < 4;i++){
      ll nx = x + dx[i];
      ll ny = y + dy[i];
      if(nx < 0 || h <= nx || ny < 0 || w <= ny) continue;
      if(data.at(nx).at(ny) == '#') continue;
      if(dist.at(nx).at(sy) != -1) continue;
      dist.at(nx).at(ny) = dist.at(x).at(y) + 1;
      que.push(pair<ll,ll>(nx,ny));
    }
  }
}