#include <bits/stdc++.h>
using namespace std;
using ll = int;


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
