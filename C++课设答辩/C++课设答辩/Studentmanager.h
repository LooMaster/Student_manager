#pragma once

#include "Student.h"
#include "Attendance.h" 
#include<vector>   //顺序表  /容器
#include<memory>   //智能指针

class Student;   //配合指针
class Attendance;

class Studentmanager
{
	enum Options//枚举,从0开始
	{
		Quit,

		//Student类
		SeeAll_s,
		Add_s,
		Search_s,
		Delete_s,
		Modify_s,

		//Attendance类
		SeeAll_a,
		Add_a,
		Search_a,
		Delete_a,
		Modify_a,
		Statistics_a,
	};


public:
	Studentmanager();
	//运行学生管理
	int run();


	//【自定义功能区】

	//Student类
              void showAll();      //显示全部个人信息 
              void addStudent();
              void searchStudent();
			  void deleteStudent();
			  void modifyStudent();
	
	//Attendance类
	          void showAttendance();
			  void addAttendance();
			  void searchAttendance();
			  void deleteAttendance();
			  void modifyAttendance();
			  void statistics();

public:
	//主菜单
	static int mainMenu();


private:
	//存储学生信息,m:member
	std::vector<std::unique_ptr<Student>> m_students;   //定义容器 保存的指针会自动释放


	//存储缺课记录 创建第二个容器 
	std::vector<std::unique_ptr<Attendance>> att_students;
};

