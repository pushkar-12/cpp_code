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
#define sz(x) (ll)(x).size()
#define ff first
#define ss second

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

string s1,s2;
stack<char>lcs;
int LCS[1001][1001];
void get(int i,int j)
{
	if(i==0 or j==0)return;
	if(s1[i-1]==s2[j-1]){
		lcs.push(s1[i-1]);get(i-1,j-1);}

	else if(LCS[i-1][j]>LCS[i][j-1])
		get(i-1,j);
	else get(i,j-1);

	if(i==s1.length() and j==s2.length())
	{
		while(!lcs.empty()){cout<<lcs.top();lcs.pop();}
	}
} 

int main()
{
	#if !ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>s1>>s2;
	int n=s1.length(),m=s2.length();

	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			
			if(s1[i-1]==s2[j-1])LCS[i][j]=LCS[i-1][j-1]+1;
			else LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
		}


	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++)
		{cout<<LCS[i][j]<<" ";}cout<<"\n";}	
	cout<<LCS[n][m]<<"\n";get(n,m);
}