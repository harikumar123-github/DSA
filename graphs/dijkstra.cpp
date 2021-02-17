#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef stack<ll> stll;
typedef pair<ll,ll> pll;
typedef vector<vll> vvll;
typedef vector<bool> vb;

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

template<typename... T>
void read(T&... args){
    ((cin >> args), ...);
}

template<typename... T>
void wrt(T... args){
    ((cout << args << " "), ...);
}

void bfs(ll r,vb &vis,vec<vec<pll>> v,vll &dist){
    priority_queue<pair<ll,ll>> q;
    q.push(mp(0,r));
    while(!q.empty()){
        ll k=q.top().sec;
        q.pop();
        if(vis[k])  continue;
        vis[k]=true;
        for(auto i:v[k]){
            if(dist[k]+i.sec<dist[i.fi]){
                dist[i.fi]=dist[k]+i.sec;
                q.push(mp(-dist[i.fi],i.fi));
            }
        }
    }
}

void solve(){
    ll n,e;
    read(n,e);
    vec<vec<pll>> v(n+1);
    FOR(i,0,e){
        ll a,b,w;
        read(a,b,w);
        v[a].pb(mp(b,w));
        v[b].pb(mp(a,w));
    }
    vll dist(n+1,INT_MAX);
    vb vis(n+1,false);
    dist[0]=dist[1]=0;
    bfs(1,vis,v,dist);
    for(auto i:dist)
        cout << i << " ";
    nl();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    while(t--)
        solve();
    return 0;
}

