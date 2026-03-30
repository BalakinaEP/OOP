
#include <iostream>

class Account
{
    protected:
        std::string name;
        long acctNum;
        double balance;
    public:
        Account(const std::string& s = "", const long an = 0,
        const double mybalance = 0.0);
        virtual void deposit (const double amt);
        double getbalance() const;
        virtual void withdraw(const double amt);
        virtual void view() const;
        virtual ~Account() = default;
};

class AccountPlus:Account
{
    private:
        double maxLoan;
        double rate;
        double owesBank;
    public:
        AccountPlus(const std::string& s ="", const long an = 0, 
        const double bal = 0.0, const double mL = 500, const double r = 0.15 );
        AccountPlus(const Account& acc, const double mL = 500, const double r = 0);
        virtual void view() const;
        virtual void withdraw(const double amt);
        virtual void deposit (const double amt);
        void resetMaxLoan(const double mL);
        void resetRate(const double r);
        void resetOwes(const double oB = 0.0);
};

int main()
{
    Account a1 ("Ivanov", 1123456789,100);
    a1.deposit(200);
    a1.view();
    AccountPlus a2("Petrov", 11111111111,100);
    a2.view();
    a2.withdraw(150);
    a2.view();
    

    return 0;
}

Account::Account(const std::string& s, const long an, const double mybalance)
        {
            name = s;
            acctNum = an;
            balance = mybalance;
        }
        
 void Account::deposit (const double amt)
 {
     if (amt<0)
     {
         std::cout<<"error, amount has to be positive\n";
     }
     else
     {
         balance+=amt;
     }
 }
 
 double Account::getbalance() const
 {
     return balance;
 }
 
 void Account::withdraw(const double amt)
 {
     if (balance-amt<0)
     {
         std::cout<<"Error, amount has to be less then your balance\n";
     }
     else
     {
         balance-=amt;
     }
 }
 
 void Account::view() const
 {
     std::cout<<"name "<<name<<std::endl;
     std::cout<<"account number "<<acctNum<<std::endl;
     std::cout<<"balance "<<balance<<std::endl;
 }
 
 AccountPlus::AccountPlus(const std::string& s, const long an, 
        const double bal, const double mL, const double r )
        :Account(s,an,bal)
        {
            maxLoan = mL;
            rate = r;
            owesBank = 0.0;
        }
        
AccountPlus::AccountPlus(const Account& acc, const double mL, const double r)
    : Account(acc)
{
            maxLoan = mL;
            rate = r;
            owesBank = 0.0;
}

void AccountPlus::view() const
{
    Account::view();
    std::cout<<"max loan "<<maxLoan<<std::endl;
    std::cout<<"rate "<<rate<<std::endl;
    std::cout<<"owesBank "<<owesBank<<std::endl;
}

void AccountPlus::withdraw(const double amt)
{
    if (balance+maxLoan-owesBank-amt<0)
     {
         std::cout<<"Error,you have no money\n";
     }
     else
     {
         balance-=amt;
         if (balance < 0)
         {
             owesBank-=balance;
             balance = 0;
         }
     }
}

void AccountPlus::resetMaxLoan(const double mL)
{
    maxLoan = mL;
}

void AccountPlus::resetRate(const double r)
{
    rate = r;
}

void AccountPlus::resetOwes(const double oB)
{
    owesBank = oB;
}

void AccountPlus::deposit (const double amt)
{
    if (owesBank >= amt)
    {
        owesBank-=amt;
    }
    else
    {
        
        balance += amt - owesBank;
        owesBank = 0;
    }
}
