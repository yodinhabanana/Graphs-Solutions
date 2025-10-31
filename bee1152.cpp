#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii; // (peso, vértice)

// função que calcula o custo da MST com Prim
long long prim(int m, vector<vector<pii>>& LAdj) {
    vector<bool> inTree(m, false);     // Marca se o vértice já está na MST
    priority_queue<pii, vector<pii>, greater<pii>> pq; // min-heap
    long long mst = 0;                 // custo total da MST
    int added = 0;                     // vértices adicionados

    pq.push({0, 0}); // começa do vértice 0

    while (!pq.empty() && added < m) {
        int w = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (inTree[u]) continue; // já visitado ignora

        inTree[u] = true;
        mst += w;
        added++;

        for (auto [v, peso] : LAdj[u]) {
            if (!inTree[v]) pq.push({peso, v});
        }
    }

    return mst;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    while (cin >> m >> n) {
        if (m == 0 && n == 0) break;

        vector<vector<pii>> LAdj(m);
        long long total = 0;

        for (int i = 0; i < n; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            LAdj[u].push_back({v, w});
            LAdj[v].push_back({u, w});
            total += w;
        }

        long long mst = prim(m, LAdj);
        cout << total - mst << "\n";
    }

    return 0;
}
