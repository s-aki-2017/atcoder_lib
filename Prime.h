#include <vector>
using namespace std;
using ll = int;


vector<bool> prime_vec(ll n){ //2からnまでの素数を列挙した配列
    vector<bool> vec(n,true);
    vec.at(0) = false;
    vec.at(1) = false;
    for(ll i=2; i<n; i++){
        if(vec.at(i)){
            for(ll j=2; i*j<n; j++){
                vec.at(i*j) = false;
            }
        }
    }
    return vec;
}