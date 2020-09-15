#include <iostream>
#include <vector>
#include <queue>
#define INF 1234567890
using namespace std;

vector<vector<int> > adj;
int n,w;
char a,b; 
int c[55][55], f[55][55], parent[55];
int totalFlow; 

//문자c를 정수로 변경 
int trans(char c){
	return c<='Z' ? c-'A' : c-'a'+26;
}

//에드몬드_카프 - Flow 알고리즘 
void networkFlow(int source, int sink){
	while(true){
		fill(parent, parent+55, -1);
		queue<int> q;
		q.push(source);
		
		while(!q.empty()){
			int now = q.front();
			q.pop();
			
			for(int i=0;i<adj[now].size();i++){
				int next = adj[now][i];
				
				if(c[now][next] - f[now][next] > 0 && parent[next] == -1){
					q.push(next);
					parent[next] = now;
				}
			}
			
		}
		
		//sink로 가는 경로가 없으면 탈출 
		if(parent[sink] == -1) break;
		
		int amount = INF;
		for(int i=sink; i!=source; i=parent[i])
			amount = min(amount, c[parent[i]][i] - f[parent[i]][i]);
		
		for(int i=sink; i!=source; i=parent[i]){
			f[parent[i]][i] += amount;
			f[i][parent[i]] -= amount;
		}
		totalFlow += amount;
	}
}


int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin>>n;
	adj.resize(55); // a~z, A~Z가 52개 
	
	for(int i=0;i<n;i++){
		cin>>a>>b>>w;
		int u = trans(a);
		int v = trans(b);
		
		adj[u].push_back(v);
		adj[v].push_back(u);
		c[u][v] += w;
		c[v][u] += w; 
	}
	
	//source가 A, sink가 B  
	networkFlow(trans('A'), trans('Z'));
	
	cout<<totalFlow;
	return 0;
}
