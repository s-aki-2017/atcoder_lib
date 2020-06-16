#include<vector>
#include<algorithm>
using namespace std;


//最長増加部分列LIS
vector<long> LIS(vector<long> &ref){
  int n = ref.size();
  vector<long> dp(n+10, 1e18);
  dp.at(0) = -1e18;
  for(int i=0;i<n;i++){
    int iter = upper_bound(dp.begin(), dp.end(), ref.at(i)) - dp.begin();
    if(dp.at(iter-1) == ref.at(i)) iter--; //被りの場合はひとつ前
    dp.at(iter) = ref.at(i);
  } 
  return dp;
}