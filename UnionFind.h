#include <vector>
using namespace std;

vector<int> par;

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
  if(rx == ry) return ;
  if(rx < ry) par.at(ry) = rx;
  else par.at(rx) = ry;
}

bool same(int x, int y){
  return root(x) == root(y);
}

void update_par(){
  for(int i=0;i<par.size();i++){
    root(i);
  }
}