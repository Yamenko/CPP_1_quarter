#include <iostream>
#include <string>
#include <tuple>
#include <optional>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>


//===========================
// Структура для ФИО
//===========================
struct Person{
    std::string lastName;
    std::string firstName;
    std::optional<std::string> middleName;
} person;

//===========================
// Структура для телефона
//===========================
struct PhoneNumber{
    uint16_t countryCode;
    uint16_t cityCode;
    std::string number;
    std::optional<uint16_t> externNum;
} phoneNumber;

//============================
// Операторы сравнения 
// Телефон и ФИО
//============================
bool operator==(const Person& p1, const Person& p2) {
    return  tie(p1.firstName, p1.lastName, p1.middleName) == tie(p2.firstName, p2.lastName, p2.middleName);
}
bool operator<(const Person& p1, const Person& p2) {
    return  tie(p1.firstName, p1.lastName, p1.middleName) < tie(p2.firstName, p2.lastName, p2.middleName);
}
bool operator==(const PhoneNumber& p1, const PhoneNumber& p2) {
    return tie(p1.countryCode, p1.cityCode, p1.number, p1.externNum) == tie(p2.countryCode, p2.cityCode, p2.number, p2.externNum);
}

bool operator<(const PhoneNumber& p1, const PhoneNumber& p2) {
    return tie(p1.countryCode, p1.cityCode, p1.number, p1.externNum) < tie(p2.countryCode, p2.cityCode, p2.number, p2.externNum);
}
//----------------------------

//===========================
// Операторы вывода на печать
// Телефон и ФИО
//===========================
std::ostream& operator<<(std::ostream& out, const PhoneNumber& pn) {
    out << "\t\t+" << pn.countryCode << "(" << pn.cityCode << ")" << pn.number;
    if (pn.externNum.has_value()) {
        out << " " << pn.externNum.value();
    }
    return out;
};
std::ostream& operator<<(std::ostream& out, const Person& pn) {
    out << pn.lastName << "\t\t" << pn.firstName;
    if (pn.middleName.has_value()) {
        out << "\t\t " << pn.middleName.value();
    }
    return out;
};
//---------------------------

//===========================
// Класс записной книжки
//===========================
class PhoneBook {
private:
    std::vector<std::pair<Person, PhoneNumber>> phoneBook;

public:
    // Конструктор класса принимает открытый поток файла
    // и заполняет поля структуры
    PhoneBook(std::ifstream& str) {
        std::stringstream myStream;
        std::string line = "";
        std::string sTmp;   // вспомогательная переменная чтобы положить данные в переменную оптионал-стринг
        int num;            // вспомогательная переменная чтобы положить данные в переменную оптионал-инт
        
        while (str.is_open() && !str.eof()) {
            std::getline(str, line);
            if (line.find("+") > 0) { // проверяем есть ли + внутри строки
                myStream << line.substr(0, line.find("+")); // в поток положим все данные ДО +
                myStream >> person.lastName >> person.firstName >> sTmp;
                if (!sTmp.empty()) { person.middleName = sTmp; }
                myStream.clear();

                myStream << line.substr(line.find("+"), line.rfind("+")); // в поток положим все данные ПОСЛЕ +
                myStream >> phoneNumber.countryCode >> phoneNumber.cityCode >> phoneNumber.number >> num;
                if (num != 0) { phoneNumber.externNum = num; }
                myStream.clear();

                //Заносим пару в вектор Записная книга 
                phoneBook.push_back(std::make_pair(person, phoneNumber));
            }
            line.erase();
        }
        str.close();
    };

    // Вывод данных на экран через перегруженные операторы вывода.
    friend std::ostream& operator<<(std::ostream& out, PhoneBook& pb) {
        for (auto it : pb.phoneBook) {
            out << it.first << it.second << std::endl;
        }
        return out;
    };

    // Сортировка через перегруженные операторы сравнения    
    void SortByName() {
        std::sort(this->phoneBook.begin(), this->phoneBook.end(),
            [](std::pair<Person, PhoneNumber> p1, std::pair<Person, PhoneNumber> p2) {return p1.first < p2.first;});
    };
    void SortByPhon() {
        std::sort(this->phoneBook.begin(), this->phoneBook.end(),
            [](std::pair<Person, PhoneNumber> p1, std::pair<Person, PhoneNumber> p2) {return p1.second < p2.second;});
    };

    // Поиск номера по фамилии
    void GetPhoneNumber(std::string& lName) {
        int count = 0; // счетчик сколько нашли совпадений

        for (auto pr : this->phoneBook) {
            if (lName == pr.first.lastName) { count++; };
        }
        switch (count)
        {
        case (0):
            std::cout << lName << " not found" << std::endl;
            break;
        case (1):
            for (auto pr : this->phoneBook) {
                if (lName == pr.first.lastName) {
                    std::cout << pr.first << pr.second << std::endl;
                }
            }
            break;
        default:
            std::cout << lName << " found more than 1" << std::endl;
            break;
        }
    };

    // Замена номера телефона человека
    void ChangePhoneNumber(Person& prChng, PhoneNumber& pnChng) {
        int i = 0;
        for (auto el : this->phoneBook)
        {
            if (el.first == prChng) { this->phoneBook[i] = std::make_pair(prChng, pnChng); }
            i++;
        }
    }

};
//---------------------------

int main()
{
    std::ifstream  dataToPars("Phonebook1.txt", std::ios_base::in);
    PhoneBook book(dataToPars);
    std::cout << "--------PhonBook----------" << std::endl;
    std::cout << book << std::endl;
    std::cout << "--------------------------" << std::endl;

    std::cout << "--------SortByName--------" << std::endl;
    book.SortByName();
    std::cout << book << std::endl;
    std::cout << "--------------------------" << std::endl;

    std::cout << "--------SortByPhon--------" << std::endl;
    book.SortByPhon();
    std::cout << book << std::endl;
    std::cout << "--------------------------" << std::endl;

    std::cout << "--------GetNomber---------" << std::endl;
    std::string nameToFind = "Dubinin";
    book.GetPhoneNumber(nameToFind);
    nameToFind = "Leo";
    book.GetPhoneNumber(nameToFind);
    std::cout << "--------------------------" << std::endl;

    std::cout << "-------ChangeNomber-------" << std::endl;
    Person perToChange;
    PhoneNumber phnToChange;
    //Dubinin Aleksei Mikhailovich + 7 473 7449054
    nameToFind = "Dubinin";

    perToChange = { "Dubinin", "Aleksei", "Mikhailovich"} ;
    phnToChange = { 3, 999, "1112233", std::nullopt };
        
    book.ChangePhoneNumber(perToChange, phnToChange);
    book.GetPhoneNumber(nameToFind);
    std::cout << "--------------------------" << std::endl;
}