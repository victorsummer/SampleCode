#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include "PhoneBook.hpp"

// CSV format
const char *PERSONS =
"name,age,city,phone\n\
Li,37,Chengdu,\n\
Marvel,26,Shenzhen,1454\n\
Rick,25,,556546\n\
Myung,55,Chengdu,";

int main () {
    PhoneBook phoneBook(PERSONS);

    phoneBook.printContacts();

    phoneBook.sortInPlace(Contact::EntryType::AgeEntry, false);
    phoneBook.printContacts();

    phoneBook.filterInPlace([](Contact contact)->bool {
                        return contact.age() < 55;
    });
    phoneBook.printContacts();

    return 0;
}
