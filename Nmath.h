#include <vector>
#include <algorithm>
using namespace std;


class Nmath{
  //コンストラクタ1個の数字を代入すればなんでもよい
  private:
    long __n;
  public:
    Nmath(long _n){
      __n = _n;
    }
    vector<bool> is_prime_vec(long n){
      vector<bool> vec(n,true);
      vec.at(0) = false;
      vec.at(1) = false;
      for(int i=2; i<n; i++){
          if(vec.at(i)){
              for(int j=2; i*j<n; j++){
                  vec.at(i*j) = false;
              }
          }
      }
      return vec;
    }
    
    vector<long> diviser(long n){
      vector<long> vec;
      for(long i=1; i*i<=n; i++){
        if(n % i != 0) continue;
        vec.push_back(i);
      }
      return vec;
    }

};