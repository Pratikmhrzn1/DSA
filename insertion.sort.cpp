#include <iostream>

using namespace std;

class Sort {
private:
  int *data;
  int size;

public:
  Sort(int *data,int size) {
    this->data = data;
    this->size = size;
  }

  void insertionSort() {
    for (int i = 1; i < this->size; i++) {
      int key = this->data[i];
      int j = i - 1;
      while (j >= 0 && this->data[j] > key) {
        this->data[j + 1] = data[j];
        j --;
      }
      data[j + 1] = key;
    }
  }

  void print() {
    for (int i = 0; i < size; i++) {
      cout << data[i] << endl;
    }
  }
};

int main() {
  int a[5] = { 52,34,36,23,18};
  Sort s(a,5);
  cout<<"The array in ascending order using insertion sort is given as:"<<endl;
  s.insertionSort();
  s.print();
  cout<<"\nSwornima Dangol\n";
  return 0;
}
