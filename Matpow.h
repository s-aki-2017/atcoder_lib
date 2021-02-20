#include<iostream>
#include<vector>
#include<bitset>
using namespace std;

void COUT(vector<vector<long>> &mat){
    long s = mat.size();
    for(int i=0;i<s;i++){
        for(int j=0;j<s;j++){
            cout << mat.at(i).at(j) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void Initmat(vector<vector<long>> &mat){
  long n = mat.size();
  for(int i=0;i<n;i++){
      mat.at(i).at(i) = 1;
  }
}

void multmat(vector<vector<long>> &ret, vector<vector<long>> mat1, vector<vector<long>> mat2){
    long m = mat1.size();
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            long tmp = 0;
            for(int k=0;k<m;k++){
                tmp += mat1.at(i).at(k) * mat2.at(k).at(j);
                //tmp %= MOD;
            }
            ret.at(i).at(j) = tmp;
        }
    }
}

vector<vector<long>> matpow(vector<vector<long>> mat, long exp){
    long n = mat.size();
    vector<vector<long>> ret(n,vector<long>(n,0));
    for(int i=0;i<n;i++) ret.at(i).at(i) = 1;
    bitset<60> bt(exp);
    for(int i=0;i<60;i++){
        if(bt.test(i)){
            multmat(ret,ret,mat);
            //COUT(ret);
        }
        multmat(mat,mat,mat); //ret = A x B
    }
    return ret;
}