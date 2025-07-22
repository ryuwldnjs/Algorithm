#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll INF = 1e18;

// 직선 f(x) = ax + b
struct Line{
    ll a,b;
    double start = -INF;

    bool operator<(const double x)const{
        return start <= x;
    }
};

//두 직선의 교점 x
double cross(Line &f, Line &g){
    return (double)(g.b - f.b) / (f.a - g.a);
}

// Convex Hull에 쌓이는 직선들
vector<Line> hull;

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;
    vector<ll> a(n), b(n), dp(n);
    
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];

    for(int i=1;i<n;i++){
        Line g = {b[i-1], dp[i-1]};

        while(!hull.empty()){
            g.start = cross(hull.back(), g);
            if(hull.back().start < g.start) break;
            hull.pop_back();
        }
        hull.emplace_back(g);

        // x = a[i]에서의 최소값을 주는 직선 찾기
        ll x = a[i];
        int idx = lower_bound(hull.begin(), hull.end(), x) - hull.begin();
        if(idx > 0) idx--;

        dp[i] = hull[idx].a * x + hull[idx].b;
    }
    
    cout<<dp[n-1];
    return 0;
}