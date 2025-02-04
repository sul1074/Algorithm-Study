#include <iostream>
#include <vector>
#include <cmath>

using std::cin;
using std::cout;
using std::vector;
using std::abs;

class AbsHeap {
	vector<int> heap;

public:
	AbsHeap() {
		heap.push_back(0); // index 계산 편의성을 위해, 0 index는 사용 X
	}

	void push(int value) {
		heap.push_back(value);
		int idx = heap.size() - 1;

		while (idx > 1) {
			int parent = idx / 2;

			// 절댓값이 부모가 더 크거나 / 절댓값이 같을 때, 자식의 값이 더 작다면
			if ((abs(heap[parent]) > abs(heap[idx])) ||
				(abs(heap[parent]) == abs(heap[idx])) && (heap[parent] > heap[idx])) {

				std::swap(heap[parent], heap[idx]);
				idx = parent;
			}
			// 힙 특성상, 더 이상 올라갈 필요 X
			else break;
		}
	}

	int pop() {
		if (isEmpty()) return 0;

		int top = heap[1];
		// 힙의 마지막 인덱스 원소를 루트로 설정하고, 마지막 인덱스 원소는 제거
		heap[1] = heap.back();
		heap.pop_back();

		int idx = 1;
		while (1) {
			int left = idx * 2;
			int right = idx * 2 + 1;
			int smallest = idx;

			// 왼쪽 자식과 비교
			if (left < heap.size()) {
				if (abs(heap[smallest]) > abs(heap[left]) ||
					(abs(heap[smallest]) == abs(heap[left]) && heap[smallest] > heap[left])) {

					smallest = left;
				}
			}

			// 오른쪽 자식과 비교
			if (right < heap.size()) {
				if (abs(heap[smallest]) > abs(heap[right]) ||
					(abs(heap[smallest]) == abs(heap[right]) && heap[smallest] > heap[right])) {

					smallest = right;
				}
			}


			if (idx == smallest) break; // 힙 정렬 완료
			std::swap(heap[smallest], heap[idx]);
			idx = smallest;
		}

		return top;
	}

	bool isEmpty() const {
		return heap.size() == 1;
	}
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
/*    0
*     1
*   2   3
*  4 5 6 7
*/