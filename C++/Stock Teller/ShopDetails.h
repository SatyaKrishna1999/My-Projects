#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

struct Item{
	int productId, quantity;
	float cost;
	string productName;
};

class Shop{
	public:
		float cost;
		char name[10];
		int code, currStock;
	
		void getdata();				// Get the Product Details

		void showdata();			// Displaying the Product Details

		void upload();				// Uploading the details into "productDetails.dat"
};

class User{
	public:
		static int ID;
		int userId;
		string name;
		string password;
		vector<Item> v;
		float total;

		void getDetails();			// Getting the New User Details

		int download(int , string );		// If the User is already existed then get his details from "UserDetails.dat"

		void update();				// For Existing User

		void upload();				// For New User

		void savePurchasingDetails(Item*, int ); // Storing the purchasing details into a vector

		void calculateTotalCost();		// Calculate the total Cost..

		void displayPurchaseDetails();		// Displaying user's Purchasing History

		void getPurchasingDetails(Shop* );	// Getting the purchasing details
};

//int User::ID=11611;
