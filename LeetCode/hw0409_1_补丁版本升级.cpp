#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
#ifdef DEBUG
void dfs(const string& version, unordered_map<string, vector<string>>& graph,
    unordered_map<string, int>& depth, int current_depth) {
    depth[version] = current_depth;
    for (const string& child : graph[version]) {
        dfs(child, graph, depth, current_depth + 1);
    }
}


int main() {
    int N;
    cin >> N;
    cin.ignore(); // ���Ե�һ��ĩβ�Ļ��з�

    unordered_map<string, vector<string>> graph;
    unordered_map<string, bool> is_child;

    for (int i = 0; i < N; ++i) {
        string line;
        getline(cin, line);

        // �ָ��ַ�������ʽΪ"child parent"��"childparent"
        string child, parent;
        size_t space_pos = line.find(' ');
        if (space_pos != string::npos) {
            child = line.substr(0, space_pos);
            parent = line.substr(space_pos + 1);
        }
        else {
            // ���û�пո񣬼���ǰ������child���󲿷���parent
            // ����������������Ҫ�����ܵķָʽ
            // ����򵥼���child��parent������ͬ�򰴹̶�����ָ�
            // ��������1��CN0010BF0001 Ӧ�÷ֳ� CN0010 �� BF0001
            // ������ü򵥷ָǰ6�ַ���child����6�ַ���parent
            if (line.size() >= 12) {
                child = line.substr(0, 6);
                parent = line.substr(6, 6);
            }
            else {
                // �������12�ַ����򵥷ֳ�������
                child = line.substr(0, line.size() / 2);
                parent = line.substr(line.size() / 2);
            }
        }

        graph[parent].push_back(child);
        is_child[child] = true;
    }

    // Find root versions (those that are not children of any version)
    vector<string> roots;
    for (const auto& entry : graph) {
        const string& version = entry.first;
        if (!is_child[version]) {
            roots.push_back(version);
        }
    }

    unordered_map<string, int> depth;
    for (const string& root : roots) {
        dfs(root, graph, depth, 0);
    }

    // Find maximum depth
    int max_depth = -1;
    for (const auto& entry : depth) {
        if (entry.second > max_depth) {
            max_depth = entry.second;
        }
    }

    // Collect versions with max depth
    vector<string> result;
    for (const auto& entry : depth) {
        if (entry.second == max_depth) {
            result.push_back(entry.first);
        }
    }

    // Sort lexicographically
    sort(result.begin(), result.end());

    // Output
    for (size_t i = 0; i < result.size(); ++i) {
        if (i != 0) cout << " ";
        cout << result[i];
    }
    cout << endl;

    return 0;
}
#endif // DEBUG


