#include <string>
#include <algorithm>
#include <iostream>
#include "PhoneBook.hpp"
#include "CSVParser.hpp"

PhoneBook::PhoneBook(const char *rawData) {
    std::vector<std::string> rows;
    CSVParser::split(rawData, rows);
    rows.erase(rows.begin());
    for (auto &row : rows) {
        mContacts.push_back(fromCSVString(row));
    }
}

void PhoneBook::sortInPlace(const Contact::EntryType &entryType, bool assend) {
    sort(mContacts, entryType, assend);
}

void PhoneBook::filterInPlace(std::function<bool(const Contact &)> func) {
    // Remove filtered items
    filter(mContacts, func);
}

std::vector<Contact> PhoneBook::sort(const Contact::EntryType &entryType, bool assend) {
    auto contacts = mContacts;
    sort(contacts, entryType, assend);
    return contacts;
}

std::vector<Contact> PhoneBook::filter(std::function<bool (Contact)> func) {
    auto contacts = mContacts;
    filter(contacts, func);
    return contacts;
}

void PhoneBook::printContacts() {
    std::cout << "Contact list:" << std::endl;
    std::string contacts;
    std::vector<std::string> rows;
    for (auto &contact : mContacts) {
        std::string row = toCSVString(contact);
        rows.push_back(row);
    }
    CSVParser::join(contacts, rows, '\n');
    std::cout << contacts << std::endl;
}

Contact &PhoneBook::contact(const int &index) {
    return mContacts[index];
}

int PhoneBook::contactCount() {
    return mContacts.size();
}

Contact PhoneBook::fromCSVString(std::string row) {
    std::vector<std::string> item;
    CSVParser::split(row, item, ',');
    return Contact(item.at(0), std::stoi(item.at(1)), item.at(2), item.at(3));
}

std::string PhoneBook::toCSVString(Contact &contact) {
    std::vector<std::string> entries;
    entries.push_back(contact.name());
    entries.push_back(std::to_string(contact.age()));
    entries.push_back(contact.city());
    entries.push_back(contact.phone());
    std::string row;
    CSVParser::join(row, entries);
    return row;
}

void PhoneBook::sort(std::vector<Contact> &contacts, const Contact::EntryType &entryType, bool assend) {
    std::sort(contacts.begin(), contacts.end(), [entryType, assend](const Contact &p1, const Contact &p2)->bool {
        switch (entryType) {
        case Contact::EntryType::NameEntry:
            return p1.name() < p2.name() ? assend : !assend;
        case Contact::EntryType::AgeEntry:
            return p1.age() < p2.age() ? assend : !assend;
        case Contact::EntryType::CityEntry:
            return p1.city() < p2.city() ? assend : !assend;
        case Contact::EntryType::PhoneEntry:
            return p1.phone() < p2.phone() ? assend : !assend;
        default:
            return true;
        }
    });
}

void PhoneBook::filter(std::vector<Contact> &contacts, std::function<bool(const Contact &)> func) {
   contacts.erase(std::remove_if(contacts.begin(), contacts.end(), func), contacts.end());
}

