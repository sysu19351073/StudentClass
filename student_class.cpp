#include<iostream>
#include"student_class.h"
#include"student.h"
using namespace std;

int student_class()
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
	Student std[20] = { std1,std2,std3 };
	string code = "577866";
	StudentClass stdc(code, std);

}
