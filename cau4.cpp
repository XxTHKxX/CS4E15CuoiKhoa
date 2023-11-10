#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

bool isSuperPrime(int n) {
    if (!isPrime(n)) return false;
    int temp = n;
    while (temp > 0) {
        if (!isPrime(temp)) return false;
        temp /= 10;
    }
    return true;
}

void superPrimeNumber(int n) {
    queue<int> q;
    for (int i = 2; i <= n; ++i) {
        if (isSuperPrime(i)) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}

int main() {
    int n;
    cout << "Nhap So N: ";
    cin >> n;
    superPrimeNumber(n);

    return 0;
}