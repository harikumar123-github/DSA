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
    ll n,f;
    cin >> n >> f;
    vec<vll> dp(n+1,vll(f+1,0));
	FOR(i,1,n+1){
		FOR(j,1,f+1){
			FOR(k,1,j+1){
				if(i==1)
					dp[i][j]=j;
				else if(j==1){
					dp[i][j]=1;
				}
				else{
					dp[i][j]=1+max(dp[i-1][k-1],dp[i][j-k]);
				}
			}
		}
	}
	cout << dp[n][f] << endl;
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


