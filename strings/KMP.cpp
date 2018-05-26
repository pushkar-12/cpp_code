#include <bits/stdc++.h>
 
#if DEBUG && !ONLINE_JUDGE
    #include "debug.h"
#else
    #define debug(...)
#endif
 
using namespace std;
 
/*******  All Required define Pre-Processors and typedef Constants *******/
#define scd(t) scanf("%d",&t)
#define scld(t) scanf("%ld",&t)
#define sclld(t) scanf("%lld",&t)
#define scc(t) scanf("%c",&t)
#define scs(t) scanf("%s",t)
#define scf(t) scanf("%f",&t)
#define sclf(t) scanf("%lf",&t)
#define mem(a, b) memset(a, (b), sizeof(a))
#define repd(i,k) for(ll i=k;i>=0;i--)
#define rep(i,k) for(ll i=0;i<k;i++)
#define repn(i,k1,k2) for(ll i=k1;i<k2;i++)
 
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define in(A, B, C) assert( B <= A && A <= C)
#define mp make_pair
#define pb push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define ee6 (ll)1000001
#define ee5 (ll)100001
#define read(type) readInt<type>()
#define tt ll t;cin>>t; while(t--)
typedef long long int ll;
 
typedef pair<ll, ll> pr;
typedef vector<ll> vi;
typedef vector<string> vs;
typedef vector<pr> vpr;
typedef vector<vpr>vvpr;
typedef vector<vi> vvi;
typedef map<ll,ll> MPII;
typedef set<ll> SETI;
typedef multiset<ll> MSETI;
 
//need to preprocess to create the lps array for the pattern string
//means lps[i] means length of longest string that is both a prefix and suffix of pattern[0..i] except
//suffix length can't be equal to the length of whole string i.e. i+1
//linear in the length of the text
/* suppose we are matching text with pattern to be searched... characters from 0 to j in the PATTERN
match with characters from x to x+j in text then there is a mismatch in the (j+1)th char in PAT and 
(x+j+1)th character in text now we don't need to go back in text as lps array tells at max how many 
characters from beginning in the pattern match with how many in the end of the pattern that helps
in determining the new pos in pattern from where to start our search
*/

vi formlps(const string& s) {
	vi lps(s.length());
	rep(i,s.length()) {
		if(!i)continue;
		int g = lps[i-1];
		while (g && s[i] != s[g]) g = lps[g-1];
		lps[i] = g + (s[i] == s[g]);
	}
	return lps;
}

void search(string &text, string &pat)
{
	string qs=pat+'/'+text;
	vi g=formlps(qs);

	for(auto i:g)cout<<i<<" ";
	for(int i=pat.length()+1;i<qs.length();i++)
	{
		if(g[i]==pat.length())
			cout<<"pattern found at :"<<i-g[i]-pat.length()<<"\n";
	}

}

int main()
{
	#if !ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string text="abbaaabababbaaa";
	string pat="abb";
	
	search(text,pat);

}