/*Write a menu driven program to:
1.Insert the data from the array.
2.Display data from the array.
3.Delete the data from the array.
4.Find the largest and smallest data from the array.
5.Arrange the array in ascending order or descending order.
6.Exit*/
#include<iostream>
#define max 5
using namespace std;
int main(){
	int arr[max],n=0;
	int choice;
	do{
		cout<<"\nMenu:\n1.Insert the data from the array.\n2.Display data from the array.\n3.Delete the data from the array.\n4.Find the largest and smallest data from the array.\n5.Arrange the array in ascending order or descending order.\n6.Exit";
		cout<<"\n\nEnter your choice:";
		cin>>choice;
		cout<<endl;
		switch(choice){
			case 1:
				if(n==max){
					cout<<"The array is full!";
				}
				else{
					int value;
					cout<<"Enter a data to insert in the array:";
					cin>>value;
					arr[n]=value;
					n++;
					cout<<"Value inserted successfully!"<<endl;
				}
				break;	
			case 2:
				if(n==0){
					cout<<"The array is empty!\n";
				}
				else{
					if(n==1){
						cout<<"The element in the array is:"<<arr[n];
					}
					else{
						cout<<"The elements of the array are:";
						for(int i=0;i<n;i++){
							cout<<arr[i]<<" ";
						}
						cout<<endl;
					}
					
				}
				break;
			case 3:
				if(n==0){
					cout<<"The array is empty!";
				}
				else{
					int position;
					cout<<"Enter the position of the element to delete:(0 to "<<n-1<<"):";
					cin>>position;
					if(position<0 || position>=n){
						cout<<"\nInvalid position!\n";
					}
					else{
						for(int i=position;i<n-1;i++){
							arr[i]=arr[i+1];
						}
							n--;
							cout<<"The element deleted successfully!"<<endl;
					}
				}
				break;
			case 4:
				if(n==0){
					cout<<"The array is empty!\n";
				}
				else{
					int largest=arr[0],smallest=arr[0];
					for(int i=0;i<n;i++){
						if(largest<arr[i]){
							largest=arr[i];
						}
						if(smallest>arr[i]){
							smallest=arr[i];
						}
					}
				cout<<"The largest number is:"<<largest<<endl<<"The smallest number is:"<<smallest<<endl;	
				}
				break;
			case 5:
				if(n==0){
					cout<<"\nPlease enter data in the array to arrange it in an order!"<<endl;
				}
				else{
					int order;
					cout<<"\nEnter 1 to arrange in ascending order and 2 to arrange in descending order:";
					cin>>order;
					int temp;
					switch(order){
						case 1:
							for(int i=0;i<n;i++){
								for(int j=i+1;j<n;j++){
									if(arr[i]>arr[j]){
										temp=arr[i];
										arr[i]=arr[j];
										arr[j]=temp;
								}
									}
							}
							cout<<"\nArray sorted successfully in ascending order!\n";
						break;
						case 2:
							for(int i=0;i<n;i++){
								for(int j=i+1;j<n;j++){
									if(arr[i]<arr[j]){
										temp=arr[i];
										arr[i]=arr[j];
										arr[j]=temp;
									}	
								}
							}
							cout<<"Array sorted successfully in descending order!";
						break;
						default:
							cout<<"Invalid order!\n";
					}
					
				}
				break;
				case 6:
					cout<<"Exiting....!";
				break;
				default:
					cout<<"Enter the number between 1-6.";
		}
		
	}while(choice!=6);
	return 0;
}
