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
#define repn(i,k1,k2) for(ll i=k1;i<=k2;i++)
 
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
 
struct Line {
    ll a, b, get(ll x) { return a * x + b; }
};

struct ConvexHull {
    int size;
    Line *hull;

    ConvexHull(int maxSize) {
        hull = new Line[++maxSize], size = 0;
    }

    bool is_bad(ll curr, ll prev, ll next) {
        Line c = hull[curr], p = hull[prev], n = hull[next];
        return (1.0*c.b - n.b)/(1.0*n.a - c.a)  <= (1.0*p.b - c.b)/(1.0*c.a - p.a);   }

    void add_line(ll a, ll b) {
        hull[size++] = (Line){a, b};
        while (size > 2 && is_bad(size - 2, size - 3, size - 1))
            hull[size - 2] = hull[size - 1], size--;
    }

    ll query(ll x) {
        int l = -1, r = size - 1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (hull[m].get(x) <= hull[m + 1].get(x))
                l = m;
            else
                r = m;
        }
        return hull[r].get(x);
    }
};


const ll N = (ll)2e5 + 1;
ll n, a[N],b[N],dp[N];

ConvexHull *hull;

int main() {

	#if !ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin>>n;

    hull = new ConvexHull(n);
    repn(i,1,n)cin>>a[i];repn(i,1,n)cin>>b[i];
    
    for (ll r = 2; r <= n; r++) {
        hull->add_line(-b[r-1], -dp[r-1]);
        dp[r] = -hull->query(a[r]);
    }

    cout<<dp[n];
} 
