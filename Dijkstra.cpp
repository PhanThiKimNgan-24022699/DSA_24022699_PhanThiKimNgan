vector<int> dijkstra(int n, const vector<vector<pii>>& adj, int src) {
    vector<int> dist(n + 1, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()) {
        auto [du, u] = pq.top();
        pq.pop();

        if(du > dist[u]) continue;

        for(auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}
