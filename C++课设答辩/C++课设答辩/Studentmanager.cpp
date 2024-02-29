#include "Studentmanager.h"
#include "Student.h"
#include "Attendance.h"
#include<iostream>
#include<algorithm>  
#include<stdio.h>
using namespace std;

Studentmanager::Studentmanager()   //信息储存（容器*2）含m_students与att_students
{
    m_students.emplace_back(new Student(1001, "华为", 1, 18, "华2023"));
    m_students.emplace_back(new Student(1002, "小米", 1, 20, "米2023"));
    m_students.emplace_back(new Student(1003, "大疆", 0, 19, "疆2023"));
	att_students.emplace_back(new Attendance(1004, "大白", 20231227, 1, "C语言", "迟到"));
    att_students.emplace_back(new Attendance(1005, "小黑", 20231201, 3, "线性代数", "旷课"));
    att_students.emplace_back(new Attendance(1006, "小绿", 20230910, 6, "高等数学", "请假"));
    att_students.emplace_back(new Attendance(1007, "大黄", 20230501, 2, "java", "迟到"));
    att_students.emplace_back(new Attendance(1008, "阿旺", 20240101, 5, "生物", "早退"));

}


int Studentmanager::run()
{
	bool isRunning = true;//与Quit构成退出功能

	while (isRunning)//连续跑
	{

		Options op = Options(mainMenu());//共12个可选择功能
		switch (op)
		{
		case Studentmanager::Quit:
			isRunning = false;
			break;
		default:
            std::cout << "【功能数字输入错误】"<<endl;
			break;

        //Student类
		case Studentmanager::SeeAll_s:
			showAll();
			break;
		case Studentmanager::Add_s:
			addStudent();
			break;
		case Studentmanager::Search_s:
			searchStudent();
			break;
		case Studentmanager::Delete_s:  
            deleteStudent();
			break;
        case Studentmanager::Modify_s:
            modifyStudent();
			break;

        //Attendance类
        case Studentmanager::SeeAll_a:
            showAttendance();
            break;
        case Studentmanager::Add_a:
            addAttendance();
            break;
        case Studentmanager::Search_a:
            searchAttendance();
            break;
        case Studentmanager::Delete_a:
            deleteAttendance();
            break;
        case Studentmanager::Modify_a:
            modifyAttendance(); 
            break;
        case Studentmanager::Statistics_a:
            statistics();
            break;

        }
		system("pause");//按任意键继续，不消失
		system("cls");//清屏，防止 主菜单连续出现
	}
	return 0;
}

int Studentmanager::mainMenu()   //主菜单
{
	std::cout << "***********欢迎使用学生考勤管理系统**********" << std::endl;
	std::cout << "*                                           *" << std::endl;
	std::cout << "*********************************************" << std::endl;
	std::cout << "*           输入数字以实现对应功能          *" << std::endl;
	std::cout << "*********************************************" << std::endl;
	std::cout << "*         0-退出系统                        *" << std::endl;
    std::cout << "*                                           *" << std::endl;
    std::cout << "*     学生信息类：                          *" << std::endl;
	std::cout << "*         1-显示所有学生的个人信息          *" << std::endl;
	std::cout << "*         2-添加信息                        *" << std::endl;
	std::cout << "*         3-查找学生信息                    *" << std::endl;
	std::cout << "*         4-删除信息                        *" << std::endl;
	std::cout << "*         5-编辑信息                        *" << std::endl;
    std::cout << "*     缺课记录类：                          *" << std::endl;
    std::cout << "*         6-显示所有缺课记录                *" << std::endl;
    std::cout << "*         7-添加记录                        *" << std::endl;
    std::cout << "*         8-查找缺课记录                    *" << std::endl;
    std::cout << "*         9-删除记录                        *" << std::endl;
    std::cout << "*        10-编辑记录                        *" << std::endl;
    std::cout << "*        11-统计缺课记录                    *" << std::endl;
	std::cout << "*********************************************" << std::endl;
	std::cout << "                                             " << std::endl;
	std::cout << "                                             " << std::endl;

	int op = -1;
	std::cout << "请输入功能对应数字后回车:";
	std::cin >> op;


	return op;
}





//std::vector<Student>::iterator s = m_students.begin(); s != m_students.end(); s++


//   【自定义功能书写区】,并与  ().h 中顺序一致。并在  ().h 的类中声明
              
//Student类函数定义
                                 //显示全部学生记录
              void Studentmanager::showAll()    
              {
                  system("cls");
              	  std::cout << Student::header_stu() << std::endl;   //输出表头
                  
                  for (auto& s : m_students)  //输出学生信息
              	  {
              	  	std::cout << *s << std::endl;
              	  }
              }
              
              //添加学生个人信息
              void Studentmanager::addStudent()  
              {
                  system("cls");
              	  std::cout << "请依次输入学生个人信息: 【学号】 【姓名】 【性别（1男0女）】 【年龄】 【班级】："<<endl;
              	  auto s = new Student;    
              	  std::cin >> *s;
              	  m_students.emplace_back(s);
              }
              
              //查找学生个人信息
              void Studentmanager::searchStudent()
              {
                  system("cls");
              	  int op, flag = -1;
              	  int num = m_students.size();    //统计容器中数据的个数，以便迭代器的使用(没用了)
                 /* cout << num<<endl;*/   //size 容器成员个数 调试成功
              	  int numberpoint;
                  string namepoint;
              	  std::cout << "请输入：<1>按学号查找  <2>按姓名查找"<<endl;
              	  std::cin >> op;
              	  if (op == 1)
              	{
              		std::cout << "请输入该生学号：";
              		std::cin >> numberpoint;
                    for(auto& s : m_students)
              		{
                        //cout << "116" << endl;//调试

                        if ((*s).number == numberpoint)
                        {
                            std::cout << Student::header_stu() << std::endl;   //输出表头

                                std::cout << *s << std::endl;   //打印该生信息
                                flag = 1;
                        }
              		}
              	}

                else if (op == 2)
                {
                    std::cout << "请输入该生姓名：";
                    std::cin >> namepoint;
                    for (auto& s : m_students)
                    {
                        //cout << "911" << endl;//调试

                        if ((*s).name == namepoint)
                        {
                            std::cout << Student::header_stu() << std::endl;   //输出表头

                            std::cout << *s << std::endl;   //打印该生信息
                            flag = 1;
                        }
                    }
                }
                if (flag == -1)
                    std::cout << "【查无此人】" << endl;
                std::cout << "查找结束！";
              }

              //删除学生个人信息
              void Studentmanager::deleteStudent()
              {
                  system("cls");
                  int op, flag = -1;
                  int numberpoint;
                  string namepoint;
                  std::cout << "请选择删除方式：<1>按学号删除  <2>按姓名删除" << endl;
                  std::cin >> op;
                  if (op == 1)
                  {
                      std::cout << "请输入该生学号：";
                      cin >> numberpoint;
                      auto it = std::find_if(m_students.begin(), m_students.end(),
                          [numberpoint](const std::unique_ptr<Student>& s) {
                              return s->number == numberpoint;
                          });

                      if (it != m_students.end()) {
                          std::cout << Student::header_stu() << std::endl;   //输出表头  
                          std::cout << **it << std::endl;   //打印该生信息  
                          std::cout << "是否删除？<1>是   <2>否" << std::endl;

                          int select;
                          std::cin >> select;
                          switch (select) {
                          case 1:
                              m_students.erase(it);
                              std::cout << "删除成功" << std::endl;
                              break;
                          case 2:
                              std::cout << "您未删除" << std::endl;
                              break;
                          default:
                              std::cout << "输入错误，将返回主菜单" << std::endl;
                              break;
                          }
                          flag = 1;
                      }
                  }

                  else if (op == 2)
                  {
                      std::cout << "请输入该生姓名：";
                      cin >> namepoint;
                      auto it = std::find_if(m_students.begin(), m_students.end(),
                          [namepoint](const std::unique_ptr<Student>& s) {
                              return s->name == namepoint;
                          });

                      if (it != m_students.end()) {
                          std::cout << Student::header_stu() << std::endl;   //输出表头  
                          std::cout << **it << std::endl;   //打印该生信息  
                          std::cout << "是否删除？<1>是   <2>否" << std::endl;

                          int select;
                          std::cin >> select;
                          switch (select) {
                          case 1:
                              m_students.erase(it);
                              std::cout << "删除成功" << std::endl;
                              break;
                          case 2:
                              std::cout << "您未删除" << std::endl;
                              break;
                          default:
                              std::cout << "输入错误，将返回主菜单" << std::endl;
                              break;
                          }
                          flag = 1;
                      }
                  }
                  if (flag == -1)
                      std::cout << "【查无此人】" << endl;
                  std::cout << "操作结束！";
              }

              //编辑学生个人信息
              void Studentmanager::modifyStudent()
              {
                  system("cls");
                  int op, flag = -1;
                  int num = m_students.size(); 
                  int numberpoint;
                  string namepoint;
                  std::cout << "请选择编辑方式：<1>按学号查找  <2>按姓名查找" << endl;
                  cin >> op;
                  if (op == 1)
                  {
                      std::cout << "请输入该生学号：";
                      cin >> numberpoint;
                      for (auto& s : m_students)
                      {
                          if ((*s).number == numberpoint)
                          {
                              int select;
                              std::cout << Student::header_stu() << std::endl;   //输出表头

                              std::cout << *s << std::endl;   //打印该生信息
                              std::cout << "已找到该学生，请重新输入该学生的信息:" << endl;
                              int number,sex,age;
                              string name,classroom;
                              cout << "【学号】："; cin >> number;
                              cout << "【姓名】："; cin >> name;
                              cout << "【性别(1男0女)】："; cin >> sex;
                              cout << "【年龄】："; cin >> age;
                              cout << "【班级】："; cin >> classroom;

                              (*s).number = number;
                              (*s).name = name;
                              (*s).sex = sex;
                              (*s).age = age;
                              (*s).classroom = classroom;

                              flag = 1;
                          }
                      }
                  }

                  else if (op == 2)
                  {
                      std::cout << "请输入该生姓名：";
                      cin >> namepoint;
                      for (auto& s : m_students)
                      {

                          if ((*s).name == namepoint)
                          {
                              std::cout << Student::header_stu() << std::endl;   //输出表头

                              std::cout << *s << std::endl;   //打印该生信息
                              std::cout << "已找到该学生，请重新输入该学生的信息:" << endl;
                              int number, sex, age;
                              string name, classroom;
                              cout << "学号:"; cin >> number;
                              cout << "姓名:"; cin >> name;
                              cout << "性别(1男0女):"; cin >> sex;
                              cout << "年龄:"; cin >> age;
                              cout << "班级:"; cin >> classroom;

                              (*s).number = number;
                              (*s).name = name;
                              (*s).sex = sex;
                              (*s).age = age;
                              (*s).classroom = classroom;

                              flag = 1;
                          }
                      }
                  }
                  if (flag == -1)
                      std::cout << "【查无此人】" << endl;
                  std::cout << "更改结束！";
              }

              








//Attendance类函数定义

              //显示所有缺课信息                   
              void Studentmanager::showAttendance()
              {
                  system("cls");
                  std::cout << Attendance::header_att() << std::endl;   //输出表头

                  for (auto& s : att_students)  //输出缺课信息
                  {
                      std::cout << *s << std::endl;
                  }
              }

              //添加缺课信息
              void Studentmanager::addAttendance()
              {
                  system("cls");
                  std::cout << "请依次输入学生缺课记录: "<<endl;
                  std::cout << "【学号】 【姓名】 【缺课日期(如 20230910)】 【第几节课 (数字)】 【课程名称】  【缺课类型 <迟到><早退><请假><旷课> 】"<<endl;
                  auto s = new Attendance;
                  std::cin >> *s;
                  att_students.emplace_back(s);
              }
              
              //查找缺课记录
              void Studentmanager::searchAttendance()
              {
                  system("cls");
                  int op, flag = -1;
                  int numberpoint;
                  string namepoint;
                  std::cout << "请输入：<1>按学号查找  <2>按姓名查找" << endl;
                  cin >> op;
                  if (op == 1)
                  {
                      std::cout << "请输入该生学号：";
                      cin >> numberpoint;
                      for (auto& s : att_students)
                      {
                          //cout << "116" << endl;//调试

                          if ((*s).number == numberpoint)
                          {
                              std::cout << Attendance::header_att() << std::endl;   //输出表头

                              std::cout << *s << std::endl;   //打印该生缺课记录

                              flag = 1;
                          }
                      }
                  }

                  else if (op == 2)
                  {
                      std::cout << "请输入该生姓名：";
                      cin >> namepoint;
                      for (auto& s : att_students)
                      {
                          //cout << "911" << endl;//调试

                          if ((*s).name == namepoint)
                          {
                              std::cout << Attendance::header_att() << std::endl;   //输出表头

                              std::cout << *s << std::endl;   //打印该生信息
                              flag = 1;
                          }
                      }
                  }
                  if (flag == -1)
                      std::cout << "【未找到该生记录】" << endl;
                  std::cout << "查找结束！";
              }

              //删除缺课记录
              void Studentmanager::deleteAttendance()
              {
                  system("cls");
                  int op, flag = -1;
                  int numberpoint;
                  string namepoint;
                  std::cout << "请选择删除方式：<1>按学号删除  <2>按姓名删除" << endl;
                  std::cin >> op;
                  if (op == 1)
                  {
                      std::cout << "请输入该生学号：";
                      cin >> numberpoint;
                      auto it = std::find_if(att_students.begin(), att_students.end(),
                          [numberpoint](const std::unique_ptr<Attendance>& s) {
                              return s->number == numberpoint;
                          });

                      if (it != att_students.end()) {
                          std::cout << Attendance::header_att() << std::endl;   //输出表头  
                          std::cout << **it << std::endl;   //打印该生信息  
                          std::cout << "是否删除？<1>是   <2>否" << std::endl;

                          int select;
                          std::cin >> select;
                          switch (select) {
                          case 1:
                              att_students.erase(it);
                              std::cout << "删除成功" << std::endl;
                              break;
                          case 2:
                              std::cout << "您未删除" << std::endl;
                              break;
                          default:
                              std::cout << "输入错误，将返回主菜单" << std::endl;
                              break;
                          }
                          flag = 1;
                      }
                  }

                  else if (op == 2)
                  {
                      std::cout << "请输入该生姓名：";
                      cin >> namepoint;
                      auto it = std::find_if(att_students.begin(), att_students.end(),
                          [namepoint](const std::unique_ptr<Attendance>& s) {
                              return s->name == namepoint;
                          });

                      if (it != att_students.end()) {
                          std::cout << Attendance::header_att() << std::endl;   //输出表头  
                          std::cout << **it << std::endl;   //打印该生信息  
                          std::cout << "是否删除？<1>是   <2>否" << std::endl;

                          int select;
                          std::cin >> select;
                          switch (select) {
                          case 1:
                              att_students.erase(it);
                              std::cout << "删除成功" << std::endl;
                              break;
                          case 2:
                              std::cout << "您未删除" << std::endl;
                              break;
                          default:
                              std::cout << "输入错误，将返回主菜单" << std::endl;
                              break;
                          }
                          flag = 1;
                      }
                  }
                  if (flag == -1)
                      std::cout << "【查无此人】" << endl;
                  std::cout << "操作结束！";
              }


              //编辑缺课记录

              void Studentmanager::modifyAttendance()
              {
                  system("cls");
                  int op, flag = -1;
                  int numberpoint;
                  string namepoint;
                  std::cout << "请选择编辑方式：<1>按学号查找  <2>按姓名查找" << endl;
                  cin >> op;
                  if (op == 1)
                  {
                      std::cout << "请输入该生学号：";
                      cin >> numberpoint;
                      for (auto& s : att_students)
                      {
                          if ((*s).number == numberpoint)
                          {
                              std::cout << Attendance::header_att() << std::endl;   //输出表头

                              std::cout << *s << std::endl;   //打印该生信息
                              std::cout << "已找到该学生，请重新输入该学生的缺课记录:" << endl;
                              int  date, classtime;
                              string  classname, classtype;
                              cout << "【缺课日期】："; cin >> date;
                              cout << "【第几节课】："; cin >> classtime;
                              cout << "【课程名称】："; cin >> classname;
                              cout << "【缺课类型 <迟到><早退><请假><旷课>】："; cin >> classtype;

                              (*s).date = date;
                              (*s).classtime = classtime;
                              (*s).classname = classname;
                              (*s).classtype = classtype;

                              flag = 1;
                          }
                      }
                  }

                  else if (op == 2)
                  {
                      std::cout << "请输入该生姓名：";
                      cin >> namepoint;
                      for (auto& s : att_students)
                      {

                          if ((*s).name == namepoint)
                          {
                              std::cout << Attendance::header_att() << std::endl;   //输出表头

                              std::cout << *s << std::endl;   //打印该生信息
                              std::cout << "已找到该学生，请重新输入该学生的缺课记录:" << endl;
                              int  date, classtime;
                              string  classname, classtype;
                              cout << "【缺课日期】："; cin >> date;
                              cout << "【第几节课】："; cin >> classtime;
                              cout << "【课程名称】："; cin >> classname;
                              cout << "【缺课类型 <迟到><早退><请假><旷课>】："; cin >> classtype;

                              (*s).date = date;
                              (*s).classtime = classtime;
                              (*s).classname = classname;
                              (*s).classtype = classtype;

                              flag = 1;
                          }
                      }
                  }
                  if (flag == -1)
                      std::cout << "【查无此人】" << endl;
                  std::cout << "更改结束！";
              }

              //统计缺课记录
                    
              void Studentmanager::statistics()
              {
                  system("cls");
                  int flag = -1;
                  int numberpoint;
                  string namepoint;
                  std::cout << "*********************************************" << std::endl;
                  std::cout << "*                 缺课记录统计              *" << std::endl;
                  std::cout << "*********************************************" << std::endl;
                  std::cout << endl;
                  std::cout << "四种缺课记录：“迟到”  “早退”  “请假”  “旷课”" << endl;
                  std::cout << "请输入一种缺课记录类型：";
                  cin >> namepoint;
                  for (auto& s : att_students)
                  {
                      if ((*s).classtype == namepoint)
                      {
                          std::cout << Attendance::header_att() << std::endl;   //输出表头

                          std::cout << *s << std::endl;   //打印该生缺课记录

                          flag = 1;
                      }
                  }

                  if (flag == -1)
                      std::cout << "【输入错误】" << endl;
                  std::cout << "查找结束！";
              }

