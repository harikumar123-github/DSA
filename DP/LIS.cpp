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

//Longest Increasing Subsequence

void solve();

void solve(){
    ll n;
    cin >> n;
    ll a[n];
    FOR(i,0,n)
		cin >> a[i];
	vll dp(n,1);
	//O(N^2) approach
	FOR(i,0,n){
		ll p=dp[i];
		FOR(j,0,i)
			if(a[i]>a[j]){
				dp[i]=max(dp[i],p+dp[j]);
			}
	}
	cout << dp[n-1] << endl;
	//O(NlogN) approach
	vll v;
	v.pb(a[0]);
	FOR(i,1,n){
		if(a[i]>v.back())
			v.pb(a[i]);
		else{
			ll j=lower_bound(all(v),a[i])-v.begin();
			v[j]=a[i];
		}
	}
	cout << v.sz() << endl;
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


