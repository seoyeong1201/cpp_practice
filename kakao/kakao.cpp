#include <string>
#include <vector>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    return answer;
}
테스트 1
입력값 〉
"2022.05.19", ["A 6", "B 12", "C 3"], ["2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C"]
기댓값 〉
[1, 3]
실행 결과 〉
실행한 결괏값 []이 기댓값 [1,3]과 다릅니다.
테스트 2
입력값 〉
"2020.01.01", ["Z 3", "D 5"], ["2019.01.01 D", "2019.11.15 Z", "2019.08.02 D", "2019.07.01 D", "2018.12.28 Z"]
기댓값 〉
[1, 4, 5]

#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = -1;
    return answer;
}

테스트 1
입력값 〉
4, 5, [1, 0, 3, 1, 2], [0, 3, 0, 4, 0]
기댓값 〉
16
실행 결과 〉
실행한 결괏값 -1이 기댓값 16과 다릅니다.
테스트 2
입력값 〉
2, 7, [1, 0, 2, 0, 1, 0, 2], [0, 2, 0, 1, 0, 2, 0]
기댓값 〉
30

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    return answer;
}

테스트 1
입력값 〉
[[40, 10000], [25, 10000]], [7000, 9000]
기댓값 〉
[1, 5400]
실행 결과 〉
실행한 결괏값 []이 기댓값 [1,5400]과 다릅니다.
테스트 2
입력값 〉
[[40, 2900], [23, 10000], [11, 5200], [5, 5900], [40, 3100], [27, 9200], [32, 6900]], [1300, 1500, 1600, 4900]
기댓값 〉
[4, 13860]

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    return answer;
}

테스트 1
입력값 〉
[7, 5]
기댓값 〉
[1, 0]
실행 결과 〉
실행한 결괏값 []이 기댓값 [1,0]과 다릅니다.
테스트 2
입력값 〉
[63, 111, 95]
기댓값 〉
[1, 1, 0]

#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    return answer;
}

테스트 1
입력값 〉
["UPDATE 1 1 menu", "UPDATE 1 2 category", "UPDATE 2 1 bibimbap", "UPDATE 2 2 korean", "UPDATE 2 3 rice", "UPDATE 3 1 ramyeon", "UPDATE 3 2 korean", "UPDATE 3 3 noodle", "UPDATE 3 4 instant", "UPDATE 4 1 pasta", "UPDATE 4 2 italian", "UPDATE 4 3 noodle", "MERGE 1 2 1 3", "MERGE 1 3 1 4", "UPDATE korean hansik", "UPDATE 1 3 group", "UNMERGE 1 4", "PRINT 1 3", "PRINT 1 4"]
기댓값 〉
["EMPTY", "group"]
실행 결과 〉
실행한 결괏값 []이 기댓값 ["EMPTY","group"]과 다릅니다.
테스트 2
입력값 〉
["UPDATE 1 1 a", "UPDATE 1 2 b", "UPDATE 2 1 c", "UPDATE 2 2 d", "MERGE 1 1 1 2", "MERGE 2 2 2 1", "MERGE 2 1 1 1", "PRINT 1 1", "UNMERGE 2 2", "PRINT 1 1"]
기댓값 〉
["d", "EMPTY"]

#include <string>
#include <vector>

using namespace std;

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    return answer;
}

테스트 1
입력값 〉
3, 4, 2, 3, 3, 1, 5
기댓값 〉
"dllrl"
실행 결과 〉
실행한 결괏값 ""이 기댓값 "dllrl"과 다릅니다.
테스트 2
입력값 〉
2, 2, 1, 1, 2, 2, 2
기댓값 〉
"dr"
실행 결과 〉
실행한 결괏값 ""이 기댓값 "dr"과 다릅니다.
테스트 3
입력값 〉
3, 3, 1, 2, 3, 3, 4
기댓값 〉
"impossible"

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<int>> edges, vector<int> target) {
    vector<int> answer;
    return answer;
}

테스트 1
입력값 〉
[[2, 4], [1, 2], [6, 8], [1, 3], [5, 7], [2, 5], [3, 6], [6, 10], [6, 9]], [0, 0, 0, 3, 0, 0, 5, 1, 2, 3]
기댓값 〉
[1, 1, 2, 2, 2, 3, 3]
실행 결과 〉
실행한 결괏값 []이 기댓값 [1,1,2,2,2,3,3]과 다릅니다.
테스트 2
입력값 〉
[[1, 2], [1, 3]], [0, 7, 3]
기댓값 〉
[1, 1, 3, 2, 3]
실행 결과 〉
실행한 결괏값 []이 기댓값 [1,1,3,2,3]과 다릅니다.
테스트 3
입력값 〉
[[1, 3], [1, 2]], [0, 7, 1]
기댓값 〉
[-1]