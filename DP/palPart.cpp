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
#define debug2(a,n,m) FOR(i,0,n){\
						FOR(j,0,m)\
							cout << a[i][j] << " "; nl(); }
#define MAX ll(1e9+7)

void solve();

bool pal(string s,ll i,ll j){
	if(i-j==0)
		return true;
	while(i<j){
		if(s[i]!=s[j])
			return false;
		i++; j--;
	}
	return true;
}

void solve(){
    string s;
    cin >> s;
    ll n=s.ln();
    vec<vll> dp(n,vll(n,0));;
    FOR(j,1,n){
		ll tj=j;
		FOR(i,0,n-j){
			if(i==tj || pal(s,i,tj))
				dp[i][tj]=0;
			else{
				ll m=INT_MAX;
				FOR(k,i,tj){
					m=min(m,1+dp[i][k]+dp[k+1][tj]);
				}
				dp[i][tj]=m;
			}
			++tj;
		}
	}
	//debug2(dp,n,n);
	cout << dp[0][n-1] << endl;
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


