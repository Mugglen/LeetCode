#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

// ����ͼ���� V ���ڵ�� E ���ߣ� NΪ���������� kΪ�����ȵİ汾����
// ʱ�临�Ӷȣ���ͼ���Ӷ�O��N��,DFS���Ӷ�O��V+E��������ַ���˳������ĸ��Ӷ�O(k log k)
// �ռ临�Ӷȣ��汾�洢�ĸ��Ӷ�O��V�����ݹ�ջ���Ӷ�O��V��


#ifdef DEBUG
// �������������DFS�����������ڱ����汾����ͼ������¼ÿ���汾�����

void dfs(const string& version, unordered_map<string, vector<string>>& graph,
    unordered_map<string, int>& depth, int current_depth) {

    // ע����ĿҪ������ĵ����������ĵ�ǰ�汾�����ǵ�ǰ�汾��ԭʼ�汾�����Կ�����ôд
    depth[version] = current_depth;  // ��¼��ǰ�汾�����
    // ������ǰ�汾�������Ӱ汾���ݹ����DFS
    for (const string& child : graph[version]) {
        dfs(child, graph, depth, current_depth + 1);  // ��ǰ��� + 1
    }
}


int main() {
    int N;
    cin >> N;  // ��ȡ�汾������ϵ������
    cin.ignore(); // ���Ե�һ��ĩβ�Ļ��з�

    unordered_map<string, vector<string>> graph;  // �汾������ϵͼ����Ϊ���汾��ֵΪ�Ӱ汾���б�
    unordered_map<string, bool> is_child;  // ���ڼ�¼��Щ�汾��ĳ���汾���Ӱ汾

    // ��ȡ���а汾��ϵ��������ͼ
    for (int i = 0; i < N; ++i) {
        string line;
        getline(cin, line);  // ��ȡÿ������

        // �ָ��ַ�������ʽΪ"child parent"��"childparent"
        string child, parent;
        size_t space_pos = line.find(' ');  // ���ҿո��λ��
        if (space_pos != string::npos) {
            // ������ڿո񣬰��տո�ָ��ַ���
            child = line.substr(0, space_pos);  // �Ӱ汾
            parent = line.substr(space_pos + 1);  // ���汾
        }
        else {
            // ���û�пո񣬼���ǰ�������Ӱ汾���󲿷��Ǹ��汾
            // ����child��parent������ͬ�򰴹̶�����ָ�
            if (line.size() >= 12) {
                // ����ַ�����������Ϊ12�����ϸ�ʽ���򣩣�ǰ6���ַ�Ϊ�Ӱ汾����6���ַ�Ϊ���汾
                child = line.substr(0, 6);
                parent = line.substr(6, 6);
            }
            else {
                // �������12���ַ����򵥵ؽ��ַ�����Ϊ������
                child = line.substr(0, line.size() / 2);
                parent = line.substr(line.size() / 2);
            }
        }

        // ���Ӱ汾��ӵ����汾�������б���
        graph[parent].push_back(child);
        is_child[child] = true;  // ��ǵ�ǰ�汾��ĳ���汾���Ӱ汾
    }

    // �ҵ����и��汾����Щ�����κΰ汾���Ӱ汾��
    vector<string> roots;
    for (const auto& entry : graph) {
        const string& version = entry.first;
        if (!is_child[version]) {
            roots.push_back(version);  // ����ð汾�����Ӱ汾�����Ǹ��汾
        }
    }

    unordered_map<string, int> depth;  // ���ڼ�¼ÿ���汾�����
    // �����и��汾��ʼ������DFS����
    for (const string& root : roots) {
        dfs(root, graph, depth, 0);  // ��ȴ�0��ʼ
    }

    // ����������
    int max_depth = -1;
    for (const auto& entry : depth) {
        if (entry.second > max_depth) {
            max_depth = entry.second;  // ����������
        }
    }

    // �ռ����������ȵİ汾
    vector<string> result;
    for (const auto& entry : depth) {
        if (entry.second == max_depth) {
            result.push_back(entry.first);  // ����汾����ȵ��������ȣ���ӵ������
        }
    }

    // ���ֵ���Խ����������
    sort(result.begin(), result.end());

    // ������
    for (size_t i = 0; i < result.size(); ++i) {
        if (i != 0) cout << " ";  // ���ǵ�һ��Ԫ��ǰ����ո�
        cout << result[i];  // ����汾��
    }
    cout << endl;

    return 0;
}
#endif // DEBUG


