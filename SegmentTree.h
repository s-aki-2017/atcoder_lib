#include <iostream>
#include <vector>
using namespace std;
using ll = int;
const bool multicase = 0;

ll N;
vector<ll> value;
vector<ll> delay;
ll MONO = 1e16; //単位元

void update(ll i, ll x){
  i += N-1;
  value.at(i) = x; //更新方法
  while(i > 0){
    i = (i-1)/2;
    ll c1 = value.at(i*2 + 1);
    ll c2 = value.at(i*2 + 2);
    value.at(i) = min(c1, c2); //min max 切り替え可能
  }
}

void eval(ll k, ll l, ll r){
  if(delay.at(k) != 0){
    value.at(k) += delay.at(k);
    if(r - l > 1){
      delay.at(2*k+1) = delay.at(k)/2;
      delay.at(2*k+2) = delay.at(k)/2;
    }
    delay.at(k) = 0;
  }
}

void add_range(ll a, ll b, ll k, ll l, ll r, ll x){ //[a,b)が追加したい区間
  eval(k, l, r);
  if(r <= a || b <= l) return;
  if(a <= l && r <= b){
    delay.at(k) += (r - l) * x;
    eval(k, l, r);
  }else{
    add_range(a, b, 2*k+1, l, (l+r)/2, x);
    add_range(a, b, 2*k+2, (l+r)/2, r, x);
    value.at(k) = value.at(2*k+1) + value.at(2*k+2);
  }
}

ll query(ll a, ll b, ll k, ll l, ll r){ //[a,b)が知りたい区間 [l,r)は初め0,N代入 k=0 現ノード
  if(r <= a || b <= l) return MONO;
  eval(k, l, r);
  if(a <= l && r <= b) return value.at(k);
  else{
    ll c1 = query(a, b, 2*k+1, l, (l+r)/2);
    ll c2 = query(a, b, 2*k+2, (l+r)/2, r);
    return min(c1, c2); //min max 切り替え可能
  }
}

void Solve(){
  ll n;
  cin >> n;
  N = 1;
  while (N < n) N *= 2; // 葉の数を計算（n以上の最小の2冪数）
  value = vector<ll>(2 * N - 1, MONO);
  delay = vector<ll>(2 * N - 1, 0);
}



//do not touch
int main(){ll t;if(multicase){cin >> t;}else{t = 1;}while(t){Solve();t--;}}