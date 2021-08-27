#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iomanip>

using namespace std;
 
#define ff first
#define ss second
#define pi pair<int, int>

const int maxN=1e5+5;
 
vector<int> arr[maxN];
vector<int> t_arr[maxN];
bool vis[maxN];

vector<pi> out;
int timer=1;

vector<int> cc;

void dfs1(int v){
	vis[v]=1;
	timer++;
	
	for(int child: arr[v]){
		if(vis[child]==0) dfs1(child);
	}
	
	out.push_back({v, timer++});
}

void dfs2(int v){
	vis[v]=1;
	
	for(int child: t_arr[v]){
		if(vis[child]==0) dfs2(child);
	}
	
	cc.push_back(v);
}

void solve(){
	int n, m;
	cin>>n>>m;
	
	cout<<n<<" "<<m<<" ";
	
	for(int i=1; i<=m; i++){
		int a, b;
		cin>>a>>b;
		arr[a].push_back(b);
		t_arr[b].push_back(a);
	}
	
	// Kosaraju's Algorithm
	
	for(int i=1; i<=n; i++){
		if(vis[i]==0) dfs1(i);
	}
	
	for(int i=1; i<=n; i++) vis[i]=0;
	
	sort(out.begin(), out.end(), [&](pi a, pi b){
		return a.ss>b.ss;
	});
	
	//cout<<"List of different connected components:-"<<endl;
	int cnt=0;
	
	for(int i=0; i<(int)out.size(); i++){
		int v=out[i].ff;
		
		if(vis[v]==0){
			cc.clear();
			dfs2(v);
			cnt++;
			for(int x: cc){
				//cout<<x<<" ";
			}
			//cout<<endl;
		}
	}
	//cout<<endl;
	//cout<<"Total no. of connected components are "<<cnt<<endl;
	
	cout<<cnt<<" ";
}
 
 
int main(){
	auto start=chrono::high_resolution_clock::now();
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	solve();

	auto end=chrono::high_resolution_clock::now();
	
	int time_taken=
		chrono::duration_cast<chrono::microseconds>(end-start).count();
		
	//cout<<fixed<<time_taken<<setprecision(9)<<endl;
	cout<<time_taken<<" "<<endl;
}
