#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<vector<int>> graph;
vector<int> discovered;
set<int> ans;
int v,e, cnt;
int dfs(int now, bool isRoot){
    discovered[now] = ++cnt;
    int num = discovered[now];
    //인접노드중 가장 발견시간이 빠른 노드의 시간 저장

    int child = 0;
    for(int i=0;i<graph[now].size();i++){
        int next = graph[now][i];
        if(discovered[next] == 0){
            child++;
            int subtree = dfs(next, false);
            num = min(num, subtree);
            if(!isRoot && subtree >= discovered[now]) ans.insert(now);
        }
        else{
            num = min(num, discovered[next]);
        }
    }
    //루트노드 - 자식이 2개 이상이면 단절점
    if(isRoot && child > 1) ans.insert(now);
    return num;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>v>>e;
    graph.resize(v+1);
    discovered.resize(v+1);
    for(int i=0;i<e;i++){
        int a,b; cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1;i<=v;i++){
        if(discovered[i] == 0) dfs(i, true);
    }

    cout<<ans.size()<<'\n';
    for(auto i: ans) cout<<i<<' ';
    return 0;
}