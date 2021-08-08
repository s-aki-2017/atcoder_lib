using namespace std;
using ll = int;

bool check(ll m){
    //
}

ll binary_search(ll left, ll right){ //左右でTFを分けるもの
    while(right - left > 1){
        ll mid = (left + right) / 2; //左寄り
        //ll mid = (left + right + 1) / 2; //右寄り 左右でFTの場合

        if(check(mid)) left = mid; //
        else right = mid; //

    }
    return right; //右がtrue
    return left; //左がfalse
}
