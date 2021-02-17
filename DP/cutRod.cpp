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
#define debug2(a,n,m) FOR(i,0,n+1){\
						FOR(j,0,m+1)\
							cout << a[i][j] << " "; nl(); }
#define MAX ll(1e9+7)


//Cutting rod to get max profit

void solve();

void solve(){
    ll n,len;
    cin >> n;
    vll a(n);
    FOR(i,0,n){
		cin >> a[i];
	}
	cin >> len;
	vec<vll> dp(n+1,vll(len+1,0));
	FOR(i,1,n+1){
		FOR(j,1,len+1){
			if(i<=j)
				dp[i][j]=max(dp[i-1][j],a[i-1]+dp[i][j-i]);
			else
				dp[i][j]=dp[i-1][j];
		}
	}
	debug2(dp,n,len);
	cout << dp[n][len] << endl;
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


