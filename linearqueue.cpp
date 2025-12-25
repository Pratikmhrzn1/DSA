#include<iostream>
using namespace std;
class Queue{
	int front,rear;
	int *array;
	int capacity;
	public:
		Queue(int cap){
			capacity=cap;
			front=0;
			rear=-1;
			array = new int[capacity];
		}
		~Queue(){
			delete []array;
		}
		void makeEmpty(){
			if(front>rear){
				cout<<"\nThe queue is already empty!\n";
			}
			else{
				front=0;
				rear=-1;
				cout<<"\nThe queue has been emptied!\n";
			}
		}
		void enqueue(int value){
			if(rear==capacity-1){
				cout<<"\nThe queue is full!\n";
			}
			else{
				array[++rear]=value;
				cout<<"\nThe value has been inserted successfully in the queue!"<<endl;
			}
			}
			void dequeue(){
				if(front>rear){
					cout<<"\nThe queue is empty!\n";
				}
				else{
					cout<<"The element removed from the queue is "<<array[front]<<endl;
					front++;
				}
			}
			void display(){
				if(front>rear){
					cout<<"\nThe queue is empty!\n";
				}
				else{
					cout<<"The elements in the queue are:\n";
					for(int i=front;i<=rear;i++){
						cout<<array[i]<<" ";
					}
					cout<<endl;
				}
			}
		
};
int main(){
	Queue q(4);
	int choice;
	do{
		cout<<"\nPratik Maharjan\n";
		cout<<"\nMenu:"<<endl;
		cout<<"\n1.Enqueue\n2.Dequeue\n3.MakeEmpty\n4.Display\n5.Exit"<<endl;
		cout<<"\nEnter your choice:";
		cin>>choice;
		switch(choice){
			case 1:
				int val;
				cout<<"\nEnter a value in the queue:";
				cin>>val;
				q.enqueue(val);
				break;
			case 2:
				q.dequeue();
				break;
			case 3:
				q.makeEmpty();
				break;
			case 4:
				q.display();
				break;
			case 5:
				cout<<"Exiting....!"<<endl;
				break;
			default:
				cout<<"Invalid choice!"<<endl;
		}
	}while(choice!=5);
	return 0;
}
