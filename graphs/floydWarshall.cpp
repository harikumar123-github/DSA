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

void solve(){
    ll n,e;
    read(n,e);
    vvll v(n+1,vll(n+1,INT_MAX));
    FOR(i,0,n+1){
        v[i][0]=v[i][i]=0;
        v[0][i]=0;
    }
    FOR(i,0,e){
        ll a,b,w;
        read(a,b,w);
        v[a][b]=w;
    }
    vvll dp(v.begin(),v.end());
    FOR(i,1,n+1){
        FOR(j,1,n+1){
            FOR(k,1,n+1){
                dp[j][k]=min(dp[j][k],dp[j][i]+dp[i][k]);
            }
        }
    }
    FOR(i,1,n+1){
        FOR(j,1,n+1){
            cout << dp[i][j] << " ";
        }
        nl();
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

