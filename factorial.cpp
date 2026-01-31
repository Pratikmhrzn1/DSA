#include<iostream>
using namespace std;
int factorial(int n){
	if(n==0 || n==1){
		return 1;
	}
	return n*factorial(n-1);
}
int main(){
	int value;
	cout<<"Enter a value:";
	cin>>value;
	cout<<"The factorial of the "<<value<<" is "<<factorial(value)<<endl;
	return 0;
}
