#include "Attendance.h"
#include<sstream>   //字符串流（表头）
#include<iomanip>

Attendance::Attendance()
{
}

Attendance::Attendance(int number, std::string name, int date, int classtime, std::string classname, std::string classtype)  //构造函数
	: number(number)
	, name(name)
	, date(date)
	, classtime(classtime)
	, classname(classname)
	, classtype(classtype)
{
}

std::string Attendance::header_att()   //表头 缺课
{
	std::stringstream stream;
	stream.setf(std::ios::left);   //左对齐
	stream << "\n" << std::setw(10) << "学号"
		<< std::setw(12) << "姓名"
		<< std::setw(12) << "缺课日期"
		<< std::setw(12) << "第几节课"
		<< std::setw(12) << "课程名称"
		<< std::setw(12) << "缺课类型";
	return stream.str();

}





std::istream& operator>>(std::istream& is, Attendance& attend)  //重载输入流 is,和Attendance attend的定义
{
	is >> attend.number >> attend.name >> attend.date >> attend.classtime >> attend.classname >> attend.classtype;
	return is;
}

std::ostream& operator<<(std::ostream& os, Attendance& attend)//栏的间隔输出
{
	os.setf(std::ios::left);   //左对齐
	os  << std::setw(10) << attend.number
		<< std::setw(12) << attend.name
		<< std::setw(12) << attend.date 
		<< std::setw(12) << attend.classtime
		<< std::setw(12) << attend.classname
		<< std::setw(12) << attend.classtype;
	return os;
}