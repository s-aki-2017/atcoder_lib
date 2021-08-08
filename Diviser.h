#include <vector>
using namespace std;
using ll = int;


vector<ll> Divisor(ll n){ // nの約数をrouteNまで出す
  vector<ll> div;
  for(ll i=1; i*i <= n; i++){
    if(n % i != 0) continue;
    div.push_back(i);
    //div.push_back(n/i);
  }
  //sort(div.begin(), div.end());
  return div;
}