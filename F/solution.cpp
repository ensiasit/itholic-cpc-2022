// Author: El Mehdi ASSALI
// Original: https://codeforces.com/contest/1307/problem/B

#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
  int n, x;
  scanf("%d %d", &n, &x);

  int answer_is_one = 0, max_a = 0;

  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);

    if (a == x) {
      answer_is_one = 1;
    }

    max_a = max(max_a, a);
  }

  if (answer_is_one) {
    printf("1\n");
  } else {
    printf("%d\n", max(2, (int) ceil((double) x / max_a)));
  }

  return 0;
}