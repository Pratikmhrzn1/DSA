/*Menu driven program to perform following tasks using the concept of stack*/
#include<iostream>
using namespace std;
class Stack{
	int top;
	int *array;
	int capacity;
	public:
		Stack(int cap){
			capacity=cap;
			array= new int[cap];
			top=-1;
		}
		~Stack(){
			delete []array;
		}
		void makeEmpty(){
				top=-1;
				cout<<"\nThe stack has been emptied!\n";	
			
		}
		bool overflow(){
			return top == capacity-1;
		}
		bool underflow(){
			return top==-1;
		}
		void push(int x){
			if(overflow()){
				cout<<"The stack is full!\n";
			}
			else{
				top++;
				array[top]=x;
				cout<<"\nValue inserted in stack successfully!\n";
			}
		}
		void pop(){
			if(underflow()){
				cout<<"The stack is empty!Please enter data before deleting them.";
			}
			else{
				cout<<"The number about to be popped is "<<array[top]<<endl;
				top--;
				cout<<"Popped successfully!\n";
			}
		}
		void traverse(){
			if(underflow()){
				cout<<"Stack is empty!";
			}
			else{
				cout<<"The elements in the stack are given below:\n";
				for(int i=top;i>=0;i--){
					cout<<array[i]<<" ";
				}
				cout<<endl;
				
			}
		}
		int peek(){
			if(underflow()){
				cout<<"Stack is empty!\n";
				return -1;
			}
			return array[top];
		}
};
int main(){
	Stack s(4);
	int choice;
	do{
		cout<<"\nMenu:\n";
		cout<<"1.Press 1 to push data on the top of the stack.\n2.Press 2 to make the stack empty.\n3.Press 3 to pop data from the top of the stack.\n4.Press 4 to traverse the stack\n5.Press 5 to peek.\n6.Press 6 to Exit\n";
		cout<<"\nEnter your choice:";
		cin>>choice;
		switch(choice){
			case 1:
				int x;
				cout<<"Enter a value to insert:";
				cin>>x;
				s.push(x);
				break;
			case 2:
				s.makeEmpty();
				break;
			case 3:
				s.pop();
				break;
			case 4:
				s.traverse();
				break;
			case 5:
				cout<<"The top element of the stack is "<<s.peek();
				break;
			case 6:
				cout<<"Exiting.....!"<<endl;
				break;
				
			default:
				cout<<"Invalid choice!\n";
				break;
		}
	}while(choice!=6);
	return 0;
	
}
