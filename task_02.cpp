#include <bits/stdc++.h>
using namespace std;

int findPivot(vector<int>& arr) {
    int l = 0, r = (int)arr.size() - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] > arr[r]) l = mid + 1;
        else r = mid;
    }
    return l;
}

int floorSearch(vector<int>& arr, int l, int r, int budget) {
    int ans = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] <= budget) {
            ans = arr[mid];
            l = mid + 1;
        } else r = mid - 1;
    }
    return ans;
}

void burgerFloor(vector<int>& rotatedMenu, int budget) {
    int n = rotatedMenu.size();
    int pivot = findPivot(rotatedMenu);

    int floor1 = floorSearch(rotatedMenu, 0, pivot - 1, budget);
    int floor2 = floorSearch(rotatedMenu, pivot, n - 1, budget);
    int res = max(floor1, floor2);
    int maxPrice = *max_element(rotatedMenu.begin(), rotatedMenu.end());

    if (budget > maxPrice) {
        cout << "Customer is rich! Return " << maxPrice << " (the max price)." << endl;
    } else if (res == -1) {
        cout << "Customer is broke. Return -1." << endl;
    } else if (budget == res) {
        if (res == maxPrice) {
            cout << "Customer has $" << budget << ". Return " << res << "." << endl;
        } else {
            cout << "Customer has $" << budget << ". Return " << res
                 << " (the burger costing $" << res << ")." << endl;
        }
    } 
}

int main() {
    vector<int> menu = {5, 6, 7, 1, 2, 3, 4};

    burgerFloor(menu, 4);
    burgerFloor(menu, 7);
    burgerFloor(menu, 10);
    burgerFloor(menu, 0);

    return 0;
}

