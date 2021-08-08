#include <vector>
using namespace std;
using ll = int;

ll Syakutori(vector<ll> &d, ll n, ll k){
  ll len = 0;
  ll tmp = 1; //default value
  //ll ans = 0;
  for(ll s=0,t=0; t<n; t++){ //s<= and <=t
    //tmp *= d.at(t); //front
    //tmp += d.at(t); //front
    while(tmp < k && s <= t){
      //tmp /= d.at(s); //back
      s++;
    }
    len = max(len, t-s+1); //lens
    //ans += t-s+1; //count 
  }
  return len;
}