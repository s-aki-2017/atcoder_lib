#include<string>
#include<vector>
using namespace std;
using ll = int;


// 4と9を含まない数字の組合せ
ll dp[100020][2];
// 各桁の総和を知りたい場合は引数にsum,判定にsum==D
ll rec(string &s, ll k=0, bool tight=true){
  if(k == s.size()){
    //条件によって返す値が決まる
    return 1;
  }

  ll m = s.at(k) - '0'; //k桁目の数字

  if(dp[k][tight] != -1) return dp[k][tight];

  ll x = (tight ? m : 9);
  ll res = 0;
  for(ll i=0; i<=x; i++){
    //if(i == 4 || i == 9) continue;
    res += rec(s, k+1, i==x && tight);
  }

  return dp[k][tight] = res;
}// 結果がおかしいときはだいたい0を含んでいるかどうか、1以上の整数か0以上の整数か

void dpInit(ll value, ll a = 1, ll b = 1, ll c = 1){
  for(ll i=0; i<a; i++){
    for(ll j=0; j<b; j++){
      for(ll k=0; k<c; k++){
        dp[i][j] = value; 
      }
    }
  }
}
