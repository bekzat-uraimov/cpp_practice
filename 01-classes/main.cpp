#include <iostream>
#include <string>

// Parent class
class Person {
public:
    std::string name;
    std::string surname;

    Person() : name(""), surname(""), age(0), address("") {}

    Person(const std::string& name, const std::string& surname, int age, const std::string& address)
        : name(name), surname(surname), age(age), address(address) {}

    void setAge(int age) { this->age = age; }
    int getAge() const { return age; }

    void printFullName() const {
        std::cout << name << " " << surname << std::endl;
    }

private:
    int age;
    std::string address;
};

// Child class - inherits from Person
class Employee : public Person {
public:
    Employee(const std::string& name, const std::string& surname, const std::string& position)
        : Person(name, surname, 0, ""), position(position) {}

    std::string getPosition() const { return position; }

private:
    std::string position;
};

int main() {
    // Public members
    Person p;
    p.name = "Bekzat";
    p.surname = "Uraimov";
    p.printFullName();
    p.setAge(25);
    std::cout << p.getAge() << std::endl;

    // Private members via constructor + getter
    Person p2("Bayaman", "Uraimov", 30, "Bishkek");
    p2.printFullName();
    std::cout << p2.getAge() << std::endl;

    // Inheritance
    Employee e("John", "Doe", "Manager");
    e.setAge(40);
    e.printFullName();
    std::cout << e.getPosition() << std::endl;
    std::cout << e.getAge() << std::endl;

    return 0;
}

// --- Notes ---
// class          - describes the structure
// object         - a specific example of that structure
// instance       - another name for object
// instantiating  - creating an object from a class
// data members   - variables that belong to a class
// methods        - functions that belong to a class
//
// parent class   - the class being inherited from
// child class    - inherits from the parent class
//
// abstraction    - making something easy to use by hiding the complex stuff
// encapsulation  - granting access to private data only through controlled public interfaces
// inheritance    - creating derived classes that inherit properties from a base class
// polymorphism   - different objects treated as the same type, even if they are different classes
