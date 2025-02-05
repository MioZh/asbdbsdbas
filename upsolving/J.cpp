#include <iostream>
#include <algorithm>

using namespace std;

bool binS (int target, int a[], int n) {
    int l = 0, r = n - 1;
    int mid;
    while (l <= r) {
        mid = l + (r - l)/2;
        if (a[mid] < target) {
            l = mid + 1;
        }
        else if (a[mid] > target) {
            r = mid - 1;
        }
        else {
            return true;
        }
    }
    return false;
}

int main() {
    int target; cin >> target;
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    for (int i = 0; i < n; i++) {
        int diff = target - arr[i];
        if (binS(diff, arr, n)) {
            cout << arr[i] << " " << diff;
            break;
        }
    }
}