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

//Longest Bitonic seq.(first Increasing and then decreasing ) 

void solve();

void solve(){
    ll n;
    cin >> n;
    ll a[n];
    FOR(i,0,n)
		cin >> a[i];
	//Considering longest increasing and longest decreasing sub seq..
	vll dp1(n),dp2(n);
	FOR(i,0,n){
		dp1[i]=1;
		FOR(j,0,i){
			if(a[j]<a[i]){
				dp1[i]=max(dp1[i],dp1[j]+1);
			}
		}
	}
	FOR(i,0,n){
		dp2[i]=1;
		FOR(j,0,i){
			if(a[j]>a[i]){
				dp2[i]=max(dp2[i],dp2[j]+1);
			}
		}
	}
	ll ans=0;
	FOR(i,0,n)
		ans=max(ans,dp1[i]+dp2[i]-1);
	cout << ans << endl;
	
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


