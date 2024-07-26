#include <iostream>
using namespace std;

class Human {
private:
    char* name;
    void copyString(char* dest, const char* src) {
        while (*src) {
            *dest++ = *src++;
        }
        *dest = '\0';
    }
    size_t stringLength(const char* str) const {
        size_t length = 0;
        while (*str++) {
            ++length;
        }
        return length;
    }
public:
    Human() : name(nullptr) {}
    Human(const char* name) {
        size_t len = stringLength(name);
        this->name = new char[len + 1];
        copyString(this->name, name);
    }
    Human(const Human& other) {
        size_t len = stringLength(other.name);
        name = new char[len + 1];
        copyString(name, other.name);
    }
    Human& operator=(const Human& other) {
        if (this == &other) return *this;
        delete[] name;
        size_t len = stringLength(other.name);
        name = new char[len + 1];
        copyString(name, other.name);
        return *this;
    }
    ~Human() {
        delete[] name;
    }

    void print() const {
        if (name) {
            cout << name << endl;
        }
        else {
            cout << "No name" << endl;
        }
    }
};
class Apartment {
private:
    Human* residents;
    int residentCount;

public:
    Apartment() : residents(nullptr), residentCount(0) {}
    void addResident(const Human& resident) {
        Human* newResidents = new Human[residentCount + 1];
        for (int i = 0; i < residentCount; ++i) {
            newResidents[i] = residents[i];
        }
        newResidents[residentCount] = resident;
        delete[] residents;
        residents = newResidents;
        ++residentCount;
    }
    Apartment(const Apartment& other) : residentCount(other.residentCount) {
        residents = new Human[residentCount];
        for (int i = 0; i < residentCount; ++i) {
            residents[i] = other.residents[i];
        }
    }
    Apartment& operator=(const Apartment& other) {
        if (this == &other) return *this;
        delete[] residents;
        residentCount = other.residentCount;
        residents = new Human[residentCount];
        for (int i = 0; i < residentCount; ++i) {
            residents[i] = other.residents[i];
        }
        return *this;
    }
    ~Apartment() {
        delete[] residents;
    }

    void print() const {
        for (int i = 0; i < residentCount; ++i) {
            residents[i].print();
        }
    }
};
class House {
private:
    Apartment* apartments;
    int apartmentCount;

public:
    House() : apartments(nullptr), apartmentCount(0) {}
    void addApartment(const Apartment& apartment) {
        Apartment* newApartments = new Apartment[apartmentCount + 1];
        for (int i = 0; i < apartmentCount; ++i) {
            newApartments[i] = apartments[i];
        }
        newApartments[apartmentCount] = apartment;
        delete[] apartments;
        apartments = newApartments;
        ++apartmentCount;
    }
    House(const House& other) : apartmentCount(other.apartmentCount) {
        apartments = new Apartment[apartmentCount];
        for (int i = 0; i < apartmentCount; ++i) {
            apartments[i] = other.apartments[i];
        }
    }
    House& operator=(const House& other) {
        if (this == &other) return *this;
        delete[] apartments;
        apartmentCount = other.apartmentCount;
        apartments = new Apartment[apartmentCount];
        for (int i = 0; i < apartmentCount; ++i) {
            apartments[i] = other.apartments[i];
        }
        return *this;
    }
    ~House() {
        delete[] apartments;
    }
    void print() const {
        for (int i = 0; i < apartmentCount; ++i) {
            apartments[i].print();
        }
    }
};
int main() {
    Human human1("John Doe");
    Human human2("Jane Smith");
    Apartment apt1;
    apt1.addResident(human1);
    apt1.addResident(human2);
    House house;
    house.addApartment(apt1);
    house.print();
}
