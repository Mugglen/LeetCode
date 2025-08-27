//#include <iostream>
//#include <vector>
//#include <unordered_map>
//#include <algorithm>
//
//using namespace std;
//
//vector<vector<int>> tree;
//vector<int> vals;
//int result = 0;
//
//void dfs(int node, int parent, unordered_map<int, int>& count) {
//    int val = vals[node];
//    unordered_map<int, int> temp_count;
//
//    // 遍历所有子节点
//    for (int child : tree[node]) {
//        if (child == parent) continue;
//
//        unordered_map<int, int> child_count;
//        dfs(child, node, child_count);
//
//        // 合并子节点的结果
//        for (auto it = child_count.begin(); it != child_count.end(); ++it) {
//            int key = it->first;
//            int value = it->second;
//
//            if (key < val) {
//                temp_count[key] += value;
//            }
//            else if (key == val) {
//                result += value;  // 找到以当前节点为终点的好路径
//                temp_count[key] += value;
//            }
//            // key > val 的情况不处理
//        }
//    }
//
//    // 当前节点本身也是一个好路径（单节点）
//    result++;
//    count[val] = 1;  // 当前节点自身
//
//    // 合并临时计数
//    for (auto it = temp_count.begin(); it != temp_count.end(); ++it) {
//        count[it->first] += it->second;
//    }
//}
//
//int main() {
//    int n;
//    cin >> n;
//
//    vals.resize(n + 1);
//    for (int i = 1; i <= n; ++i) {
//        cin >> vals[i];
//    }
//
//    tree.resize(n + 1);
//    for (int i = 0; i < n - 1; ++i) {
//        int u, v;
//        cin >> u >> v;
//        tree[u].push_back(v);
//        tree[v].push_back(u);
//    }
//
//    unordered_map<int, int> count;
//    dfs(1, -1, count);
//
//    cout << result << endl;
//
//    return 0;
//}

//#include <iostream>
//#include <unordered_map>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//vector<vector<int>> tree;
//vector<int> vals;
//int result = 0;
//
//void dfs(int node, int parent, unordered_map<int, int>& count) {
//    int val = vals[node];
//    unordered_map<int, int> temp_count;
//
//    for (int child : tree[node]) {
//        if (child == parent) continue;
//
//        unordered_map<int, int> child_count;
//        dfs(child, node, child_count);
//
//        // for(auto it = child_count.begin(); it != child_count.end(); ++it){
//        //     int key = it->first;
//        //     int value = it->second;
//
//        //     if(key < val){
//        //         temp_count[key] += value;
//        //     }else if(key == val){
//        //         result += value;
//        //         temp_count[key] += value;
//        //     }
//        // }
//        for (auto& [key, value] : child_count) {
//            if (key < val) {
//                temp_count[key] += value;
//            }
//            else if (key == val) {
//                result += value;
//                temp_count[key] += value;
//            }
//        }
//
//    }
//    result++;
//    count[val] = 1;
//
//    for (auto& [key, value] : temp_count) {
//        count[key] += value;
//    }
//}
//
//int main() {
//
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int n;
//    cin >> n;
//
//    vals.resize(n + 1);
//    tree.resize(n + 1);
//
//    for (int i = 1; i <= n; ++i) {
//        cin >> vals[i];
//    }
//
//    for (int i = 0; i < n - 1; ++i) {
//        int u, v;
//        cin >> u >> v;
//        tree[u].push_back(v);
//        tree[v].push_back(u);
//    }
//
//    unordered_map<int, int> count;
//    dfs(1, -1, count);
//
//    cout << result << endl;
//    return 0;
//
//
//}
//// 64 位输出请用 printf("%lld")