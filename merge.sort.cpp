#include <iostream>
using namespace std;

class Sort {
private:
    int* data;
    int size;

    // Merge two sorted halves
    void merge(int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        int* L = new int[n1];
        int* R = new int[n2];

        for (int i = 0; i < n1; i++)
            L[i] = data[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = data[mid + 1 + j];

        int i = 0, j = 0, k = left;

        while (i < n1 && j < n2) {
            if (L[i] <= R[j])
                data[k++] = L[i++];
            else
                data[k++] = R[j++];
        }

        while (i < n1)
            data[k++] = L[i++];

        while (j < n2)
            data[k++] = R[j++];

        delete[] L;
        delete[] R;
    }

    // Recursive merge sort
    void mergeSort(int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;

            mergeSort(left, mid);
            mergeSort(mid + 1, right);
            merge(left, mid, right);
        }
    }

public:
    Sort(int* data, int size) {
        this->data = data;
        this->size = size;
    }

    void mergeSort() {
        mergeSort(0, size - 1);
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << data[i] << endl;
        }
    }
};

int main() {
    int a[5] = {9,4,5,7,2};
	cout<<"The numbers in ascending order using merge sort is given as is given as:"<<endl;
    Sort s(a, 5);
    s.mergeSort();
    s.print();
	cout<<"\nPratik Maharjan\n";
    return 0;
}
