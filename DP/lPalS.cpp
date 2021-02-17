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

//Longest Palindromic Substring...

void solve();

void solve(){
    string s;
    cin >> s;
    ll n=s.ln();
    vec<vll> dp(n,vll(n,0));
    FOR(i,0,n)
		dp[i][i]=1;
	FOR(i,0,n-1){
		if(s[i]==s[i+1])
			dp[i][i+1]=1;
	}
	ll st=0,en=0;
	ll len=st-en+1;
	FOR(j,2,n){
		ll tj=j;
		FOR(i,0,n-j){
			dp[i][tj]=(s[i]==s[tj] && dp[i+1][tj-1]);
			if(dp[i][tj] && i-tj+1<len){//d
				len=i-tj+1;
				st=i;
				en=tj;
			}
			++tj;
		}
	}
	debug(st); debug(en);
	debug2(dp,n,n);
	FOR(i,st,en+1){
		cout << s[i];
	}
	nl();
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


