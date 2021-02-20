#include <iostream>
#include <vector>
using namespace std;

int N;
vector<long> value;
vector<long> delay;
long MONO = 1e16; //単位元

void update(int i, long x){
  i += N-1;
  value.at(i) = x; //更新方法
  while(i > 0){
    i = (i-1)/2;
    long c1 = value.at(i*2 + 1);
    long c2 = value.at(i*2 + 2);
    value.at(i) = min(c1, c2); //min max 切り替え可能
  }
}

void eval(int k, int l, int r){
  if(delay.at(k) != 0){
    value.at(k) += delay.at(k);
    if(r - l > 1){
      delay.at(2*k+1) = delay.at(k)/2;
      delay.at(2*k+2) = delay.at(k)/2;
    }
    delay.at(k) = 0;
  }
}

void add_range(int a, int b, int k, int l, int r, long x){ //[a,b)が追加したい区間
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

long query(int a, int b, int k, int l, int r){ //[a,b)が知りたい区間 [l,r)は初め0,N代入 k=0 現ノード
  if(r <= a || b <= l) return MONO;
  eval(k, l, r);
  if(a <= l && r <= b) return value.at(k);
  else{
    long c1 = query(a, b, 2*k+1, l, (l+r)/2);
    long c2 = query(a, b, 2*k+2, (l+r)/2, r);
    return min(c1, c2); //min max 切り替え可能
  }
}

int main(){
  int n;
  cin >> n;
  N = 1;
  while (N < n) N *= 2; // 葉の数を計算（n以上の最小の2冪数）
  value = vector<long>(2 * N - 1, MONO);
  delay = vector<long>(2 * N - 1, 0);
}