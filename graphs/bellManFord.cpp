#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef stack<ll> stll;
typedef pair<ll,ll> pll;
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

void solve(){
    ll n,e,s;
    cin >> n >> e >> s;
    vec<vec<pll>> v(n+1);
    FOR(i,0,e){
        ll a,b,w;
        cin >> a >> b >> w;
        v[a].pb(mp(b,w));
    }
    vll dist(n+1,INT_MAX);
    dist[0]=dist[s]=0;
    FOR(i,1,n){
        FOR(a,1,n+1){
            for(auto b:v[a]){
                if(dist[a]!=INT_MAX && dist[b.fi] > dist[a]+b.sec ){
                    dist[b.fi]=dist[a]+b.sec;
                }
            }
        }
    }
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

