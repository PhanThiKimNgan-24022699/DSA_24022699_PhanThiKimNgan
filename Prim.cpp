int primMST(int n, const vector<vector<pii>>& adj, int start = 1) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<bool> visited(n + 1, false);

    pq.push({0, start});
    int mst_weight = 0;

    while(!pq.empty()) {
        auto [w, u] = pq.top();
        pq.pop();

        if(visited[u]) continue;
        visited[u] = true;
        mst_weight += w;

        for(auto& edge : adj[u]) {
            int v = edge.first;
            int wt = edge.second;
            if(!visited[v]) pq.push({wt, v});
        }
    }

    return mst_weight;
}
