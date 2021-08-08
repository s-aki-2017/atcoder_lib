#include <vector>
using namespace std;
using ll = int;

void Init_Dubling(vector<vector<ll>> &next, ll d){
  ll n = next.size();
  
  for(ll i=1;(1<<i) <= d;i++){
    for(ll j=0;j<n;j++){
      ll nj = next.at(j).at(i-1);
      next.at(j).at(i) = next.at(nj).at(i-1);
    }
  }
}

ll res_Dubing(vector<vector<ll>> &next, ll d, ll v){
  ll nv = v;
  for(ll i=0;(1<<i) <= d;i++){
    if( (1<<i) & d ){
      nv = next.at(nv).at(i);
    }
  }
  return nv;
}