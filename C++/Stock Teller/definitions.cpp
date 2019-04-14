
#include<vector>
#include<iomanip>
#include<fstream>
#include<conio.h>
#include "ShopDetails.h"

void Shop:: getdata(){
	
	cout<<"enter the name of item"<<endl;
	cin>>name;
	cout<<"enter the cost of item"<<endl;
	cin>>cost;
	cout<<"enter the code of the item"<<endl;
	cin>>code;
	cout<<"Enter Current Stock :: ";
	cin>>currStock;
}

void Shop:: showdata(){
	cout<<"the details of the items are"<<endl;
	cout<<"the name of the item is"<<setw(10)<<name<<endl;
	cout<<"the cost of the item is "<<cost<<setprecision(5)<<endl;
	cout<<"the code of the item is "<<setw(10)<<code<<endl;
}


void Shop:: upload(){
	// If u don't want the previously saved data then remove ios::app then it will overwrite the existing file......

	ofstream fout;
	fout.open("productDetails.dat",ios::out| ios::app);
	fout.write((char*)this, sizeof(*this));
	fout.close();
}

void User:: getDetails(){
	ID++;
	userId=ID;
	cout<<"Enter Name :: ";
	cin>>name;

	cout<<"Your UserID is "<<ID<<endl;
	cout<<"Enter Password :: ";
	char ch;
	ch=getch();
	while(ch != 13){
		//character 13 is enter
		password.push_back(ch);		// adding at the last position...
	    cout << '*';
	    ch = getch();
	}
	cout<<"\nNew User is Created!!"<<endl;
}

int User:: download(int userId, string password){
	ifstream fin;

	fin.open("user.dat");
	fin.read((char*)this, sizeof(*this));

	while(!fin.eof()){
		if(userId==this->userId && password==this->password)
			return 1;
		
		fin.read((char*)this, sizeof(*this));
	}
	return 0;
}

void User:: update(){
	int id=userId;
	fstream file;
	file.open("user.dat",ios::in|ios::ate|ios::out);
	file.seekg(0,ios::beg);
	file.read((char*)this, sizeof(*this));
	
	while(!file.eof()){
		if(id==userId){
			file.seekp(file.tellp());
			file.write((char*)this,sizeof(*this));
			file.close();
			break;
		}
		file.read((char*)this, sizeof(*this));
	}

	cout<<"Updating Completed!!"<<endl;
}


void User:: upload(){
	// If u don't want the previously saved data then remove ios::app then it will overwrite the existing file......

	ofstream fout;
	fout.open("user.dat",ios::out|ios::app);
	fout.write((char*)this, sizeof(*this));
	fout.close();
	cout<<"Uploading Completed!!"<<endl;
}


void User:: savePurchasingDetails(Item arr[], int n){
	for(int i=0;i<n;i++){
		v.push_back(arr[i]);
	}
}

void User:: calculateTotalCost(){
	total=0;
	for(int i=0; i!=v.size(); i++){
		total+=v[i].cost*v[i].quantity;
	}
}

void User:: displayPurchaseDetails(){

	if(v.size()==0){
		cout<<"Your Cart is empty!!"<<endl;
		return;
	}
	cout<<"ProductID\tProductName\tQuantity\tCost(per item)"<<endl;
	
	for(int i=0; i<v.size(); i++){
		cout<<v[i].productId<<"\t"<<v[i].productName<<"\t"<<v[i].quantity<<"\t"<<v[i].cost<<endl;
	}

	cout<<"Total Cost :: "<<total<<endl;
}

void User:: getPurchasingDetails(Shop product[]){
	
	int n;

	// Save the product details....
	cout<<"Enter number of products u want to buy??";
	cin>>n;
	Item arr[n];

	for(int i=0;i<n;i++){
		int id;
		cout<<"Enter Product S.No :: ";
		cin>>id;
		arr[i].productId=product[id-1].code;
		arr[i].productName=product[id-1].name;
		arr[i].cost=product[id-1].cost;
		cout<<"Enter Product Quantity :: ";
		cin>>arr[i].quantity;

		while(arr[i].quantity>product[id-1].currStock){
			cout<<"Quantity exceeded the current stock!!";
			cout<<"Enter Product Quantity :: ";
			cin>>arr[i].quantity;
		}

		product[id-1].currStock=product[id-1].currStock-arr[i].quantity;

	}

	savePurchasingDetails(arr, n);
}