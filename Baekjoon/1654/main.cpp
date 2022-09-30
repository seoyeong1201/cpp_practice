#include <iostream>
#include <vector>
using namespace std;
// 시간초과
// 이분탐색 찾아볼까?
// parametric search

int K, N;
vector<int> line;
long sum;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> K >> N;
    // vector<int> line(K);
    sum = 0;

    int input;
    for (int i = 0; i < K; i++) {
        cin >> input;
        line.push_back(input);
        sum += line[i];
    }

    long start = sum / N;
    long interval = start / 2;
    // cout<< line[0] << endl;
    // cout << start << endl;
    while (true) {
        start--;
    }
}

bool check(int lineLength) {
    int count = 0;
    for (int i = 0; i < K; i++) {
        count += line[i] / lineLength;
    }
    // cout << sum << " " << start << " " << count << endl; //test
    if (count >= N) {
        // cout << start << "\n";
        // break;
        return true;
    } else {
        return false;
    }
}