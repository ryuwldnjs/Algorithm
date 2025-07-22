# 컨벡스 헐 트릭 (Convex Hull Trick)
`동적 계획법 / 최적화`

## 정의
- 다음 점화식을 빠르게 계산하기 위한 최적화 기법이다.
  - `dp[i] = min(dp[j] + B[j] * A[i])  (j < i)`

- 각 항은 기울기 `B[j]`와 절편 `dp[j]`를 가지는 직선으로 표현할 수 있으며,
  `A[i]`에서 최소값을 가지는 직선을 찾는 문제로 해석할 수 있다.
- A[i]가 단조 증가하거나, 쿼리 순서가 고정되어 있을 때 사용할 수 있다.



## 핵심 아이디어
- `dp[j] + B[j] * A[i]` 형태를 **f(x) = B[j] * x + dp[j]** 라는 직선으로 보고,
  여러 직선 중 x = A[i]에서 최소값을 주는 직선을 찾는다.
- 각 직선은 `start` 구간부터 유효하며, 교점(cross point)을 기준으로 구간이 나뉜다.
- 이진 탐색을 사용해 \( O(\log N) \)에 최소값을 주는 직선을 빠르게 찾는다.
- 새로운 직선을 추가할 때 더 이상 필요 없는 직선은 제거(pop)한다.



## 코드 예시
```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

// 직선 f(x) = ax + b
struct Line {
    ll a, b;
    double start = -INF;

    bool operator<(const double x) const {
        return start <= x;
    }
};

// 두 직선의 교점 x좌표 계산
double cross(Line &f, Line &g) {
    return (double)(g.b - f.b) / (f.a - g.a);
}

// Convex Hull에 쌓이는 직선들
vector<Line> hull;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;

    vector<ll> a(n), b(n), dp(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    for (int i = 1; i < n; i++) {
        Line g = {b[i - 1], dp[i - 1]};

        while (!hull.empty()) {
            g.start = cross(hull.back(), g);
            if (hull.back().start < g.start) break;
            hull.pop_back();
        }
        hull.emplace_back(g);

        // x = a[i]에서의 최소값을 주는 직선 찾기
        ll x = a[i];
        int idx = lower_bound(hull.begin(), hull.end(), x) - hull.begin();
        if (idx > 0) idx--;

        dp[i] = hull[idx].a * x + hull[idx].b;
    }

    cout << dp[n - 1];
    return 0;
}
```