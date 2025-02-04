#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::vector;
using std::string;

// 배열의 순서를 바꾸는 것이 아닌, 참조 시의 index를 역순으로 하면 되지 않을까?
class AC {
	vector<int> numList;
	int indexingDir, head, tail; // 0이면 정방향(0, 1, ..) 1이면 역방향(n, n - 1, ...)
	bool errored;

public:
	AC(int listLen, const vector<int>& listInput)
		: numList(listInput), indexingDir(0), head(0), tail(listLen), errored(false)
	{
	}

	void printAns() const {
		if (errored) {
			cout << "error" << '\n';
			return;
		}

		cout << '[';
		// 정방향
		if (indexingDir == 0) {
			for (int i = head; i < tail; ++i) {
				cout << numList[i];
				if (i != tail - 1) cout << ',';
			}
		}
		// 역방향
		else {
			for (int i = tail - 1; i >= head; --i) {
				cout << numList[i];
				if (i != head) cout << ',';
			}
		}
		cout << ']' << '\n';
	}

	void reverse() { indexingDir = 1 - indexingDir; }

	void pop() {
		if (head >= tail) {
			errored = true;
			return;
		}

		if (indexingDir == 0) head++;
		else tail--;
	}

	~AC() {}
};

int main(void) {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	for (int time = 0; time < t; ++time) {
		string func, listInput;
		vector<int> numList;
		int listLen;

		cin >> func >> listLen >> listInput;

		string listTemp;
		for (auto ch : listInput) {
			if (std::isdigit(ch)) {
				listTemp += ch; // 숫자면, stoi 함수 사용을 위해 문자열로 변환
			}
			// 하나의 숫자 문자열이 끝나면 그 숫자 문자열로 int형으로 변환
			else if (!listTemp.empty()) {
				int num = std::stoi(listTemp);
				numList.push_back(num);
				listTemp.clear(); // 다음 숫자 문자열 처리를 위해 초기화
			}
		}

		AC ac(listLen, numList);

		for (auto op : func) {
			switch (op) {
			case 'R':
				ac.reverse();
				break;
			case 'D':
				ac.pop();
				break;
			}
		}

		ac.printAns();
	}

	return 0;
}