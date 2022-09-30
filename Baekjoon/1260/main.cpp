// #include "node.h"
#include <iostream>
// #include <sstream>
#include <queue>
using namespace std;



class Node
{
public:
    int index;
    Node* next;
public:
    Node(int idx, Node* next);
    ~Node();
};

// vector<string> split(string str, char delimiter);
void dfs(int idx, Node** adjList, bool* flag);
void bfs(int idx, Node** adjList, bool* isVisited);

int main(int argc, const char** argv) {
    int N, M, V;
    int from, to;
    cin >> N >> M >> V;

    Node* adjList[N + 1];
    for (int i = 0; i < N + 1; i++) {
        adjList[i] = NULL;
    }

    for (int i = 0; i < M; i++) {
        cin >> from >> to;
        adjList[from] = new Node(to, adjList[from]);
        adjList[to] = new Node(from, adjList[to]);
    }

    // for (Node* tmp = adjList[1]; tmp != NULL; tmp = tmp->next) {
    //     cout << tmp->index << " ";
    // }

    bool* flag = new bool[N + 1];
    dfs(V, adjList, flag);
    cout << endl;
    bool* flagBfs = new bool[N + 1];
    bfs(V, adjList, flagBfs);
    cout << endl;

    return 0;
}

void dfs(int idx, Node** adjList, bool* flag) {
    flag[idx] = true;
    cout << idx << " ";

    for (auto tmp = adjList[idx]; tmp != NULL; tmp = tmp -> next) {
        if (flag[tmp -> index]) continue;
        dfs(tmp->index, adjList, flag);
    }
}

void bfs(int idx, Node** adjList, bool* isVisited) {
    queue<int> queue;
    isVisited[idx] = true;
    queue.push(idx);

    while (!queue.empty()) {
        int visit = queue.front();
        queue.pop();
        cout << visit << " ";

        for (auto tmp = adjList[visit]; tmp != NULL; tmp = tmp -> next) {
            if (isVisited[tmp -> index]) continue;
            isVisited[tmp -> index] = true;
            queue.push(tmp -> index);
        }
    }
}

Node::Node(int idx, Node* next) {
    this->index = idx;
    this->next = next;
}

Node::~Node() {
}


// int main() {
//     string user_input;
//     vector<string> words;

//     getline(cin, user_input);
//     words = split(user_input, ' ');
//     for (int i = 0; i < words.size(); i++) {
//         cout << words[i] << endl;
//     }
// }

// vector<string> split(string input, char delimiter) {
//     vector<string> result;
//     stringstream ss(input);
//     string temp;

//     while (getline(ss, temp, delimiter)) {
//         result.push_back(temp);
//     }

//     return result;
// }