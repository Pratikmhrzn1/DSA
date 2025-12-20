#include<iostream>
using namespace std;
void printRightAngledTriangle(int n){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cout<<"*"<<" ";
		}
		cout<<endl;
	}
}
void printInverseRightAngledTriangle(int n){
	for(int i=1;i<=n;i++){
		for(int j=n;j>=i;j--){
			cout<<"*"<<" ";
		}
		cout<<endl;
	}
}
void printSquare(int n){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<"*"<<" ";
		}
		cout<<endl;
	}
}
void printLeftAngledTriangle(int n)
{
    for (int i=0;i<5;i++) {
        for(int j=0;j<i;j++) {
            cout<<"  ";
        }
        for(int j=5;j>i;j--) {
            cout<<"* ";
        }
        cout<<endl;
    }
}
void printPyramid(int n){
	for(int i=1; i<=5;i++) {
        for(int j=5;j>i;j--) {
            cout<<" ";
        }
        for (int j=1;j<=i;j++) {
            cout << "* ";
        }
        cout << endl;
    }
}
void printInversePyramid(int n){
	for(int i=5; i>=1;i--) {
        for(int j=5;j>i;j--) {
            cout<<" ";
        }
        for (int j=1;j<=i;j++) {
            cout << "* ";
        }
        cout << endl;
    }
}
void printHollowSquare(int n){
	for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++){

            // boundary condition
            if(i==1 || i==5 || j==1 || j==5){
                cout<<"* ";
            } else {
                cout<<"  ";
            }
        }
        cout<<endl;
    }
}
using namespace std;
int main(){
	int n=5;
	cout<<"Right angled triangle pattern:\n";
	printRightAngledTriangle(n);
	cout<<"--------------------------------------\n";
	cout<<"Inverse Right angled triangle pattern:\n";
	printInverseRightAngledTriangle(n);
	cout<<"--------------------------------------\n";
	cout<<"Square pattern:\n";
	printSquare(n);
	cout<<"--------------------------------------\n";
	cout<<"Left Angled Triangle:\n";
	printLeftAngledTriangle(n);
	cout<<"--------------------------------------\n";
	cout<<"Pyramid:\n";
	printPyramid(n);
	cout<<"--------------------------------------\n";
	cout<<"Inverse Pyramid:\n";
	printInversePyramid(n);
	cout<<"--------------------------------------\n";
	cout<<"Diamond:\n";
	printPyramid(n);
	printInversePyramid(n);
	cout<<"--------------------------------------\n";
	cout<<"Hollow Square:\n";
	printHollowSquare(n);
	
}
