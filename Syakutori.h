#include <vector>
using namespace std;


int Syakutori(vector<long> &d, int n, int k){
  int len = 0;
  long tmp = 1; //default value
  //long ans = 0;
  for(int s=0,t=0; t<n; t++){ //s<= and <=t
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