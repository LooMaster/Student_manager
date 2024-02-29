#pragma once

#include<iostream>
#include<cstdint>  //字符串(没用了)
#include<string>

class Student
{
public:
	int number;               //学号 
	std::string name;         //姓名
	int sex;                  //性别 (1男0女)
	int age;                  //年龄
	std::string classroom;            //学生班级



	Student();
	Student(int number, std::string name,int sex,int age, std::string classroom);  //构造函数


	//表头 学生
	static std::string header_stu();



	//重载输入流 cin>>stu;
	friend std::istream& operator>>(std::istream& is, Student& stu);
	//重载输出流 cout<<stu;
	friend std::ostream& operator<<(std::ostream& os, Student& stu);
};
