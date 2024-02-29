#include "Attendance.h"
#include<sstream>   //�ַ���������ͷ��
#include<iomanip>

Attendance::Attendance()
{
}

Attendance::Attendance(int number, std::string name, int date, int classtime, std::string classname, std::string classtype)  //���캯��
	: number(number)
	, name(name)
	, date(date)
	, classtime(classtime)
	, classname(classname)
	, classtype(classtype)
{
}

std::string Attendance::header_att()   //��ͷ ȱ��
{
	std::stringstream stream;
	stream.setf(std::ios::left);   //�����
	stream << "\n" << std::setw(10) << "ѧ��"
		<< std::setw(12) << "����"
		<< std::setw(12) << "ȱ������"
		<< std::setw(12) << "�ڼ��ڿ�"
		<< std::setw(12) << "�γ�����"
		<< std::setw(12) << "ȱ������";
	return stream.str();

}





std::istream& operator>>(std::istream& is, Attendance& attend)  //���������� is,��Attendance attend�Ķ���
{
	is >> attend.number >> attend.name >> attend.date >> attend.classtime >> attend.classname >> attend.classtype;
	return is;
}

std::ostream& operator<<(std::ostream& os, Attendance& attend)//���ļ�����
{
	os.setf(std::ios::left);   //�����
	os  << std::setw(10) << attend.number
		<< std::setw(12) << attend.name
		<< std::setw(12) << attend.date 
		<< std::setw(12) << attend.classtime
		<< std::setw(12) << attend.classname
		<< std::setw(12) << attend.classtype;
	return os;
}