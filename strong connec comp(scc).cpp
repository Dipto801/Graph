#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
//#define  ordered_set  tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
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

//.....BIT_MASKING...........
int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}

//int dx[]={-1,+1,0,0}; //[Grid move's]
//int dy[]={0,0,-1,+1};
typedef long long ll;
//ll big_mod(ll a,ll b,ll m){if(b==0) return 1;ll x=big_mod(a,b/2,m);x=(x*x)%m;if(b%2)x=(x*a)%m;return x;}
const int N=1e5+12;
const int mod=1e9+7;
vll adj[N],radj[N];
ll vis[N],viss[N];
stack<ll>st;
vll scc;
void dfs1(ll node){
  vis[node]=1;
  for(auto u:adj[node]){
    if(vis[u]==0){
      dfs1(u);
    }
  }
   st.push(node);
}
void dfs2(ll node){
  viss[node]=1; scc.pb(node);
  for(auto u:radj[node]){
    if(viss[u]==0){
      dfs2(u);
    }
  }
}
void solve()
{
   ll n; cin>>n;
   ll m; cin>>m;
   while(m--){
     ll u,v; cin>>u>>v;
     adj[u].pb(v);
     radj[v].pb(u); //  reverse tao lagbe
   }
   for(ll i=1;i<=n;i++){
    if(vis[i]==0){
         dfs1(i);
    }
   }  // ekta stack a rekhe dibo
  
   ll cnt=0;
   while(st.size()>0){
    ll x=st.top(); st.pop();
   // cout<<x<<" ";
     if(viss[x]==0){
      cnt++;
      dfs2(x);
      for(auto u:scc){
        cout<<u<<" ";    // print kore dekhlam scc
      }
      cout<<nl;
     scc.clear();
    }
   } // reverse dfs chaliye dekho kotogula connected
   cout<<cnt<<nl;
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


