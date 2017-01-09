/*
Author : Aman Singh
Solution for problem code Santa Claus and Tangerines.

==============================================
A programmer started to cuss,
'cause getting to sleep was a fuss.
As he lay there awake in his bed,
Looping around and 'round in his head,
Was: while(!asleep()) sheep++;
==============================================

*/

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define sz(a) int((a).size())
// #define mp make_pair
#define pb push_back
#define fi first
#define se second
#define buli(x) (__builtin_popcountll(x))
#define all(c) (c).begin(),(c).end()
#define foreach(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define input(s, n) for(int i=0;i<n;i++) cin >> s[i];
#define F(i, f, t) for(int i=f;i<t;i++)
#define R(i,n) for(ll i=0;i<n;i++)

#define print(cnt,x) cout<<"Case #"<<cnt<<": "<<x<<"\n";

template <class T>  inline void smax(T &x,T y){ x = max((x), (y));}
template <class T>  inline void smin(T &x,T y){ x = min((x), (y));}

#ifdef LOCAL
#define fr freopen("in.txt","r",stdin)
#define fo freopen("out.txt","w",stdout)

#define error(x) cerr << #x << " = " << (x) <<endl
#define Error(a,b) cerr<<"( "<<#a<<" , "<<#b<<" ) = ( "<<(a)<<" , "<<(b)<<" )\n";
#define errop(a) cerr<<#a<<" = ( "<<((a).x)<<" , "<<((a).y)<<" )\n";
#define dbg(x) F(i,0,sz(x)) cout << x[i] << " ";
#define dbgg(x) F(i,0,sz(x)){F(j,0,sz(x[0])) cout << x[i][j] << " "; cout << endl;}
#else
#define fr 1
#define fo 1
#define error(x)
#define Error(a,b)
#define errop(a)
#define dbg(x)
#define dbgg(x)
#endif

inline void sc(int &x)
{
	bool f=0; x=0; char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') { f=1; c=getchar(); }
	while(c>='0' && c<='9') { x=x*10+c-'0'; c=getchar(); }
	if(f) x=-x; return;
}

void sc(char &x) {scanf("%c", &x); }
void sc(int &x,int &y) { sc(x); return sc(y); }
void sc(int &x,int &y,int &z) { sc(x); sc(y); return sc(z); }

#define inf 2e9
const double eps = 1e-7;

#define N 2000005
int n;
int inp[N];
char str[N];
map<pair<int, ii>, bool> mp;

int x[] = {0, -1, -1, -1, 0, 1, 1, 1};
int y[] = {1, 1, 0, -1, -1, -1, 0, 1};

int rec(int from = 0, int to = 0, int level = 0){
	cout << from << " " << to << " " << level << endl;
	if(level == n) return 0;
	else if(mp.find({inp[level], {from, to}}) != mp.end())return 0;
	else{
		for(int i = 0; i < inp[level]; i++){
			mp[{inp[level] - i, {from + i * x[level % 8], to + i * y[level % 8]}}] = 1;
		}
		int xn = from + (inp[level] - 1) * x[level % 8];
		int yn = to + (inp[level] - 1) * y[level % 8];
		Error(xn, yn);
		rec(xn + x[(level + 1) % 8], yn + y[(level + 1) % 8], level + 1);
		rec(xn + x[(level + 7) % 8], yn + y[(level + 7) % 8], level + 1);
	}
}


int main(){
	std::ios::sync_with_stdio(false);
	// fr;
	sc(n); R(i, n) sc(inp[i]);
	rec();
	int cnt = 0;
	map<ii, bool> mark;
	cout << endl << endl;
	for(auto x : mp){
		cout << x.fi.se.fi << " " << x.fi.se.second << endl;
		if(x.se && !mark[x.fi.se]) {cnt++; mark[x.fi.se] = 1;}
 	}
 	cout << cnt << endl;
	return 0;
}