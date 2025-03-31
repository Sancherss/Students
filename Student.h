#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <iostream>
enum class type_educ{DAYTIME, EVENING, CORRESPONDENCE,DINST_LEARN};
class Student
{
protected:
	const int ID;
	std::string surname;
	type_educ te;
	const int year;
public:
	Student() = delete;
	Student(const int ID, const std::string& surname, type_educ te, const int year);
	Student(const Student& other);
	Student(Student&& other)noexcept;
	Student& operator=(const Student& other);
	Student& operator=(Student&& other)noexcept;

	const int GetID();
	std::string& GetSurname();
	type_educ GetTE();
	const int GetYear();

	void SetSurname(std::string& surname);
	void SetTE(type_educ te);

	bool operator==(const Student& other);
	friend std::ostream& operator<<(std::ostream& os, const Student& other);

	virtual ~Student() = default;
};
#endif

