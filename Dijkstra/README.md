# 다익스트라(Dijkstra)
### 최단거리 알고리즘
Single Source Path를 찾기 위한 알고리즘

```c++ 
vector<vector<pii>> graph; 
//graph[i] : i에서 갈수있는 {vertex, cost}쌍
priority_queue<pii, vector<pii>, greater<pii>> pq;
vector<int> dist;
int v; //정점갯수

void dijkstra(int start){
	for(int i=1;i<=v;i++) dist[i] = INF;//초기거리 무한대 설정 
	dist[start] = 0;
	pq.push({ dist[start], start }); 
    //pair타입이라, 1번째 인자에 dist를 넣어야함
	
	while(!pq.empty()){
		int distance = pq.top().first;
 		int now = pq.top().second;
		pq.pop();

		//이미 더 짧은 경로가 있으면, 무시함
		if(dist[now] < distance) continue; 
		
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
```