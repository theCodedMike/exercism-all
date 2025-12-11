#include "sieve.h"

namespace sieve {

    std::vector<int> primes(const int n) {
        std::vector<bool> flags(n + 1, true);
        std::vector<int> result;
        result.reserve(n / 2);

        for (int i = 2; i <= n; ++i) {
            if (flags[i]) {
                result.push_back(i);
                for (int j = i * i; j <= n; j += i)
                    flags[j] = false;
            }
        }

        return result;
    }

}  // namespace sieve
