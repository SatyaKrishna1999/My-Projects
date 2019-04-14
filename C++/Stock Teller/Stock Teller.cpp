#include<iostream>
#include<conio.h>
#include "ShopDetails.h"
#include<fstream>
using namespace std;

int numProducts=4;

// function to display  all the products to the user...
void displayAllProducts(Shop product[]){
	cout<<"S.NO\tProductID\tProductName\tCurrent Stock\tCost(per item)"<<endl;
	for(int i=0; i<numProducts; i++){
		cout<<i+1<<"\t"<<product[i].code<<"\t"<<product[i].name<<"\t"<<product[i].currStock<<"\t"<<product[i].cost<<endl;
	}
	
}

// Randomly Initializing the static ID in the User class
// This will be User ID for a newly created user and will be incremented after the user has been created...
int User::ID=11611;

int main(){

	// Shop item[numProducts];

	// for(int i=0;i<numProducts;i++){
	// 	cout<<"Enter the details of Item "<<i+1<<" :: ";
	// 	item[i].getdata();
	// 	item[i].upload();
	// }

	// cout<<"\n\nShowing the Details of each product..............\n"<<endl;

	// Getting the details of each item...
	Shop product[numProducts];

	ifstream fin;
	fin.open("productDetails.dat");

	for(int i=0;i<numProducts;i++){		
		fin.read((char*)&product[i], sizeof(product[i]));			// Downloading the product Details....
		//product[i].showdata();
	}

	fin.close();

	// User Part
	cout<<"******************		Welcome to Our Site!!		******************"<<endl;
	cout<<"Are u a new User?? (0/1) :: ";						// 0 stands for Existing User and 1 stands for New User

	int isNew;
	cin>>isNew;
	cout<<endl;
	User obj;

	if(isNew)													// User is new. So take the information about the user...
		obj.getDetails();
	
	else{
		while(1){												// Getting the logging credentials of the existing user
			int userID;
			string password;
			cout<<"Enter UserName :: ";
			cin>>userID;
			cout<<"Enter Password :: ";
			char ch;
			ch = getch();
			while(ch != 13){
				//character 13 is enter
				password.push_back(ch);
			    cout << '*';
			    ch = getch();
			}
			
			if(!obj.download(userID, password)){
				cout<<"Incorrect UserName or Password!!"<<endl;
			}
			else											// User is not allowed to go further unless his login credentials are correct.
				break;
		}
	}

	int flag=1;
	
	int ch;
	while(flag==1){											// Displaying the Menu
		cout<<"1. Purchase Items"<<endl;
		cout<<"2. Show Total Cost"<<endl;
		cout<<"3. Exit"<<endl;

		cout<<"Enter Option :: ";

		cin>>ch;
		switch(ch){

			case 1:
				displayAllProducts(product);				// Display all the products
				obj.getPurchasingDetails(product);			// Get the purchasing details
				break;

			case 2:
				obj.calculateTotalCost();					// Calculating the total cost and displaying it.
				obj.displayPurchaseDetails();
				break;

			case 3:											// Exiting....
				cout<<"Thank You!!"<<endl;
				flag=0;
				break;
		}
		cout<<"================================================================================================================"<<endl<<endl;
	}
	
	// Save User Details....

	if(!isNew)												// If the user is already existed then update the DB
		obj.update();
	else
		obj.upload();										// Else just save his details....
	
	remove("productDetails.dat");

	for(int i=0;i<numProducts;i++)							// Update the Product Details also.
		product[i].upload();

	return 0;
}


