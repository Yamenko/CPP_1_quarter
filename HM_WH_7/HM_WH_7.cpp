#include <iostream>
#include <fstream>
#include <string>
#include "Source.pb.h"

// 1. Установить библиотеку protobuf.
// 2. С помощью компилятора protobuf в отдельном пространстве имен сгенерировать классы
//      a.FullName с полями имя, фамилия, отчество(отчество опционально).
//      b.Student с полями полное имя, массив оценок, средний балл.
//      c.StudentsGroup с полем массив студентов.
// 3. Создать класс StudentsGroup, который реализует интерфейсы :



class StudentsGroup {

private:
    // Создаем группу
    HW_7::StudentsGroup group;
    // Добавляем студента 
    HW_7::Student* stud = group.add_students();
    // Добавляем ФИО
    HW_7::Student_FullName* name = stud->add_namestudent();

public:

    void addInfo() {
        // Заполняем ФИО
        name->set_firstname("First");
        name->set_midlename("Midle");
        name->set_lastname("Last");

        //Заполняем оценки
        stud->add_marksstudent(5);
        stud->add_marksstudent(5);
        stud->add_marksstudent(4);
        stud->add_marksstudent(4);

        stud->set_averagemark(4.500f);
    };


    std::string SerializeAsString() { return group.SerializeAsString(); };

    class IRepository {
        friend StudentsGroup;
    private:
        StudentsGroup& data;
    public:
        IRepository(StudentsGroup& data) : data(data) {};
        // бинарная десериализация в файл
        void Open() {
            std::ifstream in("source.bin", std::ios_base::binary);
            data.group.ParseFromIstream(&in);
        };

        // бинарная сериализация в файл
        void Save() {
            std::ofstream out("source.bin", std::ios_base::binary);
            data.group.SerializeToOstream(&out);
        };
    };

    class IMethods {
    private:
        StudentsGroup& data;
    public:
        IMethods(StudentsGroup& data) : data(data) {};
        
        float GetAverageScore(const HW_7::Student_FullName& name) {          
            for (auto stud : data.group.students()) {
                if (stud.namestudent(0).firstname() == name.firstname() &&
                    stud.namestudent(0).midlename() == name.midlename() &&
                    stud.namestudent(0).lastname() == name.lastname()) {
                    return (float)stud.averagemark();
                }
            }
        };
        std::string GetAllInfo(const HW_7::Student_FullName& name) {
            std::string myString;
            for (auto stud : data.group.students()) {
                if (stud.namestudent(0).firstname() == name.firstname() &&
                    stud.namestudent(0).midlename() == name.midlename() &&
                    stud.namestudent(0).lastname() == name.lastname()) {
                    myString += "Name: ";
                    myString += stud.namestudent(0).firstname();
                    myString += ", Last: ";
                    myString += stud.namestudent(0).lastname();
                    myString += ", Score: ";
                    myString += GetAverageScore(stud.namestudent(0));
                }
            }
            return myString;
        };
        std::string GetAllInfo() {
            std::string myString;
            for (auto stud : data.group.students()) {
                myString += GetAllInfo(stud.namestudent(0));
                myString += "\n";
            }
            return myString;
        };
    };

};

int main()
{
    StudentsGroup group_1;
    group_1.addInfo();

    StudentsGroup::IRepository Info1(group_1);
    Info1.Save();

    // для тестирования данных из файла
    StudentsGroup group_2;
    StudentsGroup::IRepository Info2(group_2);
    Info2.Open();

    std::cout << group_2.SerializeAsString();

    // Для тестирования вывода данных
    StudentsGroup group_3;
    StudentsGroup::IRepository Info3(group_3);
    StudentsGroup::IMethods metods(group_3);
    
    HW_7::Student_FullName name_test;
    name_test.set_firstname("First");
    name_test.set_midlename("Midle");
    name_test.set_lastname("Last");
       
    Info3.Open();

    std::cout << metods.GetAverageScore(name_test) << std::endl;

    std::cout << metods.GetAllInfo(name_test) << std::endl << std::endl;
    std::cout << metods.GetAllInfo() << std::endl << std::endl;
    return 0;
}