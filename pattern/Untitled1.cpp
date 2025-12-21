#include<iostream>
using namespace std;
class CircularQueue{
	int front,rear;
	int *array;
	int capacity;
	public:
		CircularQueue(int cap){
			capacity= cap;
			rear= capacity-1;
			front=capacity-1;
			array = new int[capacity];
		}
		void enqueue(int x){
			if(front==(rear+1)%capacity){
				cout<<"The queue is full!\n";
			}
			else{
				rear=(rear+1)%capacity;
				array[rear]=x;
				cout<<"The number has been added successfully!"<<endl;
			}
		}
		void dequeue(){
    	if (rear == front) {
        	cout << "The queue is empty!\n";
    	}
    	else {
        	front = (front + 1) % capacity;   // move front correctly
        	int temp = array[front];           // removed element (optional)
        	cout << "The number has been removed from the queue!" << endl;
    	}
	
	}
		void traverse(){
    		if (rear == front) {
    	    	cout << "The queue is empty!" << endl;
    		} 
    		else {
        	cout << "The elements of the queue are:" << endl;
        	for (int i = front;i!=rear ; i = (i + 1) % capacity) {
            	cout << array[i] << " ";
            	if (i == rear)
                break;
        	}
        	cout << endl;
    }
}

		
};
int main(){
	CircularQueue cq(4);
	int choice;
	do{
		cout << "\n--- Circular Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Traverse\n";
        cout << "4. Exit\n";
		cout<<"Enter your choice:";
		cin>>choice;
		switch(choice){
			case 1:
				int x;
				cout<<"Enter a data in the queue:";
				cin>>x;
				cq.enqueue(x);
				break;
			case 2:
				cq.dequeue();
				break;
			case 3:
				cq.traverse();
				break;
			case 4:
				cout<<"Exiting...!";
				break;
			default:
				cout<<"Invalid choice!";	
		}
	}while(choice!=4);
	return 0;
}
