# 다익스트라(Dijkstra)
### 최단거리 알고리즘
Single Source Path를 찾기 위한 알고리즘

```c++ 
struct Info{
	int vertex, cost;
	//pq의 최소힙을 보장하기 위한 연산자 오버로딩
	bool operator<(const Info& other)const{
		return cost > other.cost;
	}
};

vector<vector<Info>> graph; 
//graph[i] : i에서 갈수있는 {vertex, cost}쌍
priority_queue<Info> pq;
vector<int> dist;
int v; //정점갯수

void dijkstra(int start){
	for(int i=1;i<=v;i++) dist[i] = INF;//초기거리 무한대 설정 
	dist[start] = 0;
	pq.push({ start, 0 }); 
	
	while(!pq.empty()){
		int now = pq.top().vertex;
		int distance = pq.top().cost;
		pq.pop();

		//이미 더 짧은 경로가 있으면, 무시함
		if(dist[now] < distance) continue; 
		
		for(int i=0; i<graph[now].size() ; i++){
			int next = graph[now][i].vertex; //다음타겟  
			int next_distance = distance + graph[now][i].cost; //다음 타겟의 가중치 
			
			if(next_distance < dist[next]){
				dist[next] = next_distance; 
				pq.push({next, next_distance});
			}
		}
	}

}
```