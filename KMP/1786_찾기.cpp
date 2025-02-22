#include <iostream>
#include <vector>
using namespace std;

vector<int> makeTable(string& pattern){
    int n = pattern.size();
    vector<int> pi(n);
    int j=0;
    for(int i=1;i<n;i++){
        while(j>0 && pattern[i] != pattern[j]) j = pi[j-1];
        if(pattern[i] == pattern[j]){
            pi[i] = j+1;
            j++;
        }
    }
    return pi;
}
void KMP(string& parent, string& pattern){
    vector<int> ans;
    vector<int> pi = makeTable(pattern);
    int n = parent.size();
    int m = pattern.size();
    int j=0;

    for(int i=0;i<n;i++){ // parent
        while(j>0 && parent[i] != pattern[j]) j = pi[j-1];
        if(parent[i] == pattern[j]){
            if(j == m-1){
                ans.push_back(i-m+2);
                j = pi[j];
            }
            else j++;
        }
    }

    cout<<ans.size()<<'\n';
    for(int i: ans) cout<<i<<' ';

}
int main(){
    string parent, pattern;
    getline(cin, parent);
    getline(cin, pattern);
    KMP(parent, pattern);
    return 0;
}