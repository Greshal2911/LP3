#include<iostream>
#include<vector>
#include<stack>
#include<cstdlib>
#include<ctime>
using namespace std;

void displayArr(vector<int>& arr) {
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Deterministic Partition
int deterministicPartition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i < j) {
        while(i <= high - 1 && arr[i] <= pivot) {
            i++;
        }

        while(j >= low + 1 && arr[j] > pivot) {
            j--;
        }

        if(i < j) {
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[low], arr[j]);
    return j;
}

// Randomized Partition
int randomizedPartition(vector<int>& arr, int low, int high) {
    int randomIdx = low + rand() % (high - low + 1);

    swap(arr[low], arr[randomIdx]);

    return deterministicPartition(arr, low, high);
}

// Non-Recursive Quick Sort
void quickSort(vector<int>& arr, int low, int high, bool israndomized) {

    stack<int> st;

    st.push(low);
    st.push(high);

    while(!st.empty()) {

        high = st.top();
        st.pop();

        low = st.top();
        st.pop();

        int p_index;

        if(israndomized) {
            p_index = randomizedPartition(arr, low, high);
        }
        else {
            p_index = deterministicPartition(arr, low, high);
        }

        // Left subarray
        if(p_index - 1 > low) {
            st.push(low);
            st.push(p_index - 1);
        }

        // Right subarray
        if(p_index + 1 < high) {
            st.push(p_index + 1);
            st.push(high);
        }
    }
}

int main() {

    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    while(true) {

        cout << "\n1. Insert elements" << endl;
        cout << "2. Quick Sort using deterministic partition" << endl;
        cout << "3. Quick Sort using randomized partition" << endl;
        cout << "4. Display array" << endl;
        cout << "5. Exit" << endl;

        int op;
        cout << "Enter option: ";
        cin >> op;

        if(op == 1) {
            for(int i = 0; i < n; i++) {
                cout << "Enter element " << i + 1 << ": ";
                cin >> arr[i];
            }
        }
        else if(op == 2) {
            if(n > 1)
                quickSort(arr, 0, n - 1, false);

            cout << "Array sorted using deterministic Quick Sort." << endl;
        }
        else if(op == 3) {
            srand(time(0));

            if(n > 1)
                quickSort(arr, 0, n - 1, true);

            cout << "Array sorted using randomized Quick Sort." << endl;
        }
        else if(op == 4) {
            displayArr(arr);
        }
        else if(op == 5) {
            break;
        }
        else {
            cout << "Invalid option!" << endl;
        }
    }

    return 0;
}