#include<string>
#include<vector>
using namespace std;


// 4と9を含まない数字の組合せ
long dp[100][2];
// 各桁の総和を知りたい場合は引数にsum,判定にsum==D
long rec(string &s, int k=0, bool tight=true){
  if(k == s.size()){
    //条件によって返す値が決まる
    return 1;
  }

  int m = s.at(k) - '0'; //k桁目の数字

  if(dp[k][tight] != -1) return dp[k][tight];

  int x = (tight ? m : 9);
  long res = 0;
  for(int i=0; i<=x; i++){
    //if(i == 4 || i == 9) continue;
    res += rec(s, k+1, i==x && tight);
  }

  return dp[k][tight] = res;
}// 結果がおかしいときはだいたい0を含んでいるかどうか

void dpInit(long value, int a = 1, int b = 1, int c = 1){
  for(int i=0; i<a; i++){
    for(int j=0; j<b; j++){
      for(int k=0; k<c; k++){
        dp[i][j] = value; 
      }
    }
  }
}