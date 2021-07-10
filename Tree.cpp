#include <bits/stdc++.h>
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

class Tree{
    public:
        struct Edge{
            ll from;
            ll to;
            ll cost;
        };
        ll n;
        vector<vector<Edge>> graph;

        Tree(ll _n){
            n = _n;
            graph = vector<vector<Edge>>(n);
        }

        void add_edge(ll a, ll b, ll c){
            graph.at(a).push_back(Edge{a, b, c});
        }

        void tree_dfs(ll v, ll pv, ll d, vector<ll> &depth){
            depth.at(v) = d;
            for(Edge ed : graph.at(v)){
                ll nv = ed.to;
                if(nv == pv) continue;
                tree_dfs(nv, v, d+1, depth);
            }
        }

        vector<ll> tree_depth(ll s = 0){
            vector<ll> depth(n);
            tree_dfs(s, -1, 0, depth);
            return depth;
        }
};