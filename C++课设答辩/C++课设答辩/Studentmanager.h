#pragma once

#include "Student.h"
#include "Attendance.h" 
#include<vector>   //˳���  /����
#include<memory>   //����ָ��

class Student;   //���ָ��
class Attendance;

class Studentmanager
{
	enum Options//ö��,��0��ʼ
	{
		Quit,

		//Student��
		SeeAll_s,
		Add_s,
		Search_s,
		Delete_s,
		Modify_s,

		//Attendance��
		SeeAll_a,
		Add_a,
		Search_a,
		Delete_a,
		Modify_a,
		Statistics_a,
	};


public:
	Studentmanager();
	//����ѧ������
	int run();


	//���Զ��幦������

	//Student��
              void showAll();      //��ʾȫ��������Ϣ 
              void addStudent();
              void searchStudent();
			  void deleteStudent();
			  void modifyStudent();
	
	//Attendance��
	          void showAttendance();
			  void addAttendance();
			  void searchAttendance();
			  void deleteAttendance();
			  void modifyAttendance();
			  void statistics();

public:
	//���˵�
	static int mainMenu();


private:
	//�洢ѧ����Ϣ,m:member
	std::vector<std::unique_ptr<Student>> m_students;   //�������� �����ָ����Զ��ͷ�


	//�洢ȱ�μ�¼ �����ڶ������� 
	std::vector<std::unique_ptr<Attendance>> att_students;
};

