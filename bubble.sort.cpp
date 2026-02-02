#include <iostream>

using namespace std;

class Sort {
private:
  int *data;
  int size;

public:
  Sort(int *a,int size) {
    this->data = a;
    this->size = size;
  }

public:
  void bubbleSort() {
    for (int i = 0; i < size - 1; i++) {
      for (int j = 0; j < size - i - 1; j++) {
        if (data[j] > data[j + 1]) {
          int temp = data[j];
          data[j] = data[j + 1];
          data[j + 1] = temp;
        }
      }
    }
  }
};


int main() {
  int a[5] = {29,44,18,26,45};

  Sort s(a,5);
  s.bubbleSort();
	cout<<"The array in ascending order using bubble sort is given as:"<<endl;
  for (int i = 0; i < 5; i++) {
    cout << a[i] <<endl;
  }
  cout<<"\nSwornima Dangol\n";
  return 0;
}
