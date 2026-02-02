#include <iostream>
using namespace std;

class Sort {
private:
    int* data;
    int size;

    // Partition function
    int partition(int low, int high) {
        int pivot = data[high];   // choose last element as pivot
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (data[j] < pivot) {
                i++;
                int temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }

        // place pivot in correct position
        int temp = data[i + 1];
        data[i + 1] = data[high];
        data[high] = temp;

        return i + 1;
    }

    // Recursive quicksort
    void quickSort(int low, int high) {
        if (low < high) {
            int pi = partition(low, high);
            quickSort(low, pi - 1);
            quickSort(pi + 1, high);
        }
    }

public:
    Sort(int* data, int size) {
        this->data = data;
        this->size = size;
    }

    void quickSort() {
        quickSort(0, size - 1);
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << data[i] << endl;
        }
    }
};

int main() {
    int a[5] = {34,22,5,4,2};
	cout<<"The array arranged in ascending order is given as:"<<endl;
    Sort s(a, 5);
    s.quickSort();
    s.print();
	cout<<"\nPratik Maharjan"<<endl;
    return 0;
}
