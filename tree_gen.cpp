// A C++ Program to generate test cases for
// an unweighted undirected graph

#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b){
	return a+rand()%(b-a+1);
}

void stupid_generator(){
	int n=rand(2, 20);
	cout<<n<<endl;
	
	for(int i=2; i<=n; i++){
		cout<<rand(1,i-1)<<" "<<i<<endl;
	}
}

void smart_generator(){
	int n=rand(2,20);
	cout<<n<<endl;
	
	vector<pair<int, int>> edges;
	for(int i=2; i<=n; i++){
		edges.emplace_back(rand(1,i-1), i);
	}
	random_shuffle(edges.begin(),edges.end()); // random order of edges
	
	vector<int> perm(n+1); // renaming vertices
	for(int i=1; i<=n; i++){
		perm[i]=i;
	}
	random_shuffle(perm.begin()+1, perm.end());
	
	for(auto edge: edges){
		int a=edge.first, b=edge.second;
		if(rand()%2) swap(a, b); // random order of two vertices in output representing an edge
		cout<<perm[a]<<" "<<perm[b]<<endl;
	}
}

void advanced_generator(){
	// Prufer Sequences
}

int main(int argc, char* argv[]){
	srand(stoi(argv[1]));
	
	//stupid_generator();
	
	smart_generator();
		
}
