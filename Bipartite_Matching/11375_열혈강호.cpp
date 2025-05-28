#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> graph;
vector<int> l,r;
vector<bool> visited;

bool dfs(int x){
	if(visited[x]) return false;
	visited[x] = true;
    for(int y: graph[x]){
        if(r[y] == -1 || dfs(r[y])){
            r[y] = x;
            l[x] = y;
            return true;
        }
    }
	return false;
}

int main(){
	int n,m; cin>>n>>m;
    l.resize(n+1, -1);
    r.resize(m+1, -1);
    graph.resize(n+1);

    for(int a=1;a<=n;a++){
        int x; cin>>x;
        while(x--){
            int b;cin>>b;
            graph[a].push_back(b);
        }
    }

    int answer=0;
	for(int i=1;i<=n;i++){
        if(l[i] != -1) continue;
        visited = vector<bool>(n+1);
		if(dfs(i)) answer++;
	}
	cout<<answer;
	return 0;
}