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


//Topological sort in DAC(Directed Acyclic graph)

//Time comp. : O(N)

void solve();

stack<ll> st;

void dfs(ll r,vb &vis,vvll &v){
	vis[r]=true;
	for(auto i:v[r]){
		if(!vis[i])
			dfs(i,vis,v);
	}
	st.push(r);
}
 
void solve(){
    ll n,e;
    cin >> n >> e;
    vvll v(n+1);
    FOR(i,0,n){
		ll a,b;
		cin >> a >> b;
		v[a].pb(b);
	}
	vb vis(n+1,false);
	FOR(i,1,n+1){
		cout << i << " :";
		for(auto j:v[i]){
			cout << j << " ";
		}
		nl();
	}
	for(ll i=1;i<=n;i++)
		if(!vis[i])
			dfs(i,vis,v);
	while(!st.empty()){
		cout << st.top() << " ";
		st.pop();
	}
	nl();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
   // cin >> t;
    while(t--)
		solve();
    return 0;
}


