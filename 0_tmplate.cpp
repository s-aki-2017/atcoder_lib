#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
using ll = long long;
using vb = vector<bool>;
using vc = vector<char>;
using vl = vector<ll>;
using vs = vector<string>;
using vd = vector<double>;
using vvb = vector<vector<bool>>;
using vvc = vector<vector<char>>;
using vvl = vector<vector<ll>>;
using pll = pair<ll, ll>;
using pdd = pair<double,double>;
#define fix20 cout << fixed << setprecision(20)
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define rep(i,n) for(ll i=0; i<(ll)(n);i++)
#define REP(i,s,t) for(ll i=s; i<t; i++)
#define RNG(i,s,t,u) for(ll i=s; i<t; i+=u)
#define MOD 1000000007
//#define MOD 998244353
#define all(vec) vec.begin(), vec.end()
#define pri(x) cout << x << endl
#define prie(x) cout << x << " "
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> void vin(vector<T>& a,ll n){rep(i,n){cin>>a.at(i);}}
template<class T> void vout(vector<T>& a,ll n){rep(i,n-1){prie(a.at(i));}if(n>0)pri(a.at(n-1));}

const ll inf = 4000000000000000000;
const double PI = acos(-1.0);
const bool multicase = 0;
struct Edge{
    ll from;
    ll to;
    ll cost;
};
vector<vector<Edge>> G;

void Solve(){
}



//do not touch
int main(){ll t;if(multicase){cin >> t;}else{t = 1;}while(t){Solve();t--;}}