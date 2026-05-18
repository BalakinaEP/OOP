
#include <iostream>

template <class Type>
class Stack
{
    private:
        enum {MAX = 10};
        Type items[MAX];
        size_t top;
    public:
        Stack();
        bool isEmpty() const;
        bool ifFull() const;
        bool push(Type& item);
        bool pop(Type& item);
    
};

template <class Type>
Stack::Stack()
{
    top = 0;
}

template <class Type>
bool Stack::isEmpty()
{
    return top == 0;
}

template <class Type>
bool Stack::ifFull()
{
    return top == MAX;
}

template <class Type>
bool Stack::push(Type& item)
{
    if (top < MAX)
    { 
        items[top++] = item;
        return true;
    }
    else
    {
        return false;
    }
}

template <class Type>
bool Stack::pop(Type& item)
{
    if (top > 0)
    {
        item = items[--top];
        return true;
    }
    else
        {
            return false;
        }
}
    Stack <float>;
    
int main()
{
    Stack <int> nubers;
    Stack <std::string> colones;


    return 0;
}
