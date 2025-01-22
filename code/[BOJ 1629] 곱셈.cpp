#include <iostream>
#include <vector>
#include <cmath>

using std::cin;
using std::cout;
using std::vector;

long long ModExp(long long, long long, long long);

int main(void) {
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);

	/*
	* 3**1 * 3**12
	*        3**6 * 3**6
	*
	* 3**1 mod 5 = 3
	* 3**2 mod 5 = 4
	* 3**3 mod 5 = 2
	* 3**4 mod 5 = 1
	* --------------
	* 3**5 mod 5 = 3
	*
	* a**b mod c = ((a**b/2) mod c) * ((a**b/2) mod c) mod c
	*/

	long long a, b, c;
	cin >> a >> b >> c;

	cout << ModExp(a, b, c);

	return 0;
}

long long ModExp(long long a, long long b, long long c) {
	if (b == 0) return 1;

	long long half = ModExp(a, b / 2, c); 

	half = (half * half) % c;  

	if (b % 2 == 1)  
		half = (half * a) % c;

	return half;
}
