// Problem 3: Counting Sort

#include<bits/stdc++.h>
using namespace std;

void countingSort(vector<int>& arr, int maxVal) {
    vector<int> count(maxVal + 1, 0);
    for (int num : arr) count[num]++;
    int idx = 0;
    for (int i = 0; i <= maxVal; ++i) {
        while (count[i]--) arr[idx++] = i;
    }
}

int main() {
    // Example usage
    products[1] = {1, 10, 5, 10};
    products[2] = {2, 5, 8, 15};

    Customer c1 = {1, 100, {{1, 3, 30}, {2, 2, 50}}};
    Customer c2 = {2, 70, {{1, 2, 20}, {2, 1, 25}}};

    process_customer(c1);
    process_customer(c2);
    print_summary();

    vector<int> echo = {3, 1, 5, 2, 6, 4, 9};
    cout << "\nLongest echo path: " << longestEchoPath(echo) << endl;

    vector<int> arr = {5, 3, 1, 4, 2};
    countingSort(arr, 5);
    cout << "Sorted: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
