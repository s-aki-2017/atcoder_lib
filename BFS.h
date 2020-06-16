#include<queue>
using namespace std;


void bfs(vector<vector<char>> &data, int sx, int sy){
  int h = data.size();
  int w = data.at(0).size();
  queue<pair<int,int>> que;
  vector<vector<long>> dist(h, vector<long>(w, -1));
  que.push(pair<int,int>(sx, sy));
  dist.at(sx).at(sy) = 0;

  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};

  while(que.size()){
    pair<int,int> P = que.front();
    int x = P.first;
    int y = P.second;
    que.pop();
    for(int i=0;i < 4;i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx < 0 || h <= nx || ny < 0 || w <= ny) continue;
      if(data.at(nx).at(ny) == '#') continue;
      if(dist.at(nx).at(sy) != -1) continue;
      dist.at(nx).at(ny) = dist.at(x).at(y) + 1;
      que.push(pair<int,int>(nx,ny));
    }
  }
}