#include <iostream>
using namespace std;
#define MOD 1000000007;
using ll = long long;



ll powMod(ll x, ll n) {
  if (n == 0) return 1 % MOD;
  ll val = powMod(x, n / 2);
  val %= MOD;
  val *= val;
  val %= MOD;
  if (n % 2 == 1) val *= x;
  return val % MOD;
}
