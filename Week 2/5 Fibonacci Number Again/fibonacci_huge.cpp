#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}
long long get_pisano_period(long long m) {
    long long a = 0, b = 1, c = a + b;
    for (int i = 0; i < m * m; i++) {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1) 
		return i + 1;
    }
}
long long get_fibonacci_huge_fast(long long n, long long m) {

	long long iterations = n % get_pisano_period(m);
	if(n ==0 || n ==1)
		return n;
	long long a=0, b=1;
	long long ans = iterations;
	
	for(long long i= 1; i < iterations ; i++){
		ans = (a + b)%m;
		a = b;
		b = ans;
	}
    return ans%m;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    //std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
    
}
