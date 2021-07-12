using namespace std;

long binary_search(long left, long right){ //左右でTFを分けるもの
    while(right - left > 1){
        long mid = (left + right) / 2; //左寄り
        //long mid = (left + right + 1) / 2; //右寄り 左右でFTの場合

        if(1) left = mid; //
        else right = mid; //

    }
    return right; //右がtrue
    return left; //左がfalse
}
