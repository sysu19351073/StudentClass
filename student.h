#include<iostream>
#include<stdio.h>
using namespace std;
class Student
{
	static const int maxCourses_ = 3;
	friend class StudentClass;
private:
	int id_;
	string name_;
	string courseNames[maxCourses_];
	double grades[maxCourses_];
public:
	Student(int id, string name, string coursenam[3], double grade[3]);
	Student(const Student& st);
	~Student() {};
	bool AddCourse(const string& courseName, double &grade);
	void SetGrade(string& courseName, double& grade);
	double GetGrade(string courseName) const;
	double GetAverageGrade()const;
	void ShowGrades() const;
	void Setid(int id) {id_ = id;};
	int Getid() const { return id_; };
	void SetName(string name) { name_ = name; };
	string GetName() const { return name_; };
	void operator=(const Student& std)
	{
		int i;
		id_ = std.id_;
		name_ = std.name_;
		for (i = 0;i < 3;i++)
		{
			courseNames[i] = std.courseNames[i];
			grades[i] = std.grades[i];
		};
	};
};

Student::Student(int id, string name, string coursenam[3], double grade[3]) 
{
	int i;
	id_ = id;
	name_ = name;
	for (i = 0;i < 3;i++)
	{
		courseNames[i] = coursenam[i];
		grades[i] = grade[i];
	};
};

Student::Student(const Student& st) :
	id_(st.id_), name_(st.name_), 
	courseNames{st.courseNames[0],st.courseNames[1],st.courseNames[2]}, 
	grades{ st.grades[0],st.grades[1],st.grades[2] } {};

void Student::SetGrade(string& courseName, double& grade)
{
	int i,j=0;
	for (i = 0;i < 3;i++)
	{
		if (courseNames[i] == courseName)
		{
			j = i;
			grades[j] = grade;
			break;
		};
	};
	
};

double Student::GetGrade(string courseName) const
{
	int i, j;
	for (i = 0;i < 3;i++)
	{
		if (courseNames[i] == courseName)
			j = i;
	}
	return grades[j];

};

double Student::GetAverageGrade() const
{
	int i;
	double sum = 0, a;
	for (i = 0;i < 3; i++)
	{
		sum += grades[i];
	};
	a = sum / 3;
	return a;
};

void Student::ShowGrades() const
{
	int i;
	for (i = 0;i < 3;i++)
	{
		cout <<name_<<'\t'<< courseNames[i] << ':\t' << grades[i] << endl;
	};
};

bool Student::AddCourse(const string& courseName, double& grade)
{
	bool a = 0;
	int i, j;
	for (i = 0;i < 3;i++)
	{
		if (grades[i] == NULL)
		{
			j = i;
			courseNames[j] = courseName;
			grades[j] = grade;
			a = 1;
			break;
		};
	};
	return a;
}