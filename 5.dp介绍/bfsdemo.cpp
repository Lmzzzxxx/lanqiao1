queue<int> q;
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        
        // 如果当前取出的点是终点，说明路是通的，直接返回 true
        if (curr == target) {
            return true;
        }
        
        // 遍历当前节点的所有邻居
        for (int neighbor : adj[curr]) {
            if (!visited[neighbor]) { // 如果邻居没去过（包含没被封锁），就推进探索队列
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    
    // 如果队列都掏空了还是没走到 target，说明走不通了
    return false;
