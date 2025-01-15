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

int dx[]={-1,+1,0,0}; //[Grid move's]
int dy[]={0,0,-1,+1};

using namespace std;
typedef long long ll;
ll m,n;
const int mx=213;
char adj[mx][mx];
ll levfire[mx][mx];
ll levjan[mx][mx];
ll p=1;
vector<pair<ll,ll>>vp;

void bfsfire(){
  memset(levfire,-1,sizeof(levfire));
  queue<pair<ll,ll>>q;
  for(auto u:vp){    //multiple sources thakle amra oita k zero kore nibo.
    q.push(u);
    levfire[u.F][u.S]=0;
  }
    while(!q.empty()){
      ll x=q.front().F;
      ll y=q.front().S;
      q.pop();
      for(ll i=0;i<4;i++){
        ll x1=x+dx[i];
        ll y1=y+dy[i];
        if(x1>=1 and x1<=n and y1>=1 and y1<=m and adj[x1][y1]!='#' and  levfire[x1][y1]==-1){
          levfire[x1][y1]=levfire[x][y]+1;
          q.push({x1,y1});
        }
      }
    }
}
void bfsjan(ll xx,ll yy){
  memset(levjan,-1,sizeof(levjan));
  queue<pair<ll,ll>>q;
  q.push({xx,yy});
  levjan[xx][yy]=0;
  while(!q.empty()){
    ll x=q.front().F;
    ll y=q.front().S;
    q.pop();
    for(ll i=0;i<4;i++){
      ll x1=x+dx[i];
      ll y1=y+dy[i];
      if(x1>=1 and x1<=n and y1>=1 and y1<=m and adj[x1][y1]!='#' and levjan[x1][y1]==-1 and levjan[x][y]+1<levfire[x1][y1]){
        levjan[x1][y1]=levjan[x][y]+1;
        q.push({x1,y1});
      }
    }
  }
}

void solve()
{
  cin>>n>>m;
  ll x,xx,y,yy;
 // memset(adj,0,sizeof(adj));
 vp.clear();
  for(ll i=1;i<=n;i++){
    for(ll j=1;j<=m;j++){
      cin>>adj[i][j];
      if(adj[i][j]=='J'){
        x=i; y=j;
      }
      if(adj[i][j]=='F'){
        vp.pb({i,j});
      }
    }
  }
  bfsfire();
  bfsjan(x,y);
  ll ans=INT_MAX;
  for(ll i=1;i<=m;i++){
    if(levjan[1][i]!=-1) ans=min(ans,levjan[1][i]);
  }
  for(ll i=1;i<=m;i++){
    if(levjan[n][i]!=-1) ans=min(levjan[n][i],ans);
  }
  for(ll i=1;i<=n;i++){
    if(levjan[i][1]!=-1) ans=min(levjan[i][1],ans);
  }
  for(ll i=1;i<=n;i++){
    if(levjan[i][m]!=-1) ans=min(levjan[i][m],ans);
  }
  cout<<"Case "<<p<<": ";
  if(ans==INT_MAX) cout<<"IMPOSSIBLE"<<nl;
  else cout<<ans+1<<nl;
  p++;
}
int main()
{
    dipto
    ll test=1;cin>>test;
    while(test--)
    {
      solve();
    }
}


