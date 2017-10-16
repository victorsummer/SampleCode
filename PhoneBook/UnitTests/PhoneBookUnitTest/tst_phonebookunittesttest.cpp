#include <QtTest>
#include <string>
#include <memory>

#include "PhoneBook.hpp"

// CSV format
const char *PERSONS =
"name,age,city,phone\n\
Boby,37,Chengdu,\n\
Marvel,26,Shenzhen,1454\n\
Rick,25,,556546\n\
Myung,55,Chengdu,";


class PhoneBookUnitTestTest : public QObject {
    Q_OBJECT

public:
    PhoneBookUnitTestTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testSort();
    void testFilter();

private:
    std::shared_ptr<PhoneBook> mPhoneBook;
};

PhoneBookUnitTestTest::PhoneBookUnitTestTest() {}

void PhoneBookUnitTestTest::initTestCase() {
    mPhoneBook = std::make_shared<PhoneBook>(PERSONS);
}

void PhoneBookUnitTestTest::cleanupTestCase() {
    mPhoneBook.reset();
}

void PhoneBookUnitTestTest::testSort() {
    mPhoneBook->sortInPlace(Contact::NameEntry);
    QVERIFY2(mPhoneBook->contact(0).name() == "Boby", "PhoneBook::sortInPlace the sort result is incorrect.");
    QVERIFY2(mPhoneBook->contact(1).name() == "Marvel", "PhoneBook::sortInPlace the sort result is incorrect.");
    QVERIFY2(mPhoneBook->contact(2).name() == "Myung", "PhoneBook::sortInPlace the sort result is incorrect.");
    QVERIFY2(mPhoneBook->contact(3).name() == "Rick", "PhoneBook::sortInPlace the sort result is incorrect.");

    mPhoneBook->sortInPlace(Contact::AgeEntry);
    QVERIFY2(mPhoneBook->contact(0).name() == "Rick", "PhoneBook::sortInPlace the sort result is incorrect.");
    QVERIFY2(mPhoneBook->contact(1).name() == "Marvel", "PhoneBook::sortInPlace the sort result is incorrect.");
    QVERIFY2(mPhoneBook->contact(2).name() == "Boby", "PhoneBook::sortInPlace the sort result is incorrect.");
    QVERIFY2(mPhoneBook->contact(3).name() == "Myung", "PhoneBook::sortInPlace the sort result is incorrect.");
}

void PhoneBookUnitTestTest::testFilter() {
    // Filter contacts whose age is under 30
    mPhoneBook->filterInPlace([](Contact contact)->bool {
        return contact.age() < 30;
    });

    QCOMPARE(mPhoneBook->contactCount(), 2);
    QVERIFY2(mPhoneBook->contact(0).name() == "Boby", "PhoneBook::filterInPlace the sort result is incorrect.");
}

QTEST_APPLESS_MAIN(PhoneBookUnitTestTest)

#include "tst_phonebookunittesttest.moc"
