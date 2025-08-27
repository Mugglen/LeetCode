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
//    // ���������ӽڵ�
//    for (int child : tree[node]) {
//        if (child == parent) continue;
//
//        unordered_map<int, int> child_count;
//        dfs(child, node, child_count);
//
//        // �ϲ��ӽڵ�Ľ��
//        for (auto it = child_count.begin(); it != child_count.end(); ++it) {
//            int key = it->first;
//            int value = it->second;
//
//            if (key < val) {
//                temp_count[key] += value;
//            }
//            else if (key == val) {
//                result += value;  // �ҵ��Ե�ǰ�ڵ�Ϊ�յ�ĺ�·��
//                temp_count[key] += value;
//            }
//            // key > val �����������
//        }
//    }
//
//    // ��ǰ�ڵ㱾��Ҳ��һ����·�������ڵ㣩
//    result++;
//    count[val] = 1;  // ��ǰ�ڵ�����
//
//    // �ϲ���ʱ����
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
//// 64 λ������� printf("%lld")