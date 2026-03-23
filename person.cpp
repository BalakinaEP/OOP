#include <iostream>

class Person
{
    protected:
        std::string name;
        std::string surname;
        std::string patronymic;
    public:
        Person(const std::string& name, const std::string& surname, 
            const std::string& patronymic = "");
        virtual std::string ToString() const;
        virtual ~Person() = default;
};

class Student:Person
{
    private:
        std::string group;
    public:
        Student(const std::string& group, const std::string& name,const std::string& surname, 
            const std::string& patronymic="");
        std::string ToString() const override;
    
};
int main()
{
    Person person("Ivanov", "Ivan", "Ivanovich");
    Student student("TKI-14","Petrov", "Petr", "Petrovich");
    std::cout<<person.ToString()<<std::endl;
    std::cout<<student.ToString()<<std::endl;

    return 0;
}

Person::Person(const std::string& name, const std::string& surname, 
            const std::string& patronymic):name(name), surname(surname),patronymic(patronymic)
{
    
}

std::string Person::ToString() const
{
    return surname+" "+name+" "+patronymic;
}

Student::Student(const std::string& group, const std::string& name, const std::string& surname, 
            const std::string& patronymic):Person(name, surname, patronymic), group(group)
{            
}           
            
std::string Student::ToString() const
{
    return Person::ToString() + " "+ group;
}
