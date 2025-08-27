#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <climits>
#include <sstream>
using namespace std;

// 如果图中有 V 个节点和 E 条边
// 时间复杂度：图构建，Dijkstra算法，路径重构，大头在Dijkstra，所以是O（（V+E）longV）
// 空间复杂度：图的存储，优先级队列，大头在图的存储O（V+E）
#ifdef DEBUG

// 边的结构体，存储目标节点和经过该边所需的时间
struct Edge {
    string to;  // 目标节点
    int time;   // 经过该边的时间
};

// 节点的结构体，包含节点名和到该节点的最短路径时间
struct Node {
    string name;  // 节点名称
    int dist;     // 从起点到该节点的最短路径时间
    // 重载运算符，用于优先队列中比较节点的最短路径
    bool operator>(const Node& other) const {
        return dist > other.dist;
    }
};

// Dijkstra算法实现：用于计算从起点到终点的最短路径
void dijkstra(unordered_map<string, vector<Edge>>& graph,
    const string& start,
    const string& end,
    unordered_map<string, int>& dist,
    unordered_map<string, string>& prev) {

    // 使用优先队列来选择当前距离最短的节点
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    dist[start] = 0;  // 起点的距离为0
    pq.push({ start, 0 });  // 将起点加入队列

    while (!pq.empty()) {
        Node current = pq.top();  // 获取队列中距离最短的节点
        pq.pop();  // 弹出该节点

        // 如果当前节点是终点，退出循环
        if (current.name == end) break;

        // 如果当前节点的距离已经大于记录的最短距离，则跳过
        if (current.dist > dist[current.name]) continue;

        // 遍历当前节点的所有邻居节点，更新它们的最短路径
        for (const Edge& edge : graph[current.name]) {
            int new_dist = current.dist + edge.time;
            if (new_dist < dist[edge.to]) {
                dist[edge.to] = new_dist;  // 更新距离
                prev[edge.to] = current.name;  // 记录该节点的前驱节点
                pq.push({ edge.to, new_dist });  // 将更新后的节点加入队列
            }
        }
    }
}

// 根据prev哈希表重建从起点到终点的路径
vector<string> reconstructPath(const unordered_map<string, string>& prev,
    const string& start,
    const string& end) {

    vector<string> path;  // 存储路径
    string current = end;  // 从终点开始，逐步追溯回起点

    // 追溯路径，直到到达起点
    while (current != start) {
        path.push_back(current);
        current = prev.at(current);  // 获取前驱节点
    }
    path.push_back(start);  // 将起点加入路径
    reverse(path.begin(), path.end());  // 反转路径，以便从起点到终点的顺序
    return path;
}


int main() {
    int N;
    string line;

    // 读取站点数目N
    getline(cin, line);
    stringstream ss(line);
    ss >> N;

    // 读取起点和终点
    string start, end;
    getline(cin, line);
    stringstream ss2(line);
    ss2 >> start >> end;

    // 创建图结构，dist用于存储最短路径，prev用于存储每个节点的前驱节点
    unordered_map<string, vector<Edge>> graph;
    unordered_map<string, int> dist;
    unordered_map<string, string> prev;

    // 初始化dist的所有值为无穷大
    dist[start] = INT_MAX;
    dist[end] = INT_MAX;

    // 读取站点连接关系并构建图
    while (getline(cin, line)) {
        if (line == "0000") break;  // 遇到"0000"表示输入结束

        string from, to;
        int time;
        stringstream ss3(line);
        ss3 >> from >> to >> time;  // 解析每个连接的站点和所需时间

        // 在图中加入双向边
        graph[from].push_back({ to, time });
        graph[to].push_back({ from, time });
        dist[from] = INT_MAX;  // 初始化站点的最短路径为无穷大
        dist[to] = INT_MAX;  // 初始化站点的最短路径为无穷大
    }

    // 调用Dijkstra算法计算最短路径
    dijkstra(graph, start, end, dist, prev);

    // 重建从起点到终点的路径
    vector<string> path = reconstructPath(prev, start, end);

    // 输出路径
    for (size_t i = 0; i < path.size(); ++i) {
        if (i != 0) cout << " ";  // 每个站点之间用空格分隔
        cout << path[i];  // 输出站点
    }
    cout << endl;  // 换行

    return 0;
}
#endif // DEBUG


