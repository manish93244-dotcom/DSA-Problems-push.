/**
 * @param {number} V
 * @param {number} src
 * @param {number[][]} edges
 * @return {number[]}
 */
class Solution {
    maxDistance(V, src, edges) {
        // Step 1: Build adjacency list and compute in-degrees
        const adj = Array.from({ length: V }, () => []);
        const inDegree = new Array(V).fill(0);

        for (const edge of edges) {
            const u = edge[0];
            const v = edge[1];
            const w = edge[2];
            adj[u].push({ node: v, weight: w });
            inDegree[v]++;
        }

        // Step 2: Topological Sort using Kahn's Algorithm (BFS)
        const q = [];
        for (let i = 0; i < V; i++) {
            if (inDegree[i] === 0) {
                q.push(i);
            }
        }

        const topo = [];
        let head = 0;
        while (head < q.length) {
            const u = q[head++];
            topo.push(u);

            for (const neighbor of adj[u]) {
                inDegree[neighbor.node]--;
                if (inDegree[neighbor.node] === 0) {
                    q.push(neighbor.node);
                }
            }
        }

        // Step 3: Initialize distances with a very small number for INT_MIN
        const INT_MIN = -2147483648;
        const dist = new Array(V).fill(INT_MIN);
        dist[src] = 0;

        // Step 4: Relax edges in topological order for longest path
        // First find the starting point in the topological order
        let startIndex = 0;
        while (startIndex < topo.length && topo[startIndex] !== src) {
            startIndex++;
        }

        for (let i = startIndex; i < topo.length; i++) {
            const u = topo[i];
            if (dist[u] !== INT_MIN) {
                for (const neighbor of adj[u]) {
                    const v = neighbor.node;
                    const w = neighbor.weight;
                    if (dist[u] + w > dist[v]) {
                        dist[v] = dist[u] + w;
                    }
                }
            }
        }

        return dist;
    }
}