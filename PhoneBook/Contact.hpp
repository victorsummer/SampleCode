#pragma once

#include <string>

class Contact {
public:
    enum class EntryType : std::uint8_t {
        NameEntry = 100,
        AgeEntry,
        CityEntry,
        PhoneEntry
    };

    explicit Contact(const std::string &name,
                     int age,
                     const std::string &city,
                     const std::string &phone);

    inline const std::string &name() const { return mName; }
    inline void setName(const std::string &name) { mName = name; }
    inline int age() const { return mAge; }
    inline void setAge(int age) { mAge = age; }
    inline const std::string &city() const { return mCity; }
    void setCity(const std::string &city) { mCity = city; }
    inline const std::string &phone() const { return mPhone; }
    inline void setPhone(const std::string &phone) { mPhone = phone; }

private:
    std::string mName;
    int mAge = 0;
    std::string mCity;
    std::string mPhone;
};
