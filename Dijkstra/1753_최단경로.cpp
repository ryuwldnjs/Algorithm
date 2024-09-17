/**
 * https://www.acmicpc.net/problem/1753
 * 최단경로 : G4
 * 다익스트라
 */
#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;
using pii=pair<int,int>;

vector<vector<pii>> graph; //간선정보 
priority_queue<pii, vector<pii>, greater<pii>> pq;
vector<int> dist;
int v,e,k; //정점갯수 ,간선 갯수, 시작 점 

void dijkstra(int start){
	for(int i=1;i<=v;i++) dist[i] = INF;//초기거리 무한대 설정 
	dist[start] = 0;
	pq.push({ dist[start], start }); //pair타입이라, 1번째 인자에 거리를 넣어야함
	
	while(!pq.empty()){
		int distance = pq.top().first;
 		int now = pq.top().second;
		pq.pop();
		
		if(dist[now] < distance) continue; //이미 더 짧은 경로가 있으면, 무시함
		
		for(int i=0; i<graph[now].size() ; i++){
			int next = graph[now][i].first; //다음타겟  
			int next_distance = distance + graph[now][i].second; //다음 타겟의 가중치 
			
			if(next_distance < dist[next]){
				dist[next] = next_distance; 
				pq.push({next_distance, next});
			}
		}
	}

}

int main(){
	cin>>v>>e>>k;
	graph.resize(v+1); dist.resize(v+1);

	for(int i=0;i<e;i++){
		int from, to, cost;
		cin>>from>>to>>cost;
		graph[from].push_back({to,cost});
	 } 

	 dijkstra(k);
	 for(int i=1;i<=v;i++){
		if(dist[i] == INF) cout<<"INF\n";
		else cout<<dist[i]<<'\n';
	 }
	return 0;
}