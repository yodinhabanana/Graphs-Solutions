#include <bits/stdc++.h>
using namespace std;

int shortestPath(vector<vector<pair<int, int>>>& graph, int start, int end) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;
        if (u == end) return d;

        for (auto [v, w] : graph[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist[end];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;

    while (cin >> N >> M) {
        if (N == 0 && M == 0) break; // parar aqui!

        vector<vector<pair<int, int>>> graph(N + 1);

        // lê arestas
        for (int i = 0; i < M; ++i) {
            int u, v, d;
            cin >> u >> v >> d;
            graph[u].push_back({v, d}); // direcionado
        }

        int q;
        cin >> q;

        while (q--) { // lê exatamente q operações
            char letter;
            cin >> letter;

            if (letter == 'R') {
                int u, v;
                cin >> u >> v;
                auto& adj = graph[u];
                adj.erase(remove_if(adj.begin(), adj.end(),
                                    [&](auto& edge) { return edge.first == v; }),
                          adj.end());
            } 
            else if (letter == 'I') {
                int u, v, w;
                cin >> u >> v >> w;
                graph[u].push_back({v, w});
            } 
            else if (letter == 'P') {
                int end;
                cin >> end;
                int result = shortestPath(graph, 1, end);
                if (result == INT_MAX)
                    cout << "-1\n";
                else
                    cout << result << "\n";
            }
        }

        cout << "\n"; // linha em branco após cada caso
    }

    return 0;
}
