#include "Session.h"

Session::Session(const int ID, const std::string& surname, type_educ te, const int year, const int max_s, int completed_s, double* grades):
	Student(ID, surname, te, year), max_s(max_s), completed_s(completed_s), grades(grades)
{
}

Session::Session(const Session& other):
	Student(other), max_s(max_s), completed_s(completed_s), grades(grades)
{
}

Session::Session(Session&& other) noexcept:
	Student(std::move(other)), max_s(max_s), completed_s(completed_s), grades(grades)
{
}

Session& Session::operator=(const Session& other)
{
	if (this != &other) {
		Student::operator=(other);
		this->completed_s = other.completed_s;
		this->grades = other.grades;
	}
	return *this;
}

Session& Session::operator=(Session&& other) noexcept
{
	if (this != &other) {
		Student::operator=(std::move(other));
		this->completed_s = other.completed_s;
		this->grades = other.grades;
	}
	return *this;
}

const int Session::GetMax()
{
	return this->max_s;
}

int Session::GetCompleted()
{
	return this->completed_s;
}

double* Session::GetGrades()
{
	return this->grades;
}

void Session::SetCompleted(int completed_s)
{
	this->completed_s = completed_s;
}

std::ostream& operator<<(std::ostream& os, const Session& other)
{
	os << Student(other);
	os << "Maximum number of sessions: " << other.max_s << std::endl;
	os << "The actual number of sessions completed: " << other.completed_s << std::endl;
	return os;
}
