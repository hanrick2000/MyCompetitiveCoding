#include<bits/stdc++.h>

using namespace std;

#define nl endl
#define lli long long int
#define ld long double
#define vb vector<bool>
typedef vector<int> vi;
typedef vector<lli> vlli;
typedef vector<double> vd;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<vector<int> > vvi;
typedef vector<vector<char> > vvc;
typedef priority_queue<int> pq; //maxHeap
typedef priority_queue <int, vector<int>, greater<int> > pqn; //minHEAP
typedef map<int, int> mii;
typedef map<string, int> msi;
typedef map<int, string> mis;
typedef map<string, bool> msb;
typedef map<string, string> mss;
typedef map<string, char> msc;
typedef pair<int, int> pii;
typedef pair<lli, lli> pllilli;
typedef vector<pii> vii;
typedef vector<pllilli> vllilli;
//vector<int>::iterator j;
#define REPV (j, v) for(vector<int>::iterator j = v.begin(); j!=v.end();j++)
#define pb push_back
//#define pf push_front
#define mp make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, A, B) for (int I = (A); I < (B); ++I)
#define REPR(I, A, B) for (int I = (B); I > (A); I--)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRLLI(X) lli (X); scanf("%lld", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRLLILLI(X, Y) lli X, Y; scanf("%lld%lld", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define DRLLILLILLI(X, Y, Z) lli X, Y, Z; scanf("%lld%lld%lld", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define DRA(a,n) int a[n]; REP(i,n)cin>>a[i]
#define l_b lower_bound
#define u_b upper_bound
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define NL cout<<endl
#define isOdd(i) (i&1)
#define isEven(i) (!(i&1))
#define all(ar) ar.begin(), ar.end()
#define zzz return 0
inline lli Power(int b, int p) { lli ret = 1; for ( int i = 1; i <= p; i++ ) ret *= b; return ret; }
const int MOD = 1e9+7;
const int SIZE = 4e6+10;
const int MAX = 1e9+1;

#define N 10000000

string s;
vi ans(4*N,0),L(4*N,0),R(4*N,0);
struct node{
  int c;int x;int y;
  node(){};
  node (int _x, int _y, int _c) : x(_x), y(_y), c(_c) {};
};
node segTree(int x, int y, int id, int l, int r){
  if(l>=y || x >= r)return node(0,0,0);
  if(x<=l && y>=r)return node(L[id],R[id],ans[id]);
  int mid = l + (r-l)/2;
  node a = segTree(x,y,id*2,l,mid);
  node b = segTree(x,y,id*2,mid+1,r);

  int tmp = min(a.x,b.y);
  int ans = a.c + b.c + tmp;
  int left = a.x +b.x-tmp;
  int right = a.y +b.y -tmp;
  return node(left, right, ans);
}


void init(int id,int l, int r){
  if(r-l<2){
    if(s[l]=='('){
      L[id]=1;
    }else{
      R[id]=1;
    }
    return;
  }
  int mid = l +(r-l)/2;
  init(id*2,l,mid);
  init(id*2 +1,mid+1,r);

  int tmp = min(L[2*id],R[2*id +1]);
  ans[id]=ans[2*id]+ans[2*id +1]+tmp;
  L[id]=L[2*id]+L[2*id +1]-tmp;
  R[id]=R[2*id]+R[2*id +1]-tmp;
}

int main(){
  cin>>s;
  int n=s.length();
  init(1,0,n-1);
  DRI(q);
  while(q--){
    DRII(l,r);
    //TODO:
    node res = segTree(l-1,r,1,0,n);
    cout<<res.c;NL;
  }

  zzz;
}
