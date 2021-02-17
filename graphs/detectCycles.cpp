#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef stack<ll> stll;
typedef pair<ll,ll> pll;

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

bool bfs(ll r,vec<bool> &vis,vec<vll> &v,ll par){
	vis[r]=true;
	for(auto i:v[r]){
		if(!vis[i]){
			return bfs(i,vis,v,r);
		}
		else if(i!=par)
			return true;
	} 
	return false;
}

void solve(){
    ll n,e;
    cin >> n >> e;
    vec<vll> v(n+1);
    FOR(i,0,e){
		ll a,b;
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	vec<bool> vis(n+1,false);
	cout << (bfs(1,vis,v,-1)?"Cycl":"No Cycl") << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    //cin >> t;
    while(t--)
		solve();
    return 0;
}


