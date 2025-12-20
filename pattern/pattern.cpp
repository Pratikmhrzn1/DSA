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
	int choice;
	do{
		cout << "\n================ PATTERN MENU ================\n";
		cout << "1. Right Angled Triangle\n";
		cout << "2. Inverse Right Angled Triangle\n";
		cout << "3. Square Pattern\n";
		cout << "4. Left Angled Triangle\n";
		cout << "5. Pyramid\n";
		cout << "6. Inverse Pyramid\n";
		cout << "7. Diamond\n";
		cout << "8. Hollow Square\n";
		cout << "9. Exit\n";
		cout << "==============================================\n";
		cout<<"Enter your choice:";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"Right angled triangle pattern:\n";
				printRightAngledTriangle(n);
				cout<<"--------------------------------------\n";
				break;
			case 2:
				cout<<"Inverse Right angled triangle pattern:\n";
				printInverseRightAngledTriangle(n);
				cout<<"--------------------------------------\n";
				break;
			case 3:
				cout<<"Square pattern:\n";
				printSquare(n);
				cout<<"--------------------------------------\n";
				break;
			case 4:
				cout<<"Left Angled Triangle:\n";
				printLeftAngledTriangle(n);
				cout<<"--------------------------------------\n";
				break;
			case 5:
				cout<<"Pyramid:\n";
				printPyramid(n);
				cout<<"--------------------------------------\n";
				break;
			case 6:
				cout<<"Inverse Pyramid:\n";
				printInversePyramid(n);
				cout<<"--------------------------------------\n";
				break;
			case 7:
				cout<<"Diamond:\n";
				printPyramid(n);
				printInversePyramid(n);
				cout<<"--------------------------------------\n";
				break;
			case 8:
				cout<<"Hollow Square:\n";
				printHollowSquare(n);
				break;
			case 9:
				cout<<"Thank you!!!"<<endl;
				break;
			default:
				cout<<"Invalid choice!"<<endl;
				
		}		
	}while(choice!=9);
	
}
