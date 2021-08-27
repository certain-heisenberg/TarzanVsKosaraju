#include <iostream>
#include <vector>
#include <stack>
#include <chrono>
#include <iomanip>

using namespace std;

const int maxN=1e5+5;

vector<int> arr[maxN];
bool vis[maxN];

int in[maxN], low[maxN];

bool onStack[maxN];
stack<int> st;
int timer=1;

int cnt;
vector<vector<int>> scc;

void dfs(int v){
	vis[v]=1;
	
	in[v]=low[v]=timer++;
	onStack[v]=1;
	st.push(v);
	
	for(int child: arr[v]){
		if(vis[child]==1 && onStack[child]){
			low[v]=min(low[v], in[child]);
		}
		else if(vis[child]==0){
			dfs(child);
			if(onStack[child]) low[v]=min(low[v], low[child]);
		}
	}
	
	if(in[v]==low[v]){
		vector<int> temp;
		cnt++;
		while(1){
			int u=st.top();
			st.pop();
			onStack[u]=0;
			temp.push_back(u);
			
			if(u==v) break;
		}
	
		scc.push_back(temp);
	}
}

void solve(){
	int n, m;
	cin>>n>>m;
	
	cout<<n<<" "<<m<<" ";
	
	for(int i=1; i<=m; i++){
		int a, b;
		cin>>a>>b;
		arr[a].push_back(b);
	}
	
	// Tarzan's Algorithm
	
	for(int i=1; i<=n; i++){
		if(vis[i]==0) dfs(i);
	}
	
	//cout<<"Total # of SCC in the given graph is "<<cnt<<endl<<endl;
	
	//cout<<"Different SCC are:"<<endl;
	
	for(auto c: scc){
		for(auto d: c){
			//cout<<d<<" ";
		}
		//cout<<endl;
	}
	
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
