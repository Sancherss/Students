#include "Student.h"
#include "Session.h"
int main() {
    setlocale(LC_ALL, "rus");
    const int ARRAY_SIZE = 5;
    Student* students[ARRAY_SIZE];

    students[0] = new Student(1, "Иванов", type_educ::DAYTIME, 2020);
    students[1] = new Student(2, "Петров", type_educ::EVENING, 2021);
    students[2] = new Student(3, "Сидоров", type_educ::CORRESPONDENCE, 2022);
    double grades1[] = { 4.5, 4.0 };
    students[3] = new Session(4, "Кузнецов", type_educ::DINST_LEARN, 2021, 5, 2, grades1);
    double grades2[] = { 3.5, 4.5, 5.0 };
    students[4] = new Session(5, "Смирнов", type_educ::DAYTIME, 2020, 5, 3, grades2);
	
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        if (dynamic_cast<Session*>(students[i])) {
            std::cout << *dynamic_cast<Session*>(students[i]) << "\n";
        }
        else {
            std::cout << *students[i] << "\n";
        }
    }


    int count_day= 0;
    int count_ev = 0;
    int count_dist = 0;
    int count_cor = 0;
    for (auto sp:students)
    {
        if(static_cast<int>(sp->GetTE()) == 0 ){
            count_day++;
        }
        else if (static_cast<int>(sp->GetTE()) == 1) {
            count_ev++;
        }
        else if (static_cast<int>(sp->GetTE()) == 2) {
            count_cor++;
        }
        else if(static_cast<int>(sp->GetTE()) == 3){
            count_dist++;
        }
    }
    std::cout << "Count of daytime learning: " << count_day << std::endl;
    std::cout << "Count of evening learning: " << count_ev << std::endl;
    std::cout << "Count of correspondence learning: " << count_cor << std::endl;
    std::cout << "Count of distance learning: " << count_dist << std::endl;

    int count_students = 0;
    int count_sessions= 0;
    for (auto sp : students) {
        if (dynamic_cast<Session*>(sp)) {
            count_sessions++;
        }
        else if (dynamic_cast<Student*>(sp)) {
            count_students++;
        }

    }
    std::cout << std::endl;
    std::cout << "Count of students: " << count_students << std::endl;
    std::cout << "Count of sessions: " << count_sessions << std::endl << std::endl;
    std::cout << std::endl << "====================================================" << std::endl << std::endl;
    std::cout << "Enter the year of admission: ";
    int ye;
    std::cin >> ye;
    std::cout << "Students enrolled in " << ye << ": " << std::endl;
    int count = 0;
    for (auto st:students)
    {
        if(dynamic_cast<Student*>(st)){
            if ((st->GetYear()) == ye) {
                std::cout << *st << std::endl;
                count++;
            }
        }
        
    }

    if (count == 0) {
        std::cout << "There are no students enrolled this year" << std::endl;
    }
   
  
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        delete students[i];
    }
   
	return 0;
}