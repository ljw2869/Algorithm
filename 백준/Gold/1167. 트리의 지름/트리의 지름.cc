#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> edge;
vector<vector<edge>> tree;
vector<bool> visited;
vector<int> dist;

void BFS(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto &e : tree[node]) {
            if (!visited[e.first]) {
                q.push(e.first);
                visited[e.first] = true;
                dist[e.first] = dist[node] + e.second;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int v;
    cin >> v;
    tree.resize(v + 1);

    int u, w;
    for (int i = 1; i <= v; i++) {
        int s;
        cin >> s;
        while (true) {
            cin >> u;
            if (u == -1) break;
            cin >> w;
            tree[s].push_back(edge(u, w));
            tree[u].push_back(edge(s, w)); // 양방향 간선 추가 🔥
        }
    }

    dist.assign(v + 1, 0);
    visited.assign(v + 1, false);
    BFS(1);

    int endpoint = 1;
    for (int i = 2; i <= v; i++) {
        if (dist[i] > dist[endpoint]) {
            endpoint = i;
        }
    }

    dist.assign(v + 1, 0);
    visited.assign(v + 1, false);
    BFS(endpoint);

    cout << *max_element(dist.begin(), dist.end()) << "\n";

    return 0;
}
