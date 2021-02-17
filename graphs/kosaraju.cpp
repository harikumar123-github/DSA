#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef stack<ll> stll;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
typedef vector<vll> vvll;

#define FOR(i,s,e) for(ll i=s;i<e;i++)
#define mp make_pair
#define pb push_back
#define fi first
#define sec second
#define in insert
#define sz size
#define ln length
#define vec vector
#define all(v) v.begin(),v.end()
#define allg(v) v.begin(),v.end(),greater<ll>()
#define nl() cout << "\n"
#define mst(a) memset(a,-1,sizeof(a))
#define endl "\n"
#define debug(z) cout << #z << "=" << z << endl
#define MAX ll(1e9+7)

void solve();

void dfs_st(ll r,vb &vis,vvll &v,stll &st){
    vis[r]=true;
    for(auto i:v[r]){
        if(!vis[i])
            dfs_st(i,vis,v,st);
    }
    st.push(r);
}

void dfs(ll r,vb &vis,vvll &v){
    vis[r]=true;
    cout << r << " ";
    for(auto i:v[r]){
        if(!vis[i])
            dfs(i,vis,v);
    }
}

void solve(){
    ll n,e;
    cin >> n >> e;
    vvll v(n+1);
    vvll tv(n+1);
    FOR(i,0,e){
        ll a,b;
        cin >> a >> b;
        v[a].pb(b);
    }
    FOR(i,1,n+1){
        for(auto j:v[i]){
            tv[j].pb(i);
        }
    }
    vb vis(n+1,false),sv(n+1,false);
    stll st;
    for(ll i=1;i<=n;i++){
        if(!vis[i])
            dfs_st(i,vis,v,st);
    }
    stll st1=st;
    while(!st1.empty()){
        cout << st1.top() << " ";
        st1.pop();
    }
    nl();
    while(!st.empty()){
        ll p=st.top();
        st.pop();
        if(!sv[p]){
            cout << "SCC:";
            dfs(p,sv,tv);
            nl();
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    while(t--)
        solve();
    return 0;
}

