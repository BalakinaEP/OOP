#include <iostream>

class Stock
{
private:
    std::string company;
    long shares;
    double price;
    double total;
    void getTotal();
public:
    Stock(const std::string company, const long shares, const double price);
    void buy(const long my_shares, const double my_price);
    void sell(const long my_shares, const double my_price);
    void update(const double my_price);
    void show() const;
};
int main()
{
    Stock myStock("Lukoil", 1000, 5247);
    myStock.show();
    myStock.buy(1000, 5325);
    myStock.show();
    myStock.sell(500, 6000);
    myStock.show();
    myStock.update(5880);
    myStock.show();
    return 0;
}

void Stock::getTotal()
{
    total = price * shares;
}

Stock::Stock(const std::string company, const long shares, const double price):
            company(company), price(price), shares(shares)
{
    //this->company = company;
    //this->shares = shares;
    //this->price = price;
    getTotal();
}

void Stock::buy(const long my_shares, const double my_price)
{
    if (my_shares > 0)
    {
        shares += my_shares;
        price = my_price;
        getTotal();
    }
    else
    {
        std::cout << "Number of shares has to be positive.\n";
    }
}

void Stock::sell(const long my_shares, const double my_price)
{
    if (shares >= my_shares)
    {
        shares -= my_shares;
        price = my_price;
        getTotal();
    }
    else
    {
        std::cout << "Number of shares has to be less then sheres you have.\n";
    }
}

void Stock::update(const double my_price)
{
    price = my_price;
    getTotal();
}

void Stock::show() const
{
    std::cout << "Company: " << company << std::endl;
    std::cout << "Shares: " << shares << std::endl;
    std::cout << "Price: " << price << std::endl;
    std::cout << "Total: " << total << std::endl << std::endl;
}
