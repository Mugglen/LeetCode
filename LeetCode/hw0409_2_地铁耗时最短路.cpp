#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <climits>
#include <sstream>
using namespace std;

#ifdef DEBUG
struct Edge {
    string to;
    int time;
};

struct Node {
    string name;
    int dist;
    bool operator>(const Node& other) const {
        return dist > other.dist;
    }
};

void dijkstra(unordered_map<string, vector<Edge>>& graph,
    const string& start,
    const string& end,
    unordered_map<string, int>& dist,
    unordered_map<string, string>& prev) {
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    dist[start] = 0;
    pq.push({ start, 0 });

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        if (current.name == end) break;
        if (current.dist > dist[current.name]) continue;

        for (const Edge& edge : graph[current.name]) {
            int new_dist = current.dist + edge.time;
            if (new_dist < dist[edge.to]) {
                dist[edge.to] = new_dist;
                prev[edge.to] = current.name;
                pq.push({ edge.to, new_dist });
            }
        }
    }
}

vector<string> reconstructPath(const unordered_map<string, string>& prev,
    const string& start,
    const string& end) {
    vector<string> path;
    string current = end;
    while (current != start) {
        path.push_back(current);
        current = prev.at(current);
    }
    path.push_back(start);
    reverse(path.begin(), path.end());
    return path;
}


int main() {
    int N;
    string line;

    // 读取第一行N
    getline(cin, line);
    stringstream ss(line);
    ss >> N;

    // 读取起点和终点
    string start, end;
    getline(cin, line);
    stringstream ss2(line);
    ss2 >> start >> end;

    unordered_map<string, vector<Edge>> graph;
    unordered_map<string, int> dist;
    unordered_map<string, string> prev;

    // 读取站点连接关系
    while (getline(cin, line)) {
        if (line == "0000") break;

        string from, to;
        int time;
        stringstream ss3(line);
        ss3 >> from >> to >> time;

        graph[from].push_back({ to, time });
        graph[to].push_back({ from, time });
        dist[from] = INT_MAX;
        dist[to] = INT_MAX;
    }

    dijkstra(graph, start, end, dist, prev);

    vector<string> path = reconstructPath(prev, start, end);

    // 输出路径
    for (size_t i = 0; i < path.size(); ++i) {
        if (i != 0) cout << " ";
        cout << path[i];
    }
    cout << endl;

    return 0;
}
#endif // DEBUG

