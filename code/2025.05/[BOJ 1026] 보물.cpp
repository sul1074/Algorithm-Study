#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int s(const vector<int>& a, const vector<int>& b) {
	int sum = 0;

	for (int i = 0; i < a.size(); ++i) {
		sum += a[i] * b[i];
	}

	return sum;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> a(n);
	vector<int> b(n);

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}

	sort(a.begin(), a.end(), [](int a, int b) { return a > b; });
	sort(b.begin(), b.end());

	cout << s(a, b) << '\n';

	return 0;
}
