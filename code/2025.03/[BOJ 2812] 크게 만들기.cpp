#include <string>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    for (int i = 0; i < number.length(); ++i) {
        while (k > 0 && !answer.empty() && answer.back() < number[i]) {
            --k;
            answer.pop_back();
        }

        answer += number[i];
    }

    while (k-- > 0) answer.pop_back();

    return answer;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string number;
    int n, k;

    cin >> n >> k;
    cin >> number;

    cout << solution(number, k) << '\n';
}
