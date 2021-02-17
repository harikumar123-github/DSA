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
	ll n,k;
	cin >> n;
	ll a[n];
	FOR(i,0,n)
		cin >> a[i];
	cin >> k;
	bool dp[n+1][k+1];
	FOR(i,0,n+1)  dp[i][0]=true;
	FOR(i,1,k+1) dp[0][i]=false;
	FOR(i,1,n+1){
		FOR(j,1,k+1)
			if(a[i-1]>j)
				dp[i][j]=dp[i-1][j];
			else
				dp[i][j]= (dp[i-1][j-a[i-1]] || dp[i-1][j]);
	}
	cout << dp[n][k] << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	int t=1;
	while(t--)
		solve();
    return 0;
}


