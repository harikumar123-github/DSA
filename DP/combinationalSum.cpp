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

//No.of ways to express sum k using the given n elements[Repetition is allowed
//																and order matters] 

void solve();

void solve(){
    ll n;
    cin >> n;
    vll a(n);
    FOR(i,0,n)
		cin >> a[i];
	ll k;
	cin >> k;
	//dp[i] ==> the no.of ways sum i can be obtained with given digits
	//                (Order matters i.e., 1+2+1 != 2+1+1)
	vll dp(k+1,0);
	dp[0]++;//Initialising the ways to get sum 0 is 1(Not taking any digits)
	FOR(i,0,k+1){
		//Adding no.of ways to obtain remaining sum by taking one of the digit
		for(auto j:a){
			if(i-j>=0)
				dp[i]+=dp[i-j];
		}
	}
	cout << dp[k] << endl;
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


