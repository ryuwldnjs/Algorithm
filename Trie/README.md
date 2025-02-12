# 트라이(Trie)
### insert: Trie에 문자열 삽입
### search: Trie에서 문자열 검색 
```c++
struct Node {
    unordered_map<char, Node*> children;
    bool isEndOfWord = false;
};

struct Trie {
    Node* root;

    Trie() {
        root = new Node();
    }

    ~Trie() { //다중 테스트케이스 메모리 초과 방지
        deleteTrie(root);
    }
    void deleteTrie(Node* node) {
        for (auto& child : node->children) { 
            deleteTrie(child.second);
        }
        delete node;
    }

    void insert(const string& word) {
        Node* node = root;
        for (char ch : word) {
            if (node->children.count(ch) == 0)
                node->children[ch] = new Node();
            node = node->children[ch];
        }
        node->isEndOfWord = true;
    }

    // 문자열 존재 여부 확인
    bool search(const string& word) {
        Node* node = root;
        for (char ch : word) {
            if (node->children.count(ch) == 0) return false;
            node = node->children[ch];
        }
        return node->isEndOfWord;
    }
};
```
