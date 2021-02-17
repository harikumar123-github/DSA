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
#define debug1(a,n) FOR(i,0,n) cout << a[i] << " ";
#define debug2(a,n,m) FOR(i,0,n){\
						FOR(j,0,m)\
							cout << a[i][j] << " "; nl(); }
#define MAX ll(1e9+7)

void solve();

void solve(){
    ll n;
    cin >> n;
    vec<pll> a(n);
    FOR(i,0,n)
		cin >>  a[i].fi >> a[i].sec;
	vll dp(n,1);
	sort(all(a));
	FOR(i,1,n){
		FOR(j,0,i){
			if(a[j].sec<a[i].fi)
				dp[i]=max(dp[i],dp[j]+1);
		}
	}
	//debug1(dp,n);
	//nl();
	cout << *max_element(all(dp)) << endl;
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


