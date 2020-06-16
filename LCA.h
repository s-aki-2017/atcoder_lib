#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<long>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvb = vector<vector<bool>>;
using vvc = vector<vector<char>>;
using pii = pair<int, int>;
using pil = pair<int, long>;
using pll = pair<long, long>;
#define fix20 cout << fixed << setprecision(20)
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define REP(i,s,t) for(int i=s; i<t; i++)
#define RNG(i,s,t,u) for(int i=s; i<t; i+=u)
#define MOD 1000000007
#define all(vec) vec.begin(), vec.end()

vvi Graph(100010);
vector<int> dist(100010,0);
vvi ances(100010,vi(20));


void dfs(int v, int pv = -1, int d=0){
  ances.at(v).at(0) = (pv == -1 ? 0 : pv);
  dist.at(v) = d;
  for(int nv : Graph.at(v)){
    if(nv == pv) continue;
    dfs(nv,v,d+1);
  }
}

void ancestor(int n){
  for(int i=1;i<20;i++){
    for(int j=0;j<n;j++){
      int tmpv = ances.at(j).at(i-1);
      ances.at(j).at(i) = ances.at(tmpv).at(i-1);
    }
  }
}

int query(int a, int b){
  if(dist.at(a) < dist.at(b)) swap(a,b);
  int d0 = dist.at(a) - dist.at(b);
  int na = a;
  bitset<20> s(d0);
  for(int i=0;i<20;i++){
    if(s.test(i)){
      na = ances.at(na).at(i);
    }
  }
  if(na == b) return d0 + 1;
  int nb = b;
  for(int i=19;i>=0;i--){
    int ta = ances.at(na).at(i);
    int tb = ances.at(nb).at(i);
    if(ta != tb){
      na = ta;
      nb = tb;
    }
  }
  int d = dist.at(nb) - dist.at(b) + 1;
  return d + d + d0 + 1;
}