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

void solve(){
    ll n,lim;  cin >> n;
    vec<pll> v(n);
    FOR(i,0,n){
		cin >> v[i].fi >> v[i].sec;
	}
	cin >> lim;
	vec<vll> dp(n+1,vll(lim+1,0));
	FOR(i,1,n+1){
		FOR(j,1,lim+1){
			if(v[i-1].fi<=j){
				dp[i][j]=max(dp[i-1][j], (v[i-1].sec+dp[i-1][j-v[i-1].fi]) );
			}
			else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	//FOR(i,0,n){
		//FOR(j,0,lim)
			//cout << dp[i+1][j+1] << " ";
		//nl();
	//}
	cout << dp[n][lim] << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    cin >> t;
    while(t--)
		solve();
    return 0;
}


