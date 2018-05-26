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


void count_sort(vector<pr> &b, ll bits) { // (optional)
	//this is just 3 times faster than stl sort for N=10^6
	ll mask = (1 << bits) - 1;
	repn(it,0,2) {
		ll move = it * bits;
		vi q(1 << bits), w(sz(q) + 1);
		repn(i,0,sz(b))
			q[(b[i].first >> move) & mask]++;
		partial_sum(q.begin(), q.end(), w.begin() + 1);
		vector<pr> res(b.size());
		repn(i,0,sz(b))
			res[w[(b[i].first >> move) & mask]++] = b[i];
		swap(b, res);
	}
}
struct SuffixArray {
	vi sa;
	string s;
	SuffixArray(const string& _s) : s(_s + '\0') {
		ll N = sz(s);
		vector<pr> b(N);
		sa.resize(N);
		repn(i,0,N) {
			b[i].first = s[i];
			b[i].second = i;
		}

		ll q = 8;
		while ((1 << q) < N) q++;
		for (ll moc = 0;; moc++) {
			count_sort(b, q); // sort(all(b)) can be used as well
			sa[b[0].second] = 0;
			repn(i,1,N)
				sa[b[i].second] = sa[b[i - 1].second] +
					(b[i - 1].first != b[i].first);

			if ((1 << moc) >= N) break;
			repn(i,0,N) {
				b[i].first = (ll)sa[i] << q;
				if (i + (1 << moc) < N)
					b[i].first += sa[i + (1 << moc)];
				b[i].second = i;
			}
		}
		repn(i,0,sz(sa)) sa[i] = b[i].second;
	}
	vi lcp() {
		// longest common prefixes: res[i] = lcp(a[i], a[i+1])
		ll n = sz(sa), h = 0;
		vi inv(n), res(n);
		repn(i,0,n) inv[sa[i]] = i;
		repn(i,0,n) if (inv[i] > 0) {
			ll p0 = sa[inv[i] - 1];
			while (s[i + h] == s[p0 + h]) h++;
			res[inv[i]-1] = h;
			if(h > 0) h--;
		}
		return res;
	}
};
 
//now suffix array consists of suffixes arranged in ascending order
//means Ar[0] gives the starting index of lexicographically smallest string in the original string
// Ar[1] gives starting index of second smallest string
int main()
{
	#if !ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string a,b;cin>>a>>b;
	SuffixArray a1=SuffixArray(a);
	SuffixArray b1=SuffixArray(b);
	string c=a+'}'+b;
	SuffixArray c1=SuffixArray(c);

	vi lcpa=a1.lcp();
	vi lcpb=b1.lcp();
	vi lcpc=c1.lcp();
	//a1.s b1.s c1.s  a1.sa b1.sa  c1.sa 

/*
	for(auto i:a1.sa)
		cout<<i<<" ";

cout<<"\n";

	for(auto i:lcpa)
		cout<<i<<" ";cout<<"\n";
	for(auto i:b1.sa)
		cout<<i<<" ";cout<<"\n";

	for(auto i:c1.sa)
		cout<<i<<" ";cout<<"\n";

	for(auto i:lcpc)
		cout<<i<<" ";cout<<"\n";*/
ll x=0;
	for(ll i=1;i<sz(a1.sa);i++)
	{
		x+=(ll)a.length()-a1.sa[i]-lcpa[i];
	}
ll y=0;
	for(ll i=1;i<sz(b1.sa);i++)
	{
		y+=(ll)b.length()-b1.sa[i]-lcpb[i];
	}
	//cout<<x<<" "<<y<<"\n\n";
	ll ANS=0;ll pointa=1,pointb=1;

	for(ll i=1;i<c1.sa.size()-1;i++)
	{
		ll idx1=c1.sa[i];
		ll idx2=c1.sa[i+1];
		//cout<<idx1<<" "<<idx2<<" ";//<<(idx1-(ll)a.length())*(idx2-(ll)a.length())<<"\n";
		if((idx1-(ll)a.length())*(idx2-(ll)a.length())<0)
		{	//cout<<"sf";
			ANS+=lcpc[i];
			//cout<<"ANS "<<ANS<<"\n";
			if(idx1<a.length())
				{ANS-=lcpa[pointa];pointa++;}
			else
				{ANS-=lcpb[pointb];pointb++;}
		}
		else if(idx1<a.length())pointa++;
		else if(idx1>a.length())pointb++;
	}
	cout<<ANS<<"\n";
	cout<<x+y-2*ANS;
}