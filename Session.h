#ifndef SESSION_H
#define SESSION_H
#include "Student.h"
class Session:public Student
{
private:

	const int max_s;
	int completed_s;
	double* grades;

public:

	Session() = delete;
	Session(const int ID, const std::string& surname, type_educ te, const int year, const int max_s, int completed_s, double* grades);
	Session(const Session& other);
	Session(Session&& other)noexcept;
	Session& operator=(const Session& other);
	Session& operator=(Session&& other)noexcept;

	const int GetMax();
	int GetCompleted();
	double* GetGrades();

	void SetCompleted(int completed_s);

	friend std::ostream& operator<<(std::ostream& os, const Session& other);
};
#endif

