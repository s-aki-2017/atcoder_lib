#include <bits/stdc++.h>
using namespace std;
using ll = int;
using vl = vector<ll>;
using vvl = vector<vl>;


vvl Graph(100010);
vector<ll> dist(100010,0);
vvl ances(100010,vl(20));


void dfs(ll v, ll pv = -1, ll d=0){
  ances.at(v).at(0) = (pv == -1 ? 0 : pv);
  dist.at(v) = d;
  for(ll nv : Graph.at(v)){
    if(nv == pv) continue;
    dfs(nv,v,d+1);
  }
}

void ancestor(ll n){
  for(ll i=1;i<20;i++){
    for(ll j=0;j<n;j++){
      ll tmpv = ances.at(j).at(i-1);
      ances.at(j).at(i) = ances.at(tmpv).at(i-1);
    }
  }
}

ll query(ll a, ll b){
  if(dist.at(a) < dist.at(b)) swap(a,b);
  ll d0 = dist.at(a) - dist.at(b);
  ll na = a;
  bitset<20> s(d0);
  for(ll i=0;i<20;i++){
    if(s.test(i)){
      na = ances.at(na).at(i);
    }
  }
  if(na == b) return d0 + 1;
  ll nb = b;
  for(ll i=19;i>=0;i--){
    ll ta = ances.at(na).at(i);
    ll tb = ances.at(nb).at(i);
    if(ta != tb){
      na = ta;
      nb = tb;
    }
  }
  ll d = dist.at(nb) - dist.at(b) + 1;
  return d + d + d0 + 1;
}