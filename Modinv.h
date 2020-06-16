#include <vector>
using namespace std;

//aの素数modを法とした逆元を求める
long Modinv(long a, long mod){
    vector<long> res(32);
    res.at(0) = a % mod;
    for(int i=1;i<32;i++){
        res.at(i) = res.at(i-1)*res.at(i-1) % mod;
    }
    long ans = 1;
    for(int i=0;i<res.size();i++){
        if((1<<i)&(mod-2)){
            ans *= res.at(i);
            ans %= mod;
        }
    }
    return ans;
}