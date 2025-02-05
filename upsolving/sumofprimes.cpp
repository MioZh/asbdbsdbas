#include <iostream>
#include <vector>

using namespace std;

bool primes[100001];
vector <int> primelist;

void Sieve (int n) {
    for (int i = 2; i < n; i++) {
        primes[i] = true;
    }
    primes[0] = primes[1] = false;

    for (int p = 2; p * p <= n; p++) {
        if (primes[p] == true) {
            for (int i = p * p; i <= n; i += p) {
                primes[i] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (primes[i])
            primelist.push_back(i);
    }
}

int binSearch(vector <int> vec, int target) {
    int l = 0, r = vec.size() - 1;
    int mid;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (target == vec[mid])
            return mid;
        if (target > vec[mid]) {
            l = mid + 1;
        }
        if (target < vec[mid]) {
            r = mid - 1;
        }
    }
    return -1;
}

void find (int n) {
    for (int i = 0; i < primelist.size(); i++) {
        int target = n - primelist[i];
        int res = binSearch(primelist, target);
        if (res != -1) {
            cout << primelist[i] << " " << target;
            return;
        }
    }
}

int main() {
    int n; cin >> n;
    Sieve(n);
    find(n);
}