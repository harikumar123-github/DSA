#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
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

vll ve;

bool dfs(ll r,vb &vis,vvll &v,vb clr,ll par){
	vis[r]=true;
	clr[r]= !clr[par];
	for(auto i:v[r]){
		if(!vis[i])
			return dfs(i,vis,v,clr,r);
		else if(clr[i]==clr[par])
			return false;
	}
	return true;
}

void solve(){
    int n,e;
    cin >> n >> e;
    vvll v(n+1);
    FOR(i,0,e){
		ll a,b;
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	vb vis(n+1,false);
	vb clr(n+1);
	clr[0]=1;
	cout << (dfs(1,vis,v,clr,0)?"Biparite":"Not Biparite") 
													<< endl;
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


