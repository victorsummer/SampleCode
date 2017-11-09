#pragma once

#include <vector>
#include <functional>
#include "Contact.hpp"

class PhoneBook {
public:
    explicit PhoneBook(const char *rawData);

    void sortInPlace(const Contact::EntryType &entryType, bool assend = true);
    void filterInPlace(std::function<bool(const Contact &)> func);

    std::vector<Contact> sort(const Contact::EntryType &entryType, bool assend = true);
    std::vector<Contact> filter(std::function<bool(Contact)> func);

    void printContacts();
    Contact &contact(const int &index);
    int contactCount();

private:
    Contact fromCSVString(std::string row);
    std::string toCSVString(Contact &contact);
    void sort(std::vector<Contact> &contacts, const Contact::EntryType &entryType, bool assend = true);
    void filter(std::vector<Contact> &contacts, std::function<bool(const Contact &)> func);

private:
    std::vector<Contact> mContacts;
};
