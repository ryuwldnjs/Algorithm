#include <iostream>
#include <vector>
using namespace std;
int n,m;
vector<int> parent(1000000+50, -1);

int find(int n){
	if(parent[n] < 0) return n;//루트노드 숫자 반환 
	
	return parent[n] = find(parent[n]);
}

bool merge(int a, int b){
	a = find(a);//a의 루트 찾기 
	b = find(b);//b의 루트 찾기 
	
	if(a == b) return 0;
	parent[a] += parent[b];
	parent[b] = a;
	return 1;
}
void verifyComponent(int a, int b){
	a = find(a);
	b = find(b);
	
	if(a==b) cout<<"YES\n";
	else cout<<"NO\n";
}
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false); 
	cin>>n>>m;
	
	for(int i=0;i<m;i++){
		int option, a,b;
		cin>>option>>a>>b;
		
		if(option) verifyComponent(a,b);
		else merge(a,b);
	}
	return 0;
}