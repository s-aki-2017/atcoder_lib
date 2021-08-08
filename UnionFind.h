#include <vector>
using namespace std;
using ll = ll;

vector<ll> par;

void Initpar(ll n){
  par = vector<ll>(n); 
  for(ll i=0; i<n; i++) par.at(i) = i;
}

ll root(ll x){
  if(x == par.at(x)) return x;
  else return par.at(x) = root(par.at(x));
}

void unite(ll x, ll y){
  ll rx = root(x);
  ll ry = root(y);
  if(rx == ry) return ;
  if(rx < ry) par.at(ry) = rx;
  else par.at(rx) = ry;
}

bool same(ll x, ll y){
  return root(x) == root(y);
}

void update_par(){
  for(ll i=0;i<par.size();i++){
    root(i);
  }
}