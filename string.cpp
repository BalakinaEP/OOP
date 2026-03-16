
#include <iostream>
#include <cstring>

class myString
{
private:
    char * str;
    int len;
    static int num_strings;
public:
    myString(const char* s);
    myString();
    ~myString();
    myString(const myString& st);
    myString& operator=(const myString& st);
    int getLength() const;
    friend std::ostream& operator<<(std::ostream& os, const myString& st);
};
    void callme1(myString s);
    void callme2(myString& s);

int main()
{
    myString string1("Hello World");
    myString string2("I love UIZI");
    myString string3;
    std::cout<<string1;
    std::cout<<string2;
    std::cout<<string3;
    string3 = string1;
    std::cout<<string3;
    myString string4(string1);
    callme1(string4);
    callme2(string4);
    std::cout<<"END\n";
    
    return 0;
}

int myString::num_strings = 0;

myString::myString(const char* s)
{
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str,s);
    num_strings++;
    std::cout<<"One object created\n";
}

myString::myString()
{
    len = 1;
    str = new char[len];
    std::strcpy(str,"");
    num_strings++;
    std::cout<<"Default object created\n";
}

myString::~myString()
{
    num_strings--;
    std::cout<<"One object deleted. "<<num_strings<<" object left\n";
    
}

int myString::getLength() const
{
    return len;
}


std::ostream& operator<<(std::ostream& os, const myString& st)
{
    os<<st.str<<std::endl;
    return os;
}


void callme1(myString s)
{
    std::cout<<"String passed by value:"<<s;
}

void callme2(myString& s)
{
    std::cout<<"String passed by reference:"<<s;
}

myString::myString(const myString& st)
{
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str,st.str);
    num_strings++;
    std::cout<<"One object created\n";
}

myString& myString::operator=(const myString& st)
{
    if (this == &st)
    {
        return *this;
    }
    delete [] str;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str,st.str);
    return *this;
}
