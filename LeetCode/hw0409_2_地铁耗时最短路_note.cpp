#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <climits>
#include <sstream>
using namespace std;

// ���ͼ���� V ���ڵ�� E ����
// ʱ�临�Ӷȣ�ͼ������Dijkstra�㷨��·���ع�����ͷ��Dijkstra��������O����V+E��longV��
// �ռ临�Ӷȣ�ͼ�Ĵ洢�����ȼ����У���ͷ��ͼ�Ĵ洢O��V+E��
#ifdef DEBUG

// �ߵĽṹ�壬�洢Ŀ��ڵ�;����ñ������ʱ��
struct Edge {
    string to;  // Ŀ��ڵ�
    int time;   // �����ñߵ�ʱ��
};

// �ڵ�Ľṹ�壬�����ڵ����͵��ýڵ�����·��ʱ��
struct Node {
    string name;  // �ڵ�����
    int dist;     // ����㵽�ýڵ�����·��ʱ��
    // ������������������ȶ����бȽϽڵ�����·��
    bool operator>(const Node& other) const {
        return dist > other.dist;
    }
};

// Dijkstra�㷨ʵ�֣����ڼ������㵽�յ�����·��
void dijkstra(unordered_map<string, vector<Edge>>& graph,
    const string& start,
    const string& end,
    unordered_map<string, int>& dist,
    unordered_map<string, string>& prev) {

    // ʹ�����ȶ�����ѡ��ǰ������̵Ľڵ�
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    dist[start] = 0;  // ���ľ���Ϊ0
    pq.push({ start, 0 });  // �����������

    while (!pq.empty()) {
        Node current = pq.top();  // ��ȡ�����о�����̵Ľڵ�
        pq.pop();  // �����ýڵ�

        // �����ǰ�ڵ����յ㣬�˳�ѭ��
        if (current.name == end) break;

        // �����ǰ�ڵ�ľ����Ѿ����ڼ�¼����̾��룬������
        if (current.dist > dist[current.name]) continue;

        // ������ǰ�ڵ�������ھӽڵ㣬�������ǵ����·��
        for (const Edge& edge : graph[current.name]) {
            int new_dist = current.dist + edge.time;
            if (new_dist < dist[edge.to]) {
                dist[edge.to] = new_dist;  // ���¾���
                prev[edge.to] = current.name;  // ��¼�ýڵ��ǰ���ڵ�
                pq.push({ edge.to, new_dist });  // �����º�Ľڵ�������
            }
        }
    }
}

// ����prev��ϣ���ؽ�����㵽�յ��·��
vector<string> reconstructPath(const unordered_map<string, string>& prev,
    const string& start,
    const string& end) {

    vector<string> path;  // �洢·��
    string current = end;  // ���յ㿪ʼ����׷�ݻ����

    // ׷��·����ֱ���������
    while (current != start) {
        path.push_back(current);
        current = prev.at(current);  // ��ȡǰ���ڵ�
    }
    path.push_back(start);  // ��������·��
    reverse(path.begin(), path.end());  // ��ת·�����Ա����㵽�յ��˳��
    return path;
}


int main() {
    int N;
    string line;

    // ��ȡվ����ĿN
    getline(cin, line);
    stringstream ss(line);
    ss >> N;

    // ��ȡ�����յ�
    string start, end;
    getline(cin, line);
    stringstream ss2(line);
    ss2 >> start >> end;

    // ����ͼ�ṹ��dist���ڴ洢���·����prev���ڴ洢ÿ���ڵ��ǰ���ڵ�
    unordered_map<string, vector<Edge>> graph;
    unordered_map<string, int> dist;
    unordered_map<string, string> prev;

    // ��ʼ��dist������ֵΪ�����
    dist[start] = INT_MAX;
    dist[end] = INT_MAX;

    // ��ȡվ�����ӹ�ϵ������ͼ
    while (getline(cin, line)) {
        if (line == "0000") break;  // ����"0000"��ʾ�������

        string from, to;
        int time;
        stringstream ss3(line);
        ss3 >> from >> to >> time;  // ����ÿ�����ӵ�վ�������ʱ��

        // ��ͼ�м���˫���
        graph[from].push_back({ to, time });
        graph[to].push_back({ from, time });
        dist[from] = INT_MAX;  // ��ʼ��վ������·��Ϊ�����
        dist[to] = INT_MAX;  // ��ʼ��վ������·��Ϊ�����
    }

    // ����Dijkstra�㷨�������·��
    dijkstra(graph, start, end, dist, prev);

    // �ؽ�����㵽�յ��·��
    vector<string> path = reconstructPath(prev, start, end);

    // ���·��
    for (size_t i = 0; i < path.size(); ++i) {
        if (i != 0) cout << " ";  // ÿ��վ��֮���ÿո�ָ�
        cout << path[i];  // ���վ��
    }
    cout << endl;  // ����

    return 0;
}
#endif // DEBUG


