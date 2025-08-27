#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

// 假设图中有 V 个节点和 E 条边， N为输入行数， k为最大深度的版本数量
// 时间复杂度：建图复杂度O（N）,DFS复杂度O（V+E），最后字符串顺序排序的复杂度O(k log k)
// 空间复杂度：版本存储的复杂度O（V），递归栈复杂度O（V）


#ifdef DEBUG
// 深度优先搜索（DFS）函数，用于遍历版本依赖图，并记录每个版本的深度

void dfs(const string& version, unordered_map<string, vector<string>>& graph,
    unordered_map<string, int>& depth, int current_depth) {

    // 注意题目要求输出的迭代次数最多的当前版本，不是当前版本的原始版本，所以可以这么写
    depth[version] = current_depth;  // 记录当前版本的深度
    // 遍历当前版本的所有子版本，递归调用DFS
    for (const string& child : graph[version]) {
        dfs(child, graph, depth, current_depth + 1);  // 当前深度 + 1
    }
}


int main() {
    int N;
    cin >> N;  // 读取版本依赖关系的数量
    cin.ignore(); // 忽略第一行末尾的换行符

    unordered_map<string, vector<string>> graph;  // 版本依赖关系图，键为父版本，值为子版本的列表
    unordered_map<string, bool> is_child;  // 用于记录哪些版本是某个版本的子版本

    // 读取所有版本关系，并建立图
    for (int i = 0; i < N; ++i) {
        string line;
        getline(cin, line);  // 读取每行输入

        // 分割字符串，格式为"child parent"或"childparent"
        string child, parent;
        size_t space_pos = line.find(' ');  // 查找空格的位置
        if (space_pos != string::npos) {
            // 如果存在空格，按照空格分割字符串
            child = line.substr(0, space_pos);  // 子版本
            parent = line.substr(space_pos + 1);  // 父版本
        }
        else {
            // 如果没有空格，假设前部分是子版本，后部分是父版本
            // 假设child和parent长度相同或按固定规则分割
            if (line.size() >= 12) {
                // 如果字符串长度至少为12（符合格式规则），前6个字符为子版本，后6个字符为父版本
                child = line.substr(0, 6);
                parent = line.substr(6, 6);
            }
            else {
                // 如果不够12个字符，简单地将字符串分为两部分
                child = line.substr(0, line.size() / 2);
                parent = line.substr(line.size() / 2);
            }
        }

        // 将子版本添加到父版本的依赖列表中
        graph[parent].push_back(child);
        is_child[child] = true;  // 标记当前版本是某个版本的子版本
    }

    // 找到所有根版本（那些不是任何版本的子版本）
    vector<string> roots;
    for (const auto& entry : graph) {
        const string& version = entry.first;
        if (!is_child[version]) {
            roots.push_back(version);  // 如果该版本不是子版本，则是根版本
        }
    }

    unordered_map<string, int> depth;  // 用于记录每个版本的深度
    // 从所有根版本开始，进行DFS遍历
    for (const string& root : roots) {
        dfs(root, graph, depth, 0);  // 深度从0开始
    }

    // 查找最大深度
    int max_depth = -1;
    for (const auto& entry : depth) {
        if (entry.second > max_depth) {
            max_depth = entry.second;  // 更新最大深度
        }
    }

    // 收集所有最大深度的版本
    vector<string> result;
    for (const auto& entry : depth) {
        if (entry.second == max_depth) {
            result.push_back(entry.first);  // 如果版本的深度等于最大深度，添加到结果中
        }
    }

    // 按字典序对结果进行排序
    sort(result.begin(), result.end());

    // 输出结果
    for (size_t i = 0; i < result.size(); ++i) {
        if (i != 0) cout << " ";  // 不是第一个元素前输出空格
        cout << result[i];  // 输出版本号
    }
    cout << endl;

    return 0;
}
#endif // DEBUG


