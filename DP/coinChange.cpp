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


//Min. possible coins from the given n coins to get the denominations for k
//												[Supply of each coin is infinity]

void solve();

void solve(){
    ll n;
    cin >> n;
    vll a(n);
    FOR(i,0,n)
		cin >> a[i];
	ll k; cin >> k;
	//dp[i] ==> Min. no.of coins for sum i
	vll dp(k+1,INT_MAX);
	dp[0]=0;
	FOR(i,0,k+1){
		for(auto j:a)
			if(i-j>=0)
		//Decide to take or not the coin and if taken add 1
				dp[i]=min(dp[i-j]+1,dp[i]);
	}
	cout << dp[k] << endl;
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


