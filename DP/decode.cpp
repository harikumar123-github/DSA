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

ll calcu(string s,ll i,vll &dp){
	if(i>=ll(s.ln())) return 1;
	if(dp[i]!=-1)
		return dp[i];
	ll ct=0,co=0;
	//debug(i);
	if(s[i+1]=='0')
		return calcu(s,i+2,dp);
	if(s[i]!='0')
		co=calcu(s,i+1,dp);
	ll dig=(s[i]-'0')*10+(s[i+1]-'0');
	if(s[i]!='0' && s[i+2]!='0' && (dig <=26 && dig >=10) )
		ct=calcu(s,i+2,dp);
	return dp[i]=(ct+co);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	string s;
	while(cin >> s){
		if(s[0]=='0')
			break;
		vll dp(s.ln(),-1);
		dp[s.ln()-1]=1;
		cout << calcu(s,0,dp) << endl;
	}
    return 0;
}


