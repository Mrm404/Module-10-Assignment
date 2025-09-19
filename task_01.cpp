#include <iostream>
#include <vector>
using namespace std;

int findTreasure(vector<int>& rotatedArray, int treasure) {
    int left = 0, right = rotatedArray.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (rotatedArray[mid] == treasure) 
            return mid;
            
        if (rotatedArray[left] <= rotatedArray[mid]) {
            if (treasure >= rotatedArray[left] && treasure < rotatedArray[mid]) {
                right = mid - 1;  
            } else {
                left = mid + 1;   
            }
        }
        else {
            if (treasure > rotatedArray[mid] && treasure <= rotatedArray[right]) {
                left = mid + 1;   
            } else {
                right = mid - 1;  
            }
        }
    }
    return -1; 
}

int main() {
    int n, treasure;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> treasure;

    int index = findTreasure(arr, treasure);

    if (index != -1)
        cout << index << endl;
    else
        cout << "Treasure not found" << endl;

    return 0;
}
