#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;
using vb = vector<bool>;

ll n;
vb sieve;
vl primes;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n;

  sieve = vb(1000, true);
  sieve[0] = false;
  sieve[1] = false;

  for (auto i = 2; i < 1000; ++i) {
    if (!sieve[i]) continue;

    primes.push_back(i);

    for (auto j = i + i; j < 1000; j += i) {
      sieve[j] = false;
    }
  }

  cout << n << '\n';
  cout << 1 << ' ';
  for (auto i = 0; i < n - 1; ++i) {
    cout << primes[i] << ' ';
  }

  return 0;
}