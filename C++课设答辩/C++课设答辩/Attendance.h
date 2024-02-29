#pragma once

#include<iostream>
#include<cstdint>  //字符串(没用了)
#include<string>


class Attendance
{
	public:
		int number;               //学号 
		std::string name;         //姓名
		int date;         //缺课日期
		int classtime;    //第几节课
		std::string classname;    //课程名称
		std::string classtype;    //缺课类型（四种：迟到，早退，请假，旷课）
		 

		Attendance();
		Attendance(int number, std::string name, int date, int classtime, std::string classname, std::string classtype);  //构造函数


		//表头 缺勤
		static std::string header_att();





		//重载输入流 cin>>stu;
		friend std::istream& operator>>(std::istream& is, Attendance& attend);
		//重载输出流 cout<<stu;
		friend std::ostream& operator<<(std::ostream& os, Attendance& attend);
	

};

