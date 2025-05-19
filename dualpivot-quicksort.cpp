#include <iostream>
#include <vector>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void dualPivotQuicksort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Pastikan pivot1 lebih kecil dari pivot2
        if (arr[low] > arr[high])
            swap(arr[low], arr[high]);

        int pivot1 = arr[low];
        int pivot2 = arr[high];

        int i = low + 1;
        int lt = low + 1;
        int gt = high - 1;

        while (i <= gt) {
            if (arr[i] < pivot1) {
                swap(arr[i], arr[lt]);
                lt++;
            }
            else if (arr[i] > pivot2) {
                swap(arr[i], arr[gt]);
                gt--;
                i--; // setelah swap, cek lagi elemen yg ketukar
            }
            i++;
        }

        lt--;
        gt++;

        swap(arr[low], arr[lt]);
        swap(arr[high], arr[gt]);

        // Rekursif untuk 3 bagian
        dualPivotQuicksort(arr, low, lt - 1);
        dualPivotQuicksort(arr, lt + 1, gt - 1);
        dualPivotQuicksort(arr, gt + 1, high);
    }
}

int main() {
    vector<int> arr = {5, 3, 7, 3, 10, 4, 9, 8};
    int n = arr.size();
    
    cout << "data sebelum diurutkan: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    dualPivotQuicksort(arr, 0, n - 1);

    cout << "Hasil setelah diurutkan: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
