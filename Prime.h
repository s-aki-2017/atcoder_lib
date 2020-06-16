#include <vector>
using namespace std;



vector<bool> prime_vec(long n){ //2からnまでの素数を列挙した配列
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