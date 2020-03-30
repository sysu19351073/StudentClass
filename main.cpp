#include<iostream>
#include"student.h"
#include"student_class.h"
using namespace std;

int student()
{
	string coursename[3] = { "Robotics","C++","Math" };
	double grade1[3] = { 100.0,99.9,98.8 };
	double grade2[3] = { 99.9,100.0,98.8 };
	double grade3[3] = { 99.9,98.8,100.0 };
	string name1 = "Bob";
	string name2 = "John";
	string name3 = "Alice";
	Student std1(101, name1, coursename, grade1);
	Student std2(102, name2, coursename, grade2);
	Student std3(103, name3, coursename, grade3);
	string course = "C++";
	double grade = 99.0;
	std1.SetGrade(course, grade);
	double grade0 = std1.GetGrade(course);
	cout << "Bob\'s" << course << ':\t' << grade0 << endl;
	double avergrade = std1.GetAverageGrade();
	cout << "Bob\'s AverageGrade :" << avergrade << endl;
	std1.ShowGrades();
	int id1 = std1.Getid();
	cout << name1 << ":\t" << id1 << endl;
	string name0 = std1.GetName();
	cout << name0 << ":\t" << id1 << endl;
	return 0;
}