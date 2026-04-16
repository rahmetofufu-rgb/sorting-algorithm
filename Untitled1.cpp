#include <iostream>
#include <cstdlib>
#include <chrono>

using namespace std;
using namespace std::chrono;

const int MAX = 100000;

struct Product {
    int id;
    int price;
};

Product a[MAX], b[MAX], c[MAX], temp[MAX];

// -------------------- GENERATE DATA --------------------
void generate(Product arr[], int n) {
    for(int i = 0; i < n; i++) {
        arr[i].id = i + 1;
        arr[i].price = rand() % 100000;
    }
}

// -------------------- MERGE SORT --------------------
void merge(Product arr[], int l, int m, int r) {
    int i = l, j = m + 1, k = l;

    while(i <= m && j <= r) {
        if(arr[i].price <= arr[j].price)
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while(i <= m) temp[k++] = arr[i++];
    while(j <= r) temp[k++] = arr[j++];

    for(int x = l; x <= r; x++)
        arr[x] = temp[x];
}

void mergeSort(Product arr[], int l, int r) {
    if(l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// -------------------- QUICK SORT --------------------
int partition(Product arr[], int low, int high) {
    int pivot = arr[high].price;
    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(arr[j].price < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(Product arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// -------------------- HEAP SORT --------------------
void heapify(Product arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if(l < n && arr[l].price > arr[largest].price)
        largest = l;

    if(r < n && arr[r].price > arr[largest].price)
        largest = r;

    if(largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(Product arr[], int n) {
    for(int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for(int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// -------------------- MAIN (EXPERIMENT) --------------------
int main() {
    srand(time(0));

    int sizes[] = {100, 1000, 10000, 100000};

    cout << "Size\tMergeSort(µs)\tQuickSort(µs)\tHeapSort(µs)\n";
    cout << "--------------------------------------------------------\n";

    for(int i = 0; i < 4; i++) {

        int n = sizes[i];

        generate(a, n);

        // copy same data
        for(int j = 0; j < n; j++) {
            b[j] = a[j];
            c[j] = a[j];
        }

        // ---------------- MERGE SORT ----------------
        auto start = high_resolution_clock::now();
        mergeSort(a, 0, n - 1);
        auto end = high_resolution_clock::now();

        long long mergeTime =
            duration_cast<microseconds>(end - start).count();

        // ---------------- QUICK SORT ----------------
        start = high_resolution_clock::now();
        quickSort(b, 0, n - 1);
        end = high_resolution_clock::now();

        long long quickTime =
            duration_cast<microseconds>(end - start).count();

        // ---------------- HEAP SORT ----------------
        start = high_resolution_clock::now();
        heapSort(c, n);
        end = high_resolution_clock::now();

        long long heapTime =
            duration_cast<microseconds>(end - start).count();

        cout << n << "\t"
             << mergeTime << "\t\t"
             << quickTime << "\t\t"
             << heapTime << endl;
    }

    return 0;
}