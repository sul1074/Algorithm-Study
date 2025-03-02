#include <string>
#include <vector>

using namespace std;

int dfs(vector<int> numbers, int target, int rst, int depth) {
    if (depth == numbers.size()) {
        if (rst == target) {
            return 1;
        }
        else return 0;
    }

    return dfs(numbers, target, rst + numbers[depth], depth + 1) + 
        dfs(numbers, target, rst - numbers[depth], depth + 1);
}

int solution(vector<int> numbers, int target) {
    int answer = dfs(numbers, target, 0, 0);

    return answer;
}
