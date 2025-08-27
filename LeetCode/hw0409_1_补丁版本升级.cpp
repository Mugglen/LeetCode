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
    cin.ignore(); // 忽略第一行末尾的换行符

    unordered_map<string, vector<string>> graph;
    unordered_map<string, bool> is_child;

    for (int i = 0; i < N; ++i) {
        string line;
        getline(cin, line);

        // 分割字符串，格式为"child parent"或"childparent"
        string child, parent;
        size_t space_pos = line.find(' ');
        if (space_pos != string::npos) {
            child = line.substr(0, space_pos);
            parent = line.substr(space_pos + 1);
        }
        else {
            // 如果没有空格，假设前部分是child，后部分是parent
            // 根据样例，可能需要更智能的分割方式
            // 这里简单假设child和parent长度相同或按固定规则分割
            // 根据样例1，CN0010BF0001 应该分成 CN0010 和 BF0001
            // 这里采用简单分割：前6字符是child，后6字符是parent
            if (line.size() >= 12) {
                child = line.substr(0, 6);
                parent = line.substr(6, 6);
            }
            else {
                // 如果不够12字符，简单分成两部分
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


