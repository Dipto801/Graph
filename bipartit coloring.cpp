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
ll p=1;
const int mx=2e4+123;
vll adj[mx];
bool vis[mx];
bool isnodeace[mx];
ll col1;
ll ans;
//bipartit graph always 2 ta color korbo;
//ei math a maximum color size ta nicchi;
void dfs(ll node, int col){
  vis[node]=1;
  ans++;   //component size count kori;
  ll temp;
  if(col==1){
     temp=2;
     col1++;
  } 
  else temp=1;
  for(auto u:adj[node]){
    if(vis[u]==0) {
      dfs(u,temp);
    }
  }
    
}
void solve()
{
  
  ll n; cin>>n;
  for(ll i=0;i<n;i++){
    ll u,v; cin>>u>>v;
    adj[u].pb(v);
    adj[v].pb(u);
    isnodeace[u]=1;
    isnodeace[v]=1;
  }
  ll cnt=0;
  for(ll i=1;i<=mx;i++){
     if(vis[i]==0 and isnodeace[i]==1){
      ans=0;col1=0;
      dfs(i,1);
      cnt+=max(col1,ans-col1);
     }
    
  }
  memset(vis,0,sizeof(vis));
  memset(adj,0,sizeof(adj));
  memset(isnodeace,0,sizeof(isnodeace));
  cout<<"Case "<<p<<": "<<cnt<<nl;
  p++;

}
int main()
{
    dipto
    ll test=1; cin>>test;
    while(test--)
    {
      solve();
    }
}


