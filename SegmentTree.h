#include <vector>
using namespace std;

int N;
vector<int> value;

void update(int i){
  i += N-1;
  while(i > 0){
    i = (i-1)/2;
    int c1 = value.at(i*2 + 1);
    int c2 = value.at(i*2 + 2);
    value.at(i) = min(c1, c2);
  }
}

int query(int a, int b, int k, int l, int r){
  if(r <= a || b <= l) return 1e8;
  if(a <= l && r <= b) return value.at(k);
  else{
    int c1 = query(a, b, 2*k+1, l, (l+r)/2);
    int c2 = query(a, b, 2*k+2, (l+r)/2, r);
    return min(c1, c2);
  }
}