#include <iostream>
#include <algorithm>

using namespace std;

struct Heap {
    long long *a; //адрес к массиву с значениями в хипе
    long long capacity; //максимальный размер хипа
    long long size; //размер хипа на данный момент

    long long parent (long long i) {
        return (i - 1)/2;
    }

    long long left (long long i) {
        return i*2 + 1;
    }

    long long right (long long i) {
        return i*2 + 2;
    }

    void add (long long x) {
        a[size] = x;
        size++;
        heapUp(size - 1);
    }

    int heapUp (long long i) {
        if (i > 0) {
            long long p = parent(i);
            if (a[i] > a[p]) {
                swap(a[i], a[p]);
                return heapUp(p);
            }
            else
                return i + 1;
        }
        else
            return 1;
    }

    void heapDown (long long i) {
        long long l = left(i);
        long long r = right(i);
        long long max = i;
        if (l < this->size && a[max] < a[l])
            max = l;
        if (r < this->size && a[max] < a[r])
            max = r;
        if (i != max) {
            swap(a[i], a[max]);
            heapDown(max);
        }
    }

    void cut_max () {
        a[0] = a[size - 1];
        size = max((long long)0, size - 1);
        heapDown(0);
    }

    void print(){
        for(long long i = 0; i < size; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }

    int Inc (int i, int b) {
        a[i-1] += b;
        int new_index = heapUp(i-1);
        return new_index;
    }

    Heap (long long x) {
        this->a = new long long[x];
        this->capacity = x;
        this->size = 0;
    }
};

int main() {
    int n; cin >> n;
    Heap H(n);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        H.add(a);
    }
    int q; cin >> q;
    while(q--) {
        int i; cin >> i;
        int b; cin >> b;
        cout << H.Inc(i, b) << "\n";
    }
    H.print();
}