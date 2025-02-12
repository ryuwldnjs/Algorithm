# 세그먼트 트리(SegmentTree) :: Bottom-Up
### update(int idx,int val): arr[idx] = val 갱신 및 세그트리 재구성
### query(int l, int r): 구간 [l,r]의 구간합
```c++
struct SegmentTree {
    int size;
    vector<int> tree;

    SegmentTree(int n) {
        size = (1<<(32 - __builtin_clz(n)));
        tree.resize(2 * size);
    }

    void build(vector<int>& arr) {
        // 리프 노드 저장 (n부터 시작)
        for (int i = 0; i < arr.size(); i++)
            tree[size + i] = arr[i];

        // 부모 노드 계산 (Bottom-Up 방식)
        for (int i = size - 1; i > 0; i--)
            tree[i] = tree[2 * i] + tree[2 * i + 1];
    }

    // 점 업데이트: 특정 인덱스 값을 변경하고, 부모에 반영
    void update(int index, int value) {
        index += size;  // 리프 노드로 이동
        tree[index] = value;  // 값 변경

        // 상위 노드 갱신
        while (index > 1) {
            index /= 2;
            tree[index] = tree[2 * index] + tree[2 * index + 1];
        }
    }

    // [left, right] 구간 합
    int query(int left, int right) {
        int sum = 0;
        left += size;  // 리프 노드로 변환
        right += size; // 리프 노드로 변환

        while (left <= right) {
            if (left % 2 == 1) sum += tree[left++];  // 홀수 인덱스(오른쪽 자식) 처리 후 이동
            if (right % 2 == 0) sum += tree[right--]; // 짝수 인덱스(왼쪽 자식) 처리 후 이동
            left /= 2, right /= 2; // 부모로 이동
        }
        return sum;
    }
};

```
