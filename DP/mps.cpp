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

void solve();

void solve(){
    ll n,m;
    cin >> n >> m;
    ll a[n][m];
    FOR(i,0,n)
		FOR(j,0,m)
			cin >> a[i][j];
    vec<vll> dp(n+1,vll(m+1,INT_MAX));
    dp[0][1]=0;//Initialising sum as 0
    FOR(i,0,n){
		FOR(j,0,m){
		//Taking min. of top or left sum from wch we reach to the current cell
		//and adding the current value to the sum
			dp[i+1][j+1]= min(dp[i][j+1],dp[i+1][j]) + a[i][j];
		}
	}
	cout << dp[n][m] << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
  //  cin >> t;
    while(t--)
		solve();
    return 0;
}


