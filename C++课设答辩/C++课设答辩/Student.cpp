#include "Student.h"
#include<sstream>   //�ַ���������ͷ��
#include<iomanip>

Student::Student()
{
}

Student::Student(int number, std::string name,int sex, int age, std::string classroom)  //���캯��
	:number(number) 
	, name(name)
	, sex(sex)
	, age(age)
	, classroom(classroom)
{
}

std::string Student::header_stu()   //��ͷ ѧ��
{
	std::stringstream stream;
	stream.setf(std::ios::left);   //�����
	stream << "\n"<< std::setw(10) << "ѧ��"
		<< std::setw(16) << "����"
		<< std::setw(10) << "�Ա�"
		<< std::setw(10) << "����"
		<< std::setw(10) << "�༶";
	return stream.str();
	
}


std::istream& operator>>(std::istream& is, Student& stu)   //���������� is,��Student stu�Ķ���
{
	is >> stu.number >> stu.name >> stu.sex >> stu.age >> stu.classroom;
	return is;
}

std::ostream& operator<<(std::ostream& os, Student& stu)//���ļ�����
{
	os.setf(std::ios::left);   //�����
	os  << std::setw(10)<<stu.number
		<< std::setw(16) << stu.name 
		<< std::setw(10) <<( stu.sex?"��":"Ů" )
		<< std::setw(10) << stu.age 
		<< std::setw(10) << stu.classroom;
	return os;
}

