#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
public:
    Person(const std::string& n, const std::string& s, int i);

protected:
    std::string name;
    std::string surname;
    int id;
};


Person::Person(const std::string& n, const std::string& s, int i)
    : name(n), surname(s), id(i) {
}

#endif 
