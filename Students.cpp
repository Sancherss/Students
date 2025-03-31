#include "Student.h"

Student::Student(const int ID, const std::string& surname, type_educ te, const int year):
	ID(ID), surname(surname), te(te), year(year)
{}

Student::Student(const Student & other):ID(other.ID), surname(other.surname), te(other.te), year(other.year)
{
}

Student::Student(Student&& other) noexcept:
	ID(other.ID), surname(std::move(other.surname)), te(other.te), year(other.year)
{
}

Student& Student::operator=(const Student& other)
{
	if (this != &other) {
		this->surname = other.surname;
		this->te = other.te;
	}
	return *this;
}

Student& Student::operator=(Student&& other) noexcept
{
	if (this != &other) {
		this->surname = std::move(other.surname);
		this->te = other.te;
	}
	return *this;
}

const int Student::GetID()
{
	return this->ID;
}

std::string& Student::GetSurname()
{
	return this->surname;
}

type_educ Student::GetTE()
{
	return this->te;
}

const int Student::GetYear()
{
	return this->year;
}

void Student::SetSurname(std::string& surname)
{
	this->surname = surname;
}

void Student::SetTE(type_educ te)
{
	this->te = te;
}

bool Student::operator==(const Student& other)
{
	return this->te== other.te;
}

std::ostream& operator<<(std::ostream& os, const Student& other)
{
	os << "ID: " << other.ID << std::endl;
	os << "Surname: " << other.surname << std::endl;
	os << "Type of learning: ";
	switch (static_cast<int>(other.te)) {
	case 1:os << "DAYTIME"; break;
	case 2:os << "EVENING"; break;
	case 3:os << "CORRESPONDENCE"; break;
	case 4:os << "Distance education"; break;
	}
	os << std::endl;
	os << "Year of admission: " << other.year << std::endl;
	return os;

}
