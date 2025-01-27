#include <iostream>
#include <vector>
#include <map>

using std::cin;
using std::cout;
using std::vector;

class Heap {
	vector<int> heap;

public:
	// 힙의 인덱스 시작을 1로 하기 위함. 0번째 index는 사용 X
	Heap()
	{
		heap.push_back(0);
	}

	// 순수 가상 함수
	virtual bool compare(int parent, int child) const = 0;

	void push(int value) {
		heap.push_back(value);
		int idx = heap.size() - 1;
		int parent = idx / 2;

		while (parent > 0 && compare(heap[parent], heap[idx])) {
			std::swap(heap[parent], heap[idx]);
			idx = parent;
			parent = idx / 2;
		}
	}

	void pop() {
		if (empty()) return;

		// 마지막 노드를 루트로 옮기고, 마지막 노드는 제거
		int top = 1;
		heap[1] = heap.back();
		heap.pop_back();

		while (1) {
			int left = top * 2;
			int right = top * 2 + 1;
			int largest = top;

			if (left < heap.size() && compare(heap[largest], heap[left])) {
				largest = left;
			}

			if (right < heap.size() && compare(heap[largest], heap[right])) {
				largest = right;
			}

			if (top == largest) break;

			std::swap(heap[largest], heap[top]);
			top = largest;
		}
	}

	bool empty() const { return heap.size() <= 1; }

	int top() const { 
		if (empty()) return -1;

		return heap[1]; 
	}

	void printHeap() const {
		for (auto n : heap) {
			cout << n << ' ';
		}
		cout << '\n';
	}

	~Heap() {}
};

class MaxHeap : public Heap {
	bool compare(int parent, int child) const override {
		return parent < child;
	}
public:
	MaxHeap() {}

	~MaxHeap() {}
};

class MinHeap : public Heap {
	bool compare(int parent, int child) const override {
		return parent > child;
	}

public:
	MinHeap() {}

	~MinHeap() {}
};

class DualPriorityQueue {
	std::map<int, int> pushedList;
	MaxHeap maxHeap;
	MinHeap minHeap;

public:
	DualPriorityQueue() {}

	void push(int value) {
		maxHeap.push(value);
		minHeap.push(value);
		pushedList[value]++;
	}

	void popMax() {
		if (maxHeap.empty()) return;

		pushedList[maxHeap.top()]--;
		maxHeap.pop();
	}

	void popMin() {
		if (minHeap.empty()) return;

		pushedList[minHeap.top()]--;
		minHeap.pop();
	}

	void synchronizeQueues() {
		while (!maxHeap.empty() && pushedList[maxHeap.top()] == 0) {
			maxHeap.pop();
		}

		while (!minHeap.empty() && pushedList[minHeap.top()] == 0) {
			minHeap.pop();
		}
	}

	void printAns() const {
		if (maxHeap.empty() || minHeap.empty()) {
			cout << "EMPTY" << '\n';
			return;
		}

		cout << maxHeap.top() << ' ' << minHeap.top() << '\n';
	}

	void debug() const {
		cout << "\n\n";
		for (std::pair<int, int> n : pushedList) {
			cout << n.first << ' ' << n.second << '\n';
		}
		cout << "Max : \n";
		maxHeap.printHeap();

		cout << "\nMin: \n";
		minHeap.printHeap();

		cout << '\n';
	}

	~DualPriorityQueue() {}
};

int main(void) {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;


	for (int time = 0; time < t; ++time) {
		DualPriorityQueue queue;
		int k;
		cin >> k;

		for (int i = 0; i < k; ++i) {
			char op;
			int n;
			cin >> op >> n;

			switch (op) {
				// 큐가 비어있으면 무시
			case 'D':
				if (n == 1) queue.popMax();
				else queue.popMin();
				queue.synchronizeQueues();
				break;
				// n 삽입
			case 'I':
				queue.push(n);
				break;
			default:
				break;
			}
		}
		// queue.debug();
		// cout << "\n\n";

		queue.printAns();
	}

	return 0;
}
