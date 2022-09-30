#include <iostream>
#include <vector>
using namespace std;
// 시간초과 이분탐색??

int memoization[1000000];
bool IsMemoi[1000000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // memoization?
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        cnt = 0;
        for (int j = 0; j < N; j++) {
            if (arr[j] < arr[i]) {
                cnt++;
            }
        }
        cout << cnt << " ";
    }
    cout << "\n";
}