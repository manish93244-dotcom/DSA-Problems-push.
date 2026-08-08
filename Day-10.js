class Solution {
    minEdgesReq(n, edges) {
        // A graph with n vertices needs at least n - 1 edges to be connected.
        if (edges.length < n - 1) {
            return -1;
        }

        // Build adjacency list
        const adj = Array.from({ length: n }, () => []);
        for (const [u, v] of edges) {
            adj[u].push(v);
            adj[v].push(u);
        }

        const visited = new Array(n).fill(false);
        let components = 0;

        // Helper function for DFS traversal
        function dfs(node) {
            visited[node] = true;
            for (const neighbor of adj[node]) {
                if (!visited[neighbor]) {
                    dfs(neighbor);
                }
            }
        }

        // Count connected components
        for (let i = 0; i < n; i++) {
            if (!visited[i]) {
                components++;
                dfs(i);
            }
        }

        // Minimum operations needed to connect C components is C - 1
        return components - 1;
    }
}