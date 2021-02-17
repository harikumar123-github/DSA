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
    ll n;
    cin >> n;
    vll dp(n);
    dp[0]=1;
    ll a=0,b=0,c=0;
    ll m2=dp[a]*2,m3=dp[b]*3,m5=dp[c]*5;
    FOR(i,1,n){
		ll un=min(m2,min(m3,m5));
		dp[i]=un;
		if(un==m2){
			a++;
			m2=dp[a]*2;
		}
		if(un==m3){
			b++;
			m3=dp[b]*3;
		}
		if(un==m5){
			c++;
			m5=dp[c]*5;
		}
	}
	cout << dp[n-1] << endl;
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


