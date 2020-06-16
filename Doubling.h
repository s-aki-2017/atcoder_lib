#include <vector>
using namespace std;

void Init_Dubling(vector<vector<long>> &next, long d){
  int n = next.size();
  
  for(long i=1;(1<<i) <= d;i++){
    for(int j=0;j<n;j++){
      long nj = next.at(j).at(i-1);
      next.at(j).at(i) = next.at(nj).at(i-1);
    }
  }
}

long res_Dubing(vector<vector<long>> &next, long d, long v){
  long nv = v;
  for(long i=0;(1<<i) <= d;i++){
    if( (1<<i) & d ){
      nv = next.at(nv).at(i);
    }
  }
  return nv;
}