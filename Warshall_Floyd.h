#include <vector>
using namespace std;

void Warshall_Floyd(vector<vector<long>> &dist){
  int n = dist.size();
  for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        dist.at(i).at(j) = min(dist.at(i).at(j), dist.at(i).at(k) + dist.at(k).at(j));
      }
    }
  }
  return;
}