# 유니온파인드(disjoint-set)
### union연산 : 두 컴포넌트를 union
### find연산 : 정점의 최상단 루트를 find
```c
vector<int> parent(1000000+50, -1);
//음수일경우 본인이 루트노드, 절댓값 크기는 컴포넌트 사이즈를 의미

int find(int n){
	if(parent[n] < 0) return n;
	
	return parent[n] = find(parent[n]); //경로압축
}

bool merge(int a, int b){
	a = find(a); //a의 루트 찾기 
	b = find(b); //b의 루트 찾기 
	
	if(a == b) return false;
	parent[a] += parent[b];
	parent[b] = a;
	return true;
}
```