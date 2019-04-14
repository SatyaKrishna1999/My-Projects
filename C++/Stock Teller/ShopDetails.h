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
	
		void getdata();

		void showdata();

		void upload();
};

class User{
	public:
		static int ID;
		int userId;
		string name;
		string password;
		vector<Item> v;
		float total;

		void getDetails();

		int download(int , string );

		void update();

		void upload();

		void savePurchasingDetails(Item*, int );

		void calculateTotalCost();

		void displayPurchaseDetails();

		void getPurchasingDetails(Shop* );
};

//int User::ID=11611;