#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
class Fooditem;
class Order;
class DeliveryMan;
class Resturants;
class Customers;

int search(vector<DeliveryMan> d);

class Fooditem
{
    string name;
    float price;

public:
    Fooditem()
    {
        // Default Constructor
    }
    Fooditem(string n, float p)
    {
        name = n;
        price = p;
    }
    void priceUpdate()
    {
        cout<<"Enter New Price: ";
        float p;
        cin>>p;
        price = p;
        cout<<endl;
    }
    void display()
    {
        cout<<name<<"\t\t"<<price<<endl;
    }
    float getPrice()
    {
        return price;
    }
};

class Resturants
{
    int restu_id;
    string name;
    string type;
    float profit = 0;
    vector <Fooditem> food_items;

    public:
    Resturants(){}
    Resturants(string n, string t, vector <Fooditem> ft)
    {
        name = n;
        type = t;
        food_items = ft;
    }
    void addItem();
    void removeItem();
    void addResturant()
    {
        string n, t;
        cout<<"Give resturant name: ";
        cin>>n;
        name = n;
        cout<<"\nGive resturant type: ";
        cin>>t;
        type = t;
        cout<<endl;
    }
    void updateMenu()
    {
        cout<<"\n Chose any option \n";
        cout<<"1. Add new item to Menu \n2. Update Items Price \n3. Remove an Item from Menu\n";
        cout<<"Enter 1, 2 or 3: ";
        int k;
        cin>>k;
        switch(k)
        {
            //add items
            case 1:
                addItem();
                break;
            //update items
            case 2:
                cout<<"Enter Index: ";
                int i;
                cin>>i;
                food_items[i-1].priceUpdate();
                break;
            //remove items
            case 3:
                removeItem();
        }
    }

    void showMenu()
    {
        cout<<"********************************\n \t\t Menu\n ********************************\n";
        cout<<"\nIndex \t Item Name \t\t Price\n";
        for (int i = 0; i < food_items.size(); i++)
        {
            cout<<i+1<<"\t";
            food_items[i].display();
        }
        cout<<endl;
    }
    Fooditem accessFoodItem(int index)
    {
        return food_items[index];
    }

    void display()
    {
        cout<<"\t"<<name<<"\t\t"<<type<<"\t"<<"\n";
    }
    void addProfit(float money)
    {
        profit += money;
    }
    void showOrderItem(int index)
    {
        food_items[index].display();
    }
};
void Resturants::addItem()
{
    string f_name;
    float f_price;

    cout<<"\nEnter Food item Name: ";
    cin>>f_name;
    cout<<"\nEnter food item price: ";
    cin>>f_price;
    cout<<endl;
        
    Fooditem f_itm(f_name, f_price);

    food_items.push_back(f_itm);
}
void Resturants::removeItem()
{
    cout<<"\nChose Which item to remove by index of menu\n";
    int i;
    cin>>i;
    vector<Fooditem>::iterator itr = food_items.begin();
    itr = next(itr, i-1);
    
    food_items.erase(itr);

}
class Order
{
    //Keeps track of From which Resturant , which Order is given.
    Resturants r;
    Fooditem f;
public:
    void setOrder(Resturants r1, Fooditem f1)
    {
        r = r1;
        f = f1;
    }
    float checkPrice()
    {
        return f.getPrice();
    }

};
// void search(vector<int> i)
// {

// }
class Customers
{   
    string name;
    long long int custm_phone;
    string address;
    int orders = 0;
    bool payment_status = false;
    bool delivery_status = false;
    Order od;

public:
    Customers(){}
    Customers(string n, long long int c_id, string adrs)
    {
        name = n;
        custm_phone = c_id;
        address = adrs;
    }
    void placeOrder(Resturants R, int food_item_index)
    {
        // Takes order
        od.setOrder(R, R.accessFoodItem(food_item_index));

    }
    long long int getNumber()
    {
        return custm_phone;
    }
    string getAddress()
    {
        return address;
    }
    // Order getOrder()
    // {
    //     return od;
    // }
    bool checkPaymentStatus()
    {
        return payment_status;
    }
    float getPrice()
    {
        return od.checkPrice();
    }
    void updatePaymentStatus()
    {
        payment_status = true;
    }
    friend void takeOrder(Customers *c, DeliveryMan &dm);

};

class DeliveryMan
{
    string name;
    long long int phone_number;
    bool avilable_status = true;

public:
    DeliveryMan(){}
    DeliveryMan(string n, long long int p_n)
    {
        name = n;
        phone_number = p_n;
    }
    // void takeOrder(long long int customer_number, string customer_address, Order customers_order)
    // {
    //     cout<<"Order Taken Successfully.\n";
    //     cout<<"Delivery Man Name : "<<name<<endl;
    //     cout<<"Contact Number: +880"<<phone_number<<endl;
    //     cout<<"Estimated Delivery Time 30 Min\n";
    //     avilable_status = false;
    // }
    void deliverOrder()
    {
        cout<<"Order is at yout Door Steps, Please Collect it\n";
        avilable_status = true;
    }
    friend int search(vector<DeliveryMan> d);
    friend void takeOrder(Customers *c, DeliveryMan &dm);

};

int main()
{
    // initializing food items and price
    vector<Fooditem> localfooditems = {{"Biryani",10.99},{"Chuijhal special chicken",5.99},{"Chuijhal with merinated Duck",9.99},{"Fresh sea Fish cutlet",11.99},{"Sundarban special Fish",15.99}};
    vector<Fooditem> chinesefooditems ={{"Vegetable role",4.99},{"Fried rice",5.99},{"Chinese soup",7.99},{"Chinese Chicken",10.99},{"Dumpling",3.99}};
    vector<Fooditem> fastfoodimtes = {{"Burger",5.99},{"Fried Ckicken",6.99},{"French Fries",5.99},{"Noodles",7.99},{"Pizza",10.99}};
    vector<Fooditem> drinkitems = {{"Lemon Juice",4.99},{"Orange Juice",5.99},{"Mango Juice",5.99},{"Watermelon Juice",7.99},{"Apple Juice",5.99}};
    vector<Fooditem> desertitems = {{"Rosogolla",10.99},{"Roshmalay",12.99},{"Chomchom",12.99},{"Sondes",11.99},{"Custard",9.99}};

    // initialization Resturants.
    vector <Resturants> R = {{"Local food Hub", "Local Food", localfooditems}, {"Taste of China", "Chinese Food", chinesefooditems}, {"Fast Food Corner", "Fast Food", fastfoodimtes}, {"Drinks Delight", "Drinks", drinkitems}, {"Sweet Haven", "Desert", desertitems}};
    vector <DeliveryMan> D = {{"Rahman", 19210102912},{"Abdul", 176453889432},{"Asif", 13194876521},{"Sifat", 14962576879},{"Zihad", 18175642390}};

    cout<<"Feeling Hungry! Order Now from Resturants Nearby\n";
    cout<<"1. Customer Login \t 2. Admin login\n";
    int k;
    cin>>k;
    // Customers Section
    if (k == 1)
    {      
        string name;
        long long int PhoneNumber;
        string address;
        fflush(stdin);
        cout<<"Enter your name : ";
        getline(cin,name);
        cout<<"Enter your Phone number: ";
        cin>>PhoneNumber;
        fflush(stdin);
        cout<<"Enter your address : ";
        getline(cin,address);
        cout<<endl;

        cout<<"Welcome "<<name<<", "<<endl;

        Customers customer(name,PhoneNumber,address);

        A:
        cout<<"Choose a Resturant\n";
        cout<<"Index \t Resturant Name \t Resturant type\n";

        for (int i = 0; i < R.size(); i++)
        {
            cout<<i+1<<". ";
            R[i].display();
        }

        int x, y;
        cout<<"\nEnter index: ";
        cin>>x;

        cout<<"\nChoose from Menu\n";
        R[x-1].showMenu();

        cout<<"\nEnter index: ";
        cin>>y;


        customer.placeOrder(R[x-1] ,y-1);

        // Diplay Customers Order
        cout<<"Here is your Order details\n";
        cout<<"Resturant name \t\t Resturant Type\n";
        R[x-1].display();
        cout<<"Ordered Items\n";
        cout<<"\t";
        R[x-1].showOrderItem(y-1);

        cout<<"Enter 'y' to confirm order, 'n' to cancel : ";
        char c;
        cin>>c;
        if (c == 'y')
        {
            cout<<"Your Order Has been Confirmed\n";
        }
        else{
            cout<<"Your Has been Cancelled\n";
            cout<<"Do you want to Order again (y/n): ";
            cin>>c;
            if (c == 'y')
            {
                goto A;
            }
            else{
                cout<<"Program Terminated\n";
                return 0;
            }
        }

        

        // Asks for Payment.
        cout<<"Payment Options\n";
        cout<<"1. Online Payment \t 2. Cash on delivery\n";
        int z;
        cin>>z;
        if (z == 1)
        {
            cout <<"Taking to online Gateway....\n";
            cout<<"Enter Amount : ";
            float ammount;
            cin>>ammount;
            if (customer.getPrice() == ammount)
            {
                customer.updatePaymentStatus();
                // Search for available delivery man and give the order.
                int i = search(D);
                takeOrder(&customer, D[i]);
            }
            else{
                cout<<"Insufficient Amount, try ordering again\n";
                goto A;
            }
        }
        else if (z == 2)
        {
            int i = search(D);
            customer.updatePaymentStatus();
            takeOrder(&customer, D[i]);
            cout<<"Pay Delivery Man , the money in Cash\n";
            B:
            cout<<"Enter Cash: ";
            float ammount;
            cin>>ammount;
            if (customer.getPrice() == ammount)
            {
                
                cout<<"Thanks for Ordering, Enjoy your Meal\n";
            }
            else{
                cout<<"Please Pay Exact ammount !! \n";
                goto B;
            }
        }
    }
    // Admin Pannel
    else if (k == 2)
    {
        string key = "NGL.NGL.TBH.TBH";
        string password;
        cout<<"\nEnter password: ";
        cin>>password;

        if (key == password)
        {
            cout<<"Available Options\n";
            cout<<"1. Add Resturants 2. Update Resturnats Food Items 3. Display all\n";
            int i;
            cin>>i;
            if (i == 1)
            {
                Resturants temp;
                temp.addResturant();
                cout<<"How many Food Items to include in the Menu\n";
                int j;
                cin>>j;
                for (int k = 0; k < j; k++)
                {
                    temp.addItem();
                }
                R.push_back(temp);
            }
            if (i == 2)
            {
                cout<<"Give Resturant index\n";
                int j, k;
                cin>>j;
                R[j-1].updateMenu();                
            }
            if (i == 3)
            {
                cout<<"Displaying All resturants With their Menu\n";
                for (int i = 0; i < R.size(); i++)
                {
                    cout<<i+1<<". ";
                    R[i].display();
                    cout<<endl;
                    R[i].showMenu();
                }
            }
        }
        else{
            cout<<"Wrong Password, Program Terminated\n";
        }
    }
    // Do you want to continue

}

int search(vector<DeliveryMan> d)
{
    int i;
    for (i = 0; i < d.size(); i++)
    {
        if (d[i].avilable_status == true)
        {
            return i;
        }
    }
}
void takeOrder(Customers *c, DeliveryMan &dm)
{
    if(c->checkPaymentStatus())
    {
        cout<<"Order Taken Successfully.\n";
        cout<<"Delivery Man Name : "<<dm.name<<endl;
        cout<<"Contact Number: +880"<<dm.phone_number<<endl;
        cout<<"Estimated Delivery Time 30 Min.\n....\n........\n............\n...................\n";
        dm.deliverOrder();
    }
    else 
    {
        dm.avilable_status = true;
        cout<<"Your Order Has been Canceled\n";
    }
}