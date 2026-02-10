#include <iostream>
class Person
	{
	private:	
		std::string name;
		int age;
		std::string phoneNumber;
	public:
		/**
		 * @brief Контструктор объекта
		 * @param my_name имя
		 * @param my_age возраст
		 * @param my_phone телефон
		 */
		Person(const std::string my_name="", const int my_age = 0,
			const std::string my_phone = "");
		Person(const std::string my_name,
			const std::string my_phone );
		~Person();
		void show() const;
	};
int main()
{
	size_t n = 4;
	Person* persons = new Person [n];
	persons[0] = Person("Katya", 18, "999900000900");
	persons[1] = Person("Vasya", 18, "111111111111");
	persons[2] = Person();
	persons[3] = Person("Irina","22222222222");
	for (size_t i = 0; i < n; i++)
	{
		persons[i].show();
	}
	delete [] persons;
	return 0;
}

Person::Person(const std::string my_name, const int my_age, 
	const std::string my_phone)
{
	std::cout << "One new object created" << std::endl;
	name = my_name;
	age = my_age;
	phoneNumber = my_phone;
}

Person::Person(const std::string my_name, const std::string my_phone)
{
	std::cout << "One new object created" << std::endl;
	name = my_name;
	age = 0;
	phoneNumber = my_phone;
}

Person::~Person()
{
	std::cout << "One object deleted" << std::endl;
}

void Person::show() const
{
	std::cout << "name: " << name << std::endl;
	std::cout << "age: " << age << std::endl;
	std::cout << "phone: " << phoneNumber << std::endl;
}
