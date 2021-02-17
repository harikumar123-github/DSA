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


//Longest palindromic subseq..
void solve();

void solve(){
    string s;
    cin >> s;
    ll n=s.ln();
    vec<vll> dp(n,vll(n,0));
    FOR(i,0,n){
		dp[i][i]=1;
	}
	FOR(j,1,n){
		ll tj=j;
		FOR(i,0,n-j){
			if(s[i]==s[tj])
				dp[i][tj]=2+dp[i+1][tj-1];
			else
				dp[i][tj]=max(dp[i+1][tj],dp[i][tj-1]);
			tj++;
		}
	}
	//FOR(i,0,n){
	//FOR(j,0,n)
		//cout  << dp[i][j] << " ";
	//nl();
	//}
	cout << dp[0][n-1] << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--)
		solve();
    return 0;
}


