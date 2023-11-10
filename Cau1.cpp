#include <iostream>

using namespace std;


int sum_of_divisors(int n) {
    int total = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            total += i;
        }
    }
    return total;
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;
        int result = sum_of_divisors(n);
        cout << result << endl;
    }

    return 0;
}
