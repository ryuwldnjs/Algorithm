# 이분 매칭 : Bipartite Matching (DFS 기반)
### 네트워크 유량 알고리즘(DFS)
- 정의:
  - 이분 그래프: 두 개의 정점 집합이 있고, 모든 간선은 서로 다른 집합 간에만 존재하는 그래프
  - 이분 매칭: 이분 그래프에서 겹치지 않게 가능한 최대 수의 간선을 선택하는 알고리즘
- 시간복잡도: O(VE)
- 설명: https://blog.naver.com/kks227/220807541506


```c++
vector<vector<int>> graph;
vector<int> l, r;
vector<bool> visited;

// x: 왼쪽 정점
bool dfs(int x){
	if(visited[x]) return false;
	visited[x] = true;
	for(int y : graph[x]){
		// y가 매칭되지 않았거나,
		// 기존 매칭 상대 r[y]가 다른 정점과 매칭 가능하면 현재 x와 y를 매칭
		if(r[y] == -1 || dfs(r[y])){
			r[y] = x;
			l[x] = y;
			return true;
		}
	}
	return false;
}

int main(){
	int n, m; cin >> n >> m; // 왼쪽 정점 수, 오른쪽 정점 수
	l.resize(n + 1, -1);     // l[i] = i번 왼쪽 정점이 매칭한 오른쪽 정점
	r.resize(m + 1, -1);     // r[j] = j번 오른쪽 정점이 매칭한 왼쪽 정점
	graph.resize(n + 1);

	for(int a = 1; a <= n; a++){
		int x; cin >> x;
		while(x--){
			int b; cin >> b;
			graph[a].push_back(b); // a번 왼쪽 정점이 b번 오른쪽 정점과 연결됨
		}
	}

	int answer = 0;
	for(int i = 1; i <= n; i++){
		if(l[i] != -1) continue;
		visited = vector<bool>(n + 1, false);
		if(dfs(i)) answer++;
	}
	cout << answer;
	return 0;
}
```