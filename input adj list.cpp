#include<bits/stdc++.h>
#define dipto ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define nl '\n'
#define yes             cout<<"YES"<<'\n';
#define no              cout<<"NO"<<'\n';
#define gcd(x,y)        __gcd(x,y)
#define lcm(x,y)        y*x/__gcd(x,y)
#define pb              push_back
#define nextp(x)        next_permutation(x.begin(),x.end())
#define all(ar)         ar.begin(), ar.end()
#define rall(ar)        ar.rbegin(), ar.rend()
#define Unique(x)       x.erase(unique(all(x)), x.end());
#define MAX(x)          *max_element(all(x));
#define MIN(x)          *min_element(all(x));
#define SUM(a)          accumulate(all(a),0LL);
#define fixpoint(x)     cout<<fixed<<setprecision(x)
#define clz(x)          __builtin_clz(x) // count leading zeros of 32 bits.
                                         //like 4=00000000....100(leading 29 ta)
#define ctz(x)          __builtin_ctz(x) //count trailing zeros                                         
#define popcount(x)     __builtin_popcount(x)    //count number of ones's(bits)

#define vll             vector<ll>
#define F               first
#define S               second
#define cinv(v)         for(auto& i:v)cin>>i;
#define coutv(v)        for(auto& i:v)cout<<i<<' ';
using namespace std;
typedef long long ll;
/*
bool cmp(const pair<ll,ll>&p1,const pair<ll,ll>&p2)
{
  if(p1.first>p2.first) return 1;
  else if(p1.first==p2.first) return(p1.second<p2.second);
  return 0;
} */
const int N=1e5+123;
vll adj[N];
void solve()
{
  ll n,m; cin>>n>>m;
  for(ll i=0;i<m;i++){
    ll u,v; cin>>u>>v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  for(ll i=1;i<=n;i++){
    cout<<"adj list of node "<<i<<": ";
    for(auto u:adj[i]){
        cout<<u<<" ";
    }
    cout<<nl;
  }

}
int main()
{
    dipto
    ll test=1;//cin>>test;
    while(test--)
    {
      solve();
    }
}


