#include <vector>
using namespace std;



vector<long> Divisor(long n){ // nの約数をrouteNまで出す
  vector<long> div;
  for(long i=1; i*i <= n; i++){
    if(n % i != 0) continue;
    div.push_back(i);
    //div.push_back(n/i);
  }
  //sort(div.begin(), div.end());
  return div;
}