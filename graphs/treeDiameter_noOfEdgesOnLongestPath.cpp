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

template<typename... T>
void read(T&... args){
    ((cin >> args), ...);
}

template<typename... T>
void wrt(T... args){
    ((cout << args << " "), ...);
}

ll lf;

void calcu(ll r,vvll &v,ll cnt,vb vis,ll &ans){
    vis[r]=true;
    cnt++;
    for(auto i:v[r]){
        if(!vis[i]){
            if(cnt>=ans){
                ans=cnt; lf=i;
            }
            calcu(i,v,cnt,vis,ans);
        }
    }
}

void solve(){
    ll n;
    cin >> n;
    vvll v(n+1);
    FOR(i,1,n){
        ll a,b;
        read(a,b);
        v[a].pb(b);
        v[b].pb(a);
    }
    ll cnt=0,ans=0;
    vb vis(n+1,false);
    calcu(1,v,cnt,vis,ans);
    calcu(lf,v,cnt,vis,ans);
    cout << "Edges=" << ans << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    while(t--)
        solve();
    return 0;
}

