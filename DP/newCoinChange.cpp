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
#define endl "\n"
#define debug(z) cout << #z << "=" << z << endl
#define MAX ll(1e9+7)

//No.of ways to get the change for k cents from given n coins[Supply of each
																//coin is infinity]

void solve();

void solve(){
	ll n;
	cin >> n;
	vll a(n);
	FOR(i,0,n)
		cin >> a[i];
	ll k;  cin >> k;
	vec<vll> dp(n+1,vll(k+1,0));
	FOR(i,0,n+1)
		dp[i][0]=1;
	FOR(i,1,n+1){
		FOR(j,1,k+1){
			if(j>=a[i-1])
				dp[i][j] += (dp[i-1][j]+dp[i][j-a[i-1]]);
			else
				dp[i][j] += dp[i-1][j];
		}
	}
	cout << dp[n][k] << endl;
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


