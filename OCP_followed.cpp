#include<iostream>
#include<vector>

using namespace std;

class Product {
public:
    string name;
    double price;
    Product(string name, double price) {
        this-> name = name;
        this-> price = price;
    }
};

// 1. ShoppingCart: Only responsible for cart related business logic

class ShoppingCart{
private:
vector<Product*> products;

public:
    void addProduct(Product* p){
        products.push_back(p);
    }

    const vector<Product*>& getProducts(){
        return products;
    }

    // calculates total price in cart.
    double calculateTotal(){
        double total = 0;
        for(auto p : products){
            total += p-> price;
        }
        return total;
    }
};

// 2. ShoppingCartPrinter: Only responsible for printing Invoice 

class ShoppingCartPrinter{
    
private:   
    ShoppingCart* cart;

public:
    ShoppingCartPrinter(ShoppingCart* cart){
        this->cart = cart;
    }

    void printInvoice(){
        cout << "Invoice:" << endl;
        for(auto p : cart->getProducts()){
            cout << p->name << " - $" << p->price << endl;
        }
        cout << "Total: $" << cart->calculateTotal() << endl;
    }
};


// Abstract class

class Persistance {
private:
    ShoppingCart* cart;
public:
    virtual void save(ShoppingCart* cart) = 0; // pure virtual function
};

class SQLPersistance: public Persistance {
    public:
        void save(ShoppingCart* cart){
            cout<<"Saving shopping cart to SQL database..."<<endl;
        }
};

class MongoPersistance: public Persistance {
    public:
        void save(ShoppingCart* cart){
            cout<<"Saving shopping cart to MongoDB database..."<<endl;
        }
};

class FilePersistance: public Persistance {
    public:
        void save(ShoppingCart* cart){
            cout<<"Saving shopping cart to File database..."<<endl;
        }
};

int main(){
    ShoppingCart* cart = new ShoppingCart();
    cart->addProduct(new Product("Laptop", 15000));
    cart->addProduct(new Product("Mouse", 50));

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

    // Using OCP for saving to different databases without modifying existing code
    Persistance* db = new SQLPersistance();
    Persistance* mongodb = new MongoPersistance();
    Persistance* file = new FilePersistance();
   
    db->save(cart);  // save to SQl database
    mongodb->save(cart); // save to MongoDB 
    file->save(cart); // save to File

}


// =========================================================================================

//                                         OUTPUT

// =========================================================================================

//                                     Invoice:
//                                     Laptop - $15000
//                                     Mouse - $50
//                                     Total: $15050
//                                     Saving shopping cart to SQL database...
//                                     Saving shopping cart to MongoDB database...
//                                     Saving shopping cart to File database...

// =========================================================================================
