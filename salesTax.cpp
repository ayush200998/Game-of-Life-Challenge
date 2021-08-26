#include<iostream>

using namespace std;

class Products {
    public:
    string item;
    float price;
    bool addTax;
};

int main(){
    
    float total = 0;
    int numOfProducts;
    string book = "book";
    string medicine = "medicine";

    // Reading the input.
        cout<< "Enter the number of products you want.\n";
        cin>> numOfProducts;
        Products products[numOfProducts];

        for(int i=0;i<numOfProducts;i++){
            cout<< "Enter the item you want \n";
            cin>> products[i].item;
            cout<< "Enter the cost of the product \n";
            cin >> products[i].price;
        }

    // Initialize tax variable.
    for(int i=0; i<numOfProducts; i++){
        products[i].addTax = false;
    }

    // Checking for tax.
    for(int i=0; i<numOfProducts; i++) {
        if(products[i].item != book && products[i].item != medicine){
            // Add Tax.
            products[i].addTax = true;
        }
    }

    // Updating the cost by adding it with the tax.
    for(int i=0; i<numOfProducts; i++){
        if(products[i].addTax){
            cout << products[i].item <<endl;
            float salesAmount = (products[i].price * 10) / 100;
            products[i].price += salesAmount;
            cout << "After adding sales tax on " <<products[i].item << " amount is: " << products[i].price << endl; 
        }
    }


    // Generating the bill.
    for(int i=0;i<numOfProducts;i++){
        total += products[i].price;
        cout<<"\nItem: " << products[i].item <<", Amount: " << products[i].price;
        cout<<"\n";
    }

    // Total amount.
    cout <<"\nTotal = " << total;
}