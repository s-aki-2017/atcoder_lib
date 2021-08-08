#include<vector>
#include<algorithm>
using namespace std;
using ll = int;


//最長増加部分列LIS (より大きい版
vector<ll> LIS(vector<ll> &ref){
  ll n = ref.size();
  vector<ll> dp(n+10, 1e18);
  dp.at(0) = -1e18;
  for(ll i=0;i<n;i++){
    ll iter = upper_bound(dp.begin(), dp.end(), ref.at(i)) - dp.begin();
    if(dp.at(iter-1) == ref.at(i)) iter--; //被りの場合はひとつ前 (<=以上の場合はここを消す
    dp.at(iter) = ref.at(i);
  } 
  return dp;
}