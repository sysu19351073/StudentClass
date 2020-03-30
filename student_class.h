#include<iostream>
#include"student.h"
using namespace std;
class StudentClass
{
	static const int maxStudents_ = 20;
	static int StudentCount_;
private:
	string code_;
	Student* student_[maxStudents_];
public:
	StudentClass(string code, Student* student[maxStudents_]);
	StudentClass(const StudentClass& stc);
	~StudentClass() {};
	void Setcode(string code) { code_ = code; };
	string Getcode() { return code_; };
	void SetStudent(Student* student);
	bool AddStudent(const Student* student);
	void ShowStudent(int id) const;
	void ShowStudentsByIdOrder(bool(*compare)(int id, int id_));
	static void showStudentCount() { cout << "Studentcount:\t" << StudentCount_ << endl; };
};

StudentClass::StudentClass(string code, Student* student[maxStudents_])
{
	code_ = code;
	int i;
	for (i = 0;i < maxStudents_;i++)
	{
		student_[i] = student[i];
	}
}

StudentClass::StudentClass(const StudentClass& stc)
{
	int i;
	code_ = stc.code_;
	for (i = 0;i < maxStudents_;i++)
	{
		student_[i] = stc.student_[i];
	};
};

bool StudentClass::AddStudent(const Student* student)
{
	int i;
	bool a = 0;
	for (i = 0;i < maxStudents_;i++)
	{
		if (student_[i]->name_ == student[i].name_)
		{
			a = 1;
			break;
		}
	};
	return a;
};

void StudentClass::SetStudent(Student* student)
{
	int i;
	for (i = 0;i < maxStudents_;i++)
	{
		if (student_[i]->id_ == NULL)
		{
			student_[i] = student;
			break;
		};
	};
};

void StudentClass::ShowStudent(int id) const
{
	int i, j = 0;
	for (i = 0;i < maxStudents_;i++)
	{
		if (student_[i]->id_ == id)
		{
			j = i;
			break;
		}
		cout << student_[j]->name_ << '\t' << student_[j]->id_ << endl;
		cout << student_[j]->courseNames[0] << '\t' << student_[j]->courseNames[1] << '\t' << student_[j]->courseNames[2] << endl;
		cout << student_[j]->grades[0] << '\t' << student_[j]->grades[1] << '\t' << student_[j]->grades[2] << endl;
	};
};

void StudentClass::ShowStudentsByIdOrder(bool(*compare)(int id, int id_))
{

}