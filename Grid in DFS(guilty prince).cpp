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
//int dx[]={-1,+1,0,0}; //[Grid move"s]
//int dy[]={0,0,-1,+1};


ll p=1;
ll x,y,cnt,m,n;
const int mx=21;
char adj[mx][mx];
bool vis[mx][mx];
int dx[]={-1,+1,0,0};
int dy[]={0,0,-1,+1};
void dfs(ll x,ll y){
  vis[x][y]=1;
  cnt++;
   for(ll i=0;i<4;i++){
    ll x1=x+dx[i];
    ll y1=y+dy[i];
    if(x1>=0 and x1<n and y1>=0 and y1<m and vis[x1][y1]==0 and adj[x1][y1]=='.'){
      dfs(x1,y1);
    }
   }
    
}
void solve()
{
  
   cin>>m>>n;
  for(ll i=0;i<n;i++){
    for(ll j=0;j<m;j++){
      cin>>adj[i][j];
      if(adj[i][j]=='@'){
        x=i; y=j;
      }
    }
  }
   cnt=0;
  dfs(x,y);
  memset(vis,0,sizeof(vis));
  memset(adj,0,sizeof(adj));
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


