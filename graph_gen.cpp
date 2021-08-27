// A C++ Program to generate test cases for
// an unweighted directed graph

#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b){
	return a+rand()%(b-a+1);
}

int main(int argc, char* argv[]){
	int seed = stoi(argv[1]);
    srand(seed);
	
	set<pair<int, int>> container;
	
	int n=rand(2, 20), MAX_EDGE=n*(n-1)/2;
	
	int m=rand(1,MAX_EDGE);
	
	cout<<n<<" "<<m<<endl;
		
	for(int i=1; i<=m; i++){
		int a=rand(1,n);
		int b=rand(1,n);

		while (container.find({a,b}) != container.end()){
			a=rand(1,n);
			b=rand(1,n);
		}
		container.insert({a,b});
	}
		
	for(auto p: container) cout<<p.first<<" "<<p.second<<endl;
}
