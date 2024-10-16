#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

using namespace std;

void Initialize(double* arr, const int size, int i) {
    if (i < size) {
        arr[i] = rand() % 21 - 10;  
        Initialize(arr, size, i + 1);
    }
}

void PrintArray(const double* arr, const int n, int i, int validSize = -1) {
    if (i == 0) cout << "{ ";
    if (validSize != -1 && i >= validSize) {
        cout << "}" << endl;
        return;
    }
    cout << fixed << setprecision(0) << arr[i];
    if (i < n - 1 && (validSize == -1 || i < validSize - 1)) {
        cout << " ";
        PrintArray(arr, n, i + 1, validSize);
    }
    else {
        cout << " }" << endl;
    }
}

double FindMaxElement(const double* arr, const int n, int i, double max) {
    if (i < n) {
        if (arr[i] > max)
            max = arr[i];
        return FindMaxElement(arr, n, i + 1, max);
    }
    return max;
}

int FindLastPositiveIndex(const double* arr, const int n, int i, int lastIndex) {
    if (i < n) {
        if (arr[i] > 0)
            lastIndex = i;
        return FindLastPositiveIndex(arr, n, i + 1, lastIndex);
    }
    return lastIndex;
}

double SumBeforeLastPositive(const double* arr, const int n) {
    int lastPositiveIndex = FindLastPositiveIndex(arr, n, 0, -1);
    if (lastPositiveIndex == -1) return 0;

    double sum = 0;
    for (int i = 0; i < lastPositiveIndex; i++) {
        sum += arr[i];
    }
    return sum;
}

int CompressArray(double* arr, const int n, int i, int j, double a, double b) {
    if (i < n) {
        if (abs(arr[i]) < a || abs(arr[i]) > b) {
            arr[j] = arr[i];
            return CompressArray(arr, n, i + 1, j + 1, a, b);
        }
        else {
            return CompressArray(arr, n, i + 1, j, a, b);
        }
    }
    return j;  // Повертаємо кількість елементів у стиснутому масиві
}

int main() {
    srand(time(0));
    int n;
    double a, b;

    cout << "Enter the size of the array n = "; cin >> n;
    cout << "Enter the lower limit of the interval a = "; cin >> a;
    cout << "Enter the upper limit of the interval b = "; cin >> b;

    double* arr = new double[n];

    Initialize(arr, n, 0);
    cout << "Initial array:" << endl;
    PrintArray(arr, n, 0);

    cout << "The maximum element of the array: " << FindMaxElement(arr, n, 0, numeric_limits<double>::lowest()) << endl;

    cout << "The sum of the elements of the array up to the last positive: " << SumBeforeLastPositive(arr, n) << endl;

    int compressedSize = CompressArray(arr, n, 0, 0, a, b);
    cout << "Compressed array:" << endl;
    PrintArray(arr, n, 0, compressedSize);

    delete[] arr;
    return 0;
}