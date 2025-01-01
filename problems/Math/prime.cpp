#include "helper.hpp"
#include <cstdlib>
#include <print>
#include <vector>

bool isPrime(int n) {
    int i = 2;
    while (i * i < n) {
        if (n % i == 0)
            return false;
        i++;
    }
    return true;
}

// sieve of eratosthenes to find prime from [1-n]
// https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html
void sieve(int n) {
    // n * log(n)
    std::vector<bool> primes(n, true);
    // only check till the sqrt of n
    for (int i = 2; i * i < n; i++) {
        if (primes[i]) {
            for (int j = i * 2; j < n; j += i) {
                primes[j] = false;
            }
        }
    }

    for (int i = 2; i < n; i++) {
        std::cout << i << " " << std::boolalpha << primes[i] << std::endl;
    }
}

double BS_sqrt(double s, double e, double n, int p) {
    if (s >= e) {
        s--;
        double incr = 0.1;
        for (int i = 0; i < p; i++) {
            while (s * s < n) {
                s += 0.1;
            }
            s -= incr;
            incr /= 10;
        }
        return s;
    }
    double mid = (s + e) / 2;
    if (mid * mid == n) {
        return mid;
    } else if (mid * mid > n) {
        return BS_sqrt(s, mid - 1, n, p);
    } else {
        return BS_sqrt(mid + 1, e, n, p);
    }
}

// Newton Raphson Sqrt method: minimize the error from assumed sqrt
double NewtonSqrt(double num, double precision) {
    double assumedVal = num / 2;
    while (true) {
        double x = (assumedVal + num / assumedVal) * 0.5;
        double error =  std::abs(assumedVal - x);
        if (error < precision)
            break;
        assumedVal = x;
    }
    return assumedVal;
}

// in ascending order
void printFactors(int n) {

}

int main()
{
    // int n = 40;
    // int s = 1;
    // int e = n / 2;
    // std::cout << BS_sqrt(s, e, n, 3) << std::endl;

    std::cout << NewtonSqrt(32, 0.5) << std::endl;
}
