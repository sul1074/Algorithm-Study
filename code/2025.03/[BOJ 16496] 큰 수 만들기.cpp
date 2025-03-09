#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<int> numbers) {
    vector<vector<string>> sortedNumList(10);
    string answer = "";

    for (auto num : numbers) {
        int idx = num;
        while (idx >= 10) {
            idx /= 10;
        }
        sortedNumList[idx].push_back(to_string(num));
    }

    for (int i = 0; i < 10; ++i) {
        sort(sortedNumList[i].begin(), sortedNumList[i].end(), [](string a, string b) {
                return (a + b) > (b + a);
            });
    }

    for (int i = 9; i > -1; --i) {
        for (auto col : sortedNumList[i]) {
            if (answer.empty() && col == "0") return "0";

            answer += col;
        }
    }

    return answer;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> numList(n);
    for (int i = 0; i < n; ++i) {
        cin >> numList[i];
    }

    cout << solution(numList);
}
