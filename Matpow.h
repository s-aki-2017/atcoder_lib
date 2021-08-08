#include<iostream>
#include<vector>
#include<bitset>
using namespace std;
using ll = int;

void COUT(vector<vector<ll>> &mat){
    ll s = mat.size();
    for(ll i=0;i<s;i++){
        for(ll j=0;j<s;j++){
            cout << mat.at(i).at(j) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void Initmat(vector<vector<ll>> &mat){
  ll n = mat.size();
  for(ll i=0;i<n;i++){
      mat.at(i).at(i) = 1;
  }
}

void multmat(vector<vector<ll>> &ret, vector<vector<ll>> mat1, vector<vector<ll>> mat2){
    ll m = mat1.size();
    for(ll i=0;i<m;i++){
        for(ll j=0;j<m;j++){
            ll tmp = 0;
            for(ll k=0;k<m;k++){
                tmp += mat1.at(i).at(k) * mat2.at(k).at(j);
                //tmp %= MOD;
            }
            ret.at(i).at(j) = tmp;
        }
    }
}

vector<vector<ll>> matpow(vector<vector<ll>> mat, ll exp){
    ll n = mat.size();
    vector<vector<ll>> ret(n,vector<ll>(n,0));
    for(ll i=0;i<n;i++) ret.at(i).at(i) = 1;
    bitset<60> bt(exp);
    for(ll i=0;i<60;i++){
        if(bt.test(i)){
            multmat(ret,ret,mat);
            //COUT(ret);
        }
        multmat(mat,mat,mat); //ret = A x B
    }
    return ret;
}