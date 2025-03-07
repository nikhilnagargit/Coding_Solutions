#include <vector>
using namespace std;

class Solution {
public:
    static vector<bool> prime;
    
    // Static method to initialize the sieve
    static void computePrimes() {
        prime[0] = false;
        prime[1] = false;

        for (int p = 2; p * p <= 1000000; p++) {
            if (prime[p]) {
                for (int i = p * p; i <= 1000000; i += p)
                    prime[i] = false;
            }
        }
    }

    vector<int> closestPrimes(int left, int right) {
        static bool initialized = (computePrimes(), true); // Ensure primes are computed only once
        
        int num1 = -1, num2 = -1;
        
        for (int i = left; i <= right; i++) {
            if (prime[i]) {
                num1 = i;
                break;
            }
        }
        if (num1 == -1) return {-1, -1};  // No prime found in range

        for (int i = num1 + 1; i <= right; i++) {
            if (prime[i]) {
                num2 = i;
                break;
            }
        }
        if (num2 == -1) return {-1, -1};  // Only one prime found

        int N1 = num1, N2 = num2;
        int prev = num2, curr = num2 + 1;

        while (curr <= right) {
            if (prime[curr]) {
                if (curr - prev < N2 - N1) {
                    N1 = prev;
                    N2 = curr;
                }
                prev = curr;
            }
            curr++;
        }

        return {N1, N2};
    }
};

// Initialize the static vector
vector<bool> Solution::prime(1000001, true);

