#include <iostream>

using namespace std;

int n, e, m;
int parent[100001];

int findParent(int x) {
    if(parent[x] == x) {
        return x;
    }
    else {
        return parent[x] = findParent(parent[x]);
    }
}

int unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);

    if(a < b) {
        parent[b] = a;
    }
    else {
        parent[b] = a;
    }
}

int main() {
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for(int i = 0; i < m; i++) {
        int operation, a, b;
        cin >> operation >> a >> b;
        if(operation == 0) {
            unionParent(a, b);
        }
        else {
            if (findParent(a) == findParent(b)) {
                cout << "YES" << '\n';
            }
            else {
                cout << "NO" << '\n';
            }
        }
    }

    return 0;
}
