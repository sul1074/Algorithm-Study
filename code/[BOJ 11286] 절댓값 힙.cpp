#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using std::cin;
using std::cout;
using std::vector;
using std::priority_queue;

class AbsHeap {
	// 우선순위 큐에서 절대 값이 가장 작은 값이 우선순위가 가장 크도록 조정
	struct Compare {
		bool operator()(int a, int b) {
			if (std::abs(a) == std::abs(b)) {
				return a > b;
			}
			return std::abs(a) > std::abs(b);
		}
	};
	// Compare를 초기화에 사용하여 우선순위 큐의 container 저장 방식 조정
	priority_queue<int, std::vector<int>, Compare> numList;

public:
	AbsHeap() {}

	void push(int value) {
		numList.push(value);
	}

	int pop() {
		if (isEmpty()) return 0;
		else {
			int top = numList.top();
			numList.pop();

			return top;
		}
	}

	bool isEmpty() const {
		return numList.empty();
	}

	~AbsHeap() {}
};

int main(void) {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	AbsHeap heap;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int op;
		cin >> op;

		if (op == 0) cout << heap.pop() << '\n';
		else heap.push(op);
	}

	return 0;
}