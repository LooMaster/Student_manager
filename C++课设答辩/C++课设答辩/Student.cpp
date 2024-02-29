#include "Student.h"
#include<sstream>   //字符串流（表头）
#include<iomanip>

Student::Student()
{
}

Student::Student(int number, std::string name,int sex, int age, std::string classroom)  //构造函数
	:number(number) 
	, name(name)
	, sex(sex)
	, age(age)
	, classroom(classroom)
{
}

std::string Student::header_stu()   //表头 学生
{
	std::stringstream stream;
	stream.setf(std::ios::left);   //左对齐
	stream << "\n"<< std::setw(10) << "学号"
		<< std::setw(16) << "姓名"
		<< std::setw(10) << "性别"
		<< std::setw(10) << "年龄"
		<< std::setw(10) << "班级";
	return stream.str();
	
}


std::istream& operator>>(std::istream& is, Student& stu)   //重载输入流 is,和Student stu的定义
{
	is >> stu.number >> stu.name >> stu.sex >> stu.age >> stu.classroom;
	return is;
}

std::ostream& operator<<(std::ostream& os, Student& stu)//栏的间隔输出
{
	os.setf(std::ios::left);   //左对齐
	os  << std::setw(10)<<stu.number
		<< std::setw(16) << stu.name 
		<< std::setw(10) <<( stu.sex?"男":"女" )
		<< std::setw(10) << stu.age 
		<< std::setw(10) << stu.classroom;
	return os;
}

