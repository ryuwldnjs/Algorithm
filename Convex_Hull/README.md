# 볼록껍질 : 모노톤체인 (Convex Hull :Monotone Chain)
`기하`

## 정의
- `볼록껍질` :2차원 평면 위의 점들을 모두 포함하는 가장 작은 볼록 다각형
- `모노톤체인` : 2차원 점들을 x좌표 기준으로 정렬한 뒤, 시계/반시계 방향으로 각각 스캔하여 윗껍질과 아랫껍질을 구하고 이를 합쳐 볼록 껍질을 완성하는 기하 알고리즘

```c++
struct Point{
    ll x, y;
    bool operator<(const Point& other) const{
        if(x == other.x) return y < other.y;
        return x < other.x;
    }
};

int n;
vector<Point> p;

int ccw(Point a, Point b, Point c){
    //int형은 oveflow발생
    ll val = (a.x*b.y + b.x*c.y + c.x*a.y) - (a.y*b.x + b.y*c.x + c.y*a.x);
    if(val > 0) return 1; //반시계
    if(val == 0) return 0; // 직선
    if(val < 0) return -1; // 시계
}

// 원하는 clock_wise방향으로 껍질 구성
void make_hull(stack<Point> &s, int clock_wise){
    s.push(p[0]); s.push(p[1]);
    for(int i=2;i<n;i++){
        while(s.size() >= 2){
            Point b = s.top(); s.pop();
            Point a = s.top();
            if(ccw(a, b, p[i]) == clock_wise){//원하는 방향
                s.push(b);
                break;
            }
        }
        s.push(p[i]);
    }

}
//stack대신 vector사용 권장
void convex_hull(){
    sort(p.begin(), p.end());
    stack<Point> s1, s2;
    
    //윗껍질: 시계방향
    make_hull(s1, -1);
    //아랫껍질: 반시계방향
    make_hull(s2, 1);

    int answer = s1.size() + s2.size() - 2;
    cout<<answer;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y; cin>>x>>y;
        p.push_back({x,y});
    }

    convex_hull();
    return 0;
}
```