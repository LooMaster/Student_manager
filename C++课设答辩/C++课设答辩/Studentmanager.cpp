#include "Studentmanager.h"
#include "Student.h"
#include "Attendance.h"
#include<iostream>
#include<algorithm>  
#include<stdio.h>
using namespace std;

Studentmanager::Studentmanager()   //��Ϣ���棨����*2����m_students��att_students
{
    m_students.emplace_back(new Student(1001, "��Ϊ", 1, 18, "��2023"));
    m_students.emplace_back(new Student(1002, "С��", 1, 20, "��2023"));
    m_students.emplace_back(new Student(1003, "��", 0, 19, "��2023"));
	att_students.emplace_back(new Attendance(1004, "���", 20231227, 1, "C����", "�ٵ�"));
    att_students.emplace_back(new Attendance(1005, "С��", 20231201, 3, "���Դ���", "����"));
    att_students.emplace_back(new Attendance(1006, "С��", 20230910, 6, "�ߵ���ѧ", "���"));
    att_students.emplace_back(new Attendance(1007, "���", 20230501, 2, "java", "�ٵ�"));
    att_students.emplace_back(new Attendance(1008, "����", 20240101, 5, "����", "����"));

}


int Studentmanager::run()
{
	bool isRunning = true;//��Quit�����˳�����

	while (isRunning)//������
	{

		Options op = Options(mainMenu());//��12����ѡ����
		switch (op)
		{
		case Studentmanager::Quit:
			isRunning = false;
			break;
		default:
            std::cout << "�����������������"<<endl;
			break;

        //Student��
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

        //Attendance��
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
		system("pause");//�����������������ʧ
		system("cls");//��������ֹ ���˵���������
	}
	return 0;
}

int Studentmanager::mainMenu()   //���˵�
{
	std::cout << "***********��ӭʹ��ѧ�����ڹ���ϵͳ**********" << std::endl;
	std::cout << "*                                           *" << std::endl;
	std::cout << "*********************************************" << std::endl;
	std::cout << "*           ����������ʵ�ֶ�Ӧ����          *" << std::endl;
	std::cout << "*********************************************" << std::endl;
	std::cout << "*         0-�˳�ϵͳ                        *" << std::endl;
    std::cout << "*                                           *" << std::endl;
    std::cout << "*     ѧ����Ϣ�ࣺ                          *" << std::endl;
	std::cout << "*         1-��ʾ����ѧ���ĸ�����Ϣ          *" << std::endl;
	std::cout << "*         2-�����Ϣ                        *" << std::endl;
	std::cout << "*         3-����ѧ����Ϣ                    *" << std::endl;
	std::cout << "*         4-ɾ����Ϣ                        *" << std::endl;
	std::cout << "*         5-�༭��Ϣ                        *" << std::endl;
    std::cout << "*     ȱ�μ�¼�ࣺ                          *" << std::endl;
    std::cout << "*         6-��ʾ����ȱ�μ�¼                *" << std::endl;
    std::cout << "*         7-��Ӽ�¼                        *" << std::endl;
    std::cout << "*         8-����ȱ�μ�¼                    *" << std::endl;
    std::cout << "*         9-ɾ����¼                        *" << std::endl;
    std::cout << "*        10-�༭��¼                        *" << std::endl;
    std::cout << "*        11-ͳ��ȱ�μ�¼                    *" << std::endl;
	std::cout << "*********************************************" << std::endl;
	std::cout << "                                             " << std::endl;
	std::cout << "                                             " << std::endl;

	int op = -1;
	std::cout << "�����빦�ܶ�Ӧ���ֺ�س�:";
	std::cin >> op;


	return op;
}





//std::vector<Student>::iterator s = m_students.begin(); s != m_students.end(); s++


//   ���Զ��幦����д����,����  ().h ��˳��һ�¡�����  ().h ����������
              
//Student�ຯ������
                                 //��ʾȫ��ѧ����¼
              void Studentmanager::showAll()    
              {
                  system("cls");
              	  std::cout << Student::header_stu() << std::endl;   //�����ͷ
                  
                  for (auto& s : m_students)  //���ѧ����Ϣ
              	  {
              	  	std::cout << *s << std::endl;
              	  }
              }
              
              //���ѧ��������Ϣ
              void Studentmanager::addStudent()  
              {
                  system("cls");
              	  std::cout << "����������ѧ��������Ϣ: ��ѧ�š� �������� ���Ա�1��0Ů���� �����䡿 ���༶����"<<endl;
              	  auto s = new Student;    
              	  std::cin >> *s;
              	  m_students.emplace_back(s);
              }
              
              //����ѧ��������Ϣ
              void Studentmanager::searchStudent()
              {
                  system("cls");
              	  int op, flag = -1;
              	  int num = m_students.size();    //ͳ�����������ݵĸ������Ա��������ʹ��(û����)
                 /* cout << num<<endl;*/   //size ������Ա���� ���Գɹ�
              	  int numberpoint;
                  string namepoint;
              	  std::cout << "�����룺<1>��ѧ�Ų���  <2>����������"<<endl;
              	  std::cin >> op;
              	  if (op == 1)
              	{
              		std::cout << "���������ѧ�ţ�";
              		std::cin >> numberpoint;
                    for(auto& s : m_students)
              		{
                        //cout << "116" << endl;//����

                        if ((*s).number == numberpoint)
                        {
                            std::cout << Student::header_stu() << std::endl;   //�����ͷ

                                std::cout << *s << std::endl;   //��ӡ������Ϣ
                                flag = 1;
                        }
              		}
              	}

                else if (op == 2)
                {
                    std::cout << "���������������";
                    std::cin >> namepoint;
                    for (auto& s : m_students)
                    {
                        //cout << "911" << endl;//����

                        if ((*s).name == namepoint)
                        {
                            std::cout << Student::header_stu() << std::endl;   //�����ͷ

                            std::cout << *s << std::endl;   //��ӡ������Ϣ
                            flag = 1;
                        }
                    }
                }
                if (flag == -1)
                    std::cout << "�����޴��ˡ�" << endl;
                std::cout << "���ҽ�����";
              }

              //ɾ��ѧ��������Ϣ
              void Studentmanager::deleteStudent()
              {
                  system("cls");
                  int op, flag = -1;
                  int numberpoint;
                  string namepoint;
                  std::cout << "��ѡ��ɾ����ʽ��<1>��ѧ��ɾ��  <2>������ɾ��" << endl;
                  std::cin >> op;
                  if (op == 1)
                  {
                      std::cout << "���������ѧ�ţ�";
                      cin >> numberpoint;
                      auto it = std::find_if(m_students.begin(), m_students.end(),
                          [numberpoint](const std::unique_ptr<Student>& s) {
                              return s->number == numberpoint;
                          });

                      if (it != m_students.end()) {
                          std::cout << Student::header_stu() << std::endl;   //�����ͷ  
                          std::cout << **it << std::endl;   //��ӡ������Ϣ  
                          std::cout << "�Ƿ�ɾ����<1>��   <2>��" << std::endl;

                          int select;
                          std::cin >> select;
                          switch (select) {
                          case 1:
                              m_students.erase(it);
                              std::cout << "ɾ���ɹ�" << std::endl;
                              break;
                          case 2:
                              std::cout << "��δɾ��" << std::endl;
                              break;
                          default:
                              std::cout << "������󣬽��������˵�" << std::endl;
                              break;
                          }
                          flag = 1;
                      }
                  }

                  else if (op == 2)
                  {
                      std::cout << "���������������";
                      cin >> namepoint;
                      auto it = std::find_if(m_students.begin(), m_students.end(),
                          [namepoint](const std::unique_ptr<Student>& s) {
                              return s->name == namepoint;
                          });

                      if (it != m_students.end()) {
                          std::cout << Student::header_stu() << std::endl;   //�����ͷ  
                          std::cout << **it << std::endl;   //��ӡ������Ϣ  
                          std::cout << "�Ƿ�ɾ����<1>��   <2>��" << std::endl;

                          int select;
                          std::cin >> select;
                          switch (select) {
                          case 1:
                              m_students.erase(it);
                              std::cout << "ɾ���ɹ�" << std::endl;
                              break;
                          case 2:
                              std::cout << "��δɾ��" << std::endl;
                              break;
                          default:
                              std::cout << "������󣬽��������˵�" << std::endl;
                              break;
                          }
                          flag = 1;
                      }
                  }
                  if (flag == -1)
                      std::cout << "�����޴��ˡ�" << endl;
                  std::cout << "����������";
              }

              //�༭ѧ��������Ϣ
              void Studentmanager::modifyStudent()
              {
                  system("cls");
                  int op, flag = -1;
                  int num = m_students.size(); 
                  int numberpoint;
                  string namepoint;
                  std::cout << "��ѡ��༭��ʽ��<1>��ѧ�Ų���  <2>����������" << endl;
                  cin >> op;
                  if (op == 1)
                  {
                      std::cout << "���������ѧ�ţ�";
                      cin >> numberpoint;
                      for (auto& s : m_students)
                      {
                          if ((*s).number == numberpoint)
                          {
                              int select;
                              std::cout << Student::header_stu() << std::endl;   //�����ͷ

                              std::cout << *s << std::endl;   //��ӡ������Ϣ
                              std::cout << "���ҵ���ѧ���������������ѧ������Ϣ:" << endl;
                              int number,sex,age;
                              string name,classroom;
                              cout << "��ѧ�š���"; cin >> number;
                              cout << "����������"; cin >> name;
                              cout << "���Ա�(1��0Ů)����"; cin >> sex;
                              cout << "�����䡿��"; cin >> age;
                              cout << "���༶����"; cin >> classroom;

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
                      std::cout << "���������������";
                      cin >> namepoint;
                      for (auto& s : m_students)
                      {

                          if ((*s).name == namepoint)
                          {
                              std::cout << Student::header_stu() << std::endl;   //�����ͷ

                              std::cout << *s << std::endl;   //��ӡ������Ϣ
                              std::cout << "���ҵ���ѧ���������������ѧ������Ϣ:" << endl;
                              int number, sex, age;
                              string name, classroom;
                              cout << "ѧ��:"; cin >> number;
                              cout << "����:"; cin >> name;
                              cout << "�Ա�(1��0Ů):"; cin >> sex;
                              cout << "����:"; cin >> age;
                              cout << "�༶:"; cin >> classroom;

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
                      std::cout << "�����޴��ˡ�" << endl;
                  std::cout << "���Ľ�����";
              }

              








//Attendance�ຯ������

              //��ʾ����ȱ����Ϣ                   
              void Studentmanager::showAttendance()
              {
                  system("cls");
                  std::cout << Attendance::header_att() << std::endl;   //�����ͷ

                  for (auto& s : att_students)  //���ȱ����Ϣ
                  {
                      std::cout << *s << std::endl;
                  }
              }

              //���ȱ����Ϣ
              void Studentmanager::addAttendance()
              {
                  system("cls");
                  std::cout << "����������ѧ��ȱ�μ�¼: "<<endl;
                  std::cout << "��ѧ�š� �������� ��ȱ������(�� 20230910)�� ���ڼ��ڿ� (����)�� ���γ����ơ�  ��ȱ������ <�ٵ�><����><���><����> ��"<<endl;
                  auto s = new Attendance;
                  std::cin >> *s;
                  att_students.emplace_back(s);
              }
              
              //����ȱ�μ�¼
              void Studentmanager::searchAttendance()
              {
                  system("cls");
                  int op, flag = -1;
                  int numberpoint;
                  string namepoint;
                  std::cout << "�����룺<1>��ѧ�Ų���  <2>����������" << endl;
                  cin >> op;
                  if (op == 1)
                  {
                      std::cout << "���������ѧ�ţ�";
                      cin >> numberpoint;
                      for (auto& s : att_students)
                      {
                          //cout << "116" << endl;//����

                          if ((*s).number == numberpoint)
                          {
                              std::cout << Attendance::header_att() << std::endl;   //�����ͷ

                              std::cout << *s << std::endl;   //��ӡ����ȱ�μ�¼

                              flag = 1;
                          }
                      }
                  }

                  else if (op == 2)
                  {
                      std::cout << "���������������";
                      cin >> namepoint;
                      for (auto& s : att_students)
                      {
                          //cout << "911" << endl;//����

                          if ((*s).name == namepoint)
                          {
                              std::cout << Attendance::header_att() << std::endl;   //�����ͷ

                              std::cout << *s << std::endl;   //��ӡ������Ϣ
                              flag = 1;
                          }
                      }
                  }
                  if (flag == -1)
                      std::cout << "��δ�ҵ�������¼��" << endl;
                  std::cout << "���ҽ�����";
              }

              //ɾ��ȱ�μ�¼
              void Studentmanager::deleteAttendance()
              {
                  system("cls");
                  int op, flag = -1;
                  int numberpoint;
                  string namepoint;
                  std::cout << "��ѡ��ɾ����ʽ��<1>��ѧ��ɾ��  <2>������ɾ��" << endl;
                  std::cin >> op;
                  if (op == 1)
                  {
                      std::cout << "���������ѧ�ţ�";
                      cin >> numberpoint;
                      auto it = std::find_if(att_students.begin(), att_students.end(),
                          [numberpoint](const std::unique_ptr<Attendance>& s) {
                              return s->number == numberpoint;
                          });

                      if (it != att_students.end()) {
                          std::cout << Attendance::header_att() << std::endl;   //�����ͷ  
                          std::cout << **it << std::endl;   //��ӡ������Ϣ  
                          std::cout << "�Ƿ�ɾ����<1>��   <2>��" << std::endl;

                          int select;
                          std::cin >> select;
                          switch (select) {
                          case 1:
                              att_students.erase(it);
                              std::cout << "ɾ���ɹ�" << std::endl;
                              break;
                          case 2:
                              std::cout << "��δɾ��" << std::endl;
                              break;
                          default:
                              std::cout << "������󣬽��������˵�" << std::endl;
                              break;
                          }
                          flag = 1;
                      }
                  }

                  else if (op == 2)
                  {
                      std::cout << "���������������";
                      cin >> namepoint;
                      auto it = std::find_if(att_students.begin(), att_students.end(),
                          [namepoint](const std::unique_ptr<Attendance>& s) {
                              return s->name == namepoint;
                          });

                      if (it != att_students.end()) {
                          std::cout << Attendance::header_att() << std::endl;   //�����ͷ  
                          std::cout << **it << std::endl;   //��ӡ������Ϣ  
                          std::cout << "�Ƿ�ɾ����<1>��   <2>��" << std::endl;

                          int select;
                          std::cin >> select;
                          switch (select) {
                          case 1:
                              att_students.erase(it);
                              std::cout << "ɾ���ɹ�" << std::endl;
                              break;
                          case 2:
                              std::cout << "��δɾ��" << std::endl;
                              break;
                          default:
                              std::cout << "������󣬽��������˵�" << std::endl;
                              break;
                          }
                          flag = 1;
                      }
                  }
                  if (flag == -1)
                      std::cout << "�����޴��ˡ�" << endl;
                  std::cout << "����������";
              }


              //�༭ȱ�μ�¼

              void Studentmanager::modifyAttendance()
              {
                  system("cls");
                  int op, flag = -1;
                  int numberpoint;
                  string namepoint;
                  std::cout << "��ѡ��༭��ʽ��<1>��ѧ�Ų���  <2>����������" << endl;
                  cin >> op;
                  if (op == 1)
                  {
                      std::cout << "���������ѧ�ţ�";
                      cin >> numberpoint;
                      for (auto& s : att_students)
                      {
                          if ((*s).number == numberpoint)
                          {
                              std::cout << Attendance::header_att() << std::endl;   //�����ͷ

                              std::cout << *s << std::endl;   //��ӡ������Ϣ
                              std::cout << "���ҵ���ѧ���������������ѧ����ȱ�μ�¼:" << endl;
                              int  date, classtime;
                              string  classname, classtype;
                              cout << "��ȱ�����ڡ���"; cin >> date;
                              cout << "���ڼ��ڿΡ���"; cin >> classtime;
                              cout << "���γ����ơ���"; cin >> classname;
                              cout << "��ȱ������ <�ٵ�><����><���><����>����"; cin >> classtype;

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
                      std::cout << "���������������";
                      cin >> namepoint;
                      for (auto& s : att_students)
                      {

                          if ((*s).name == namepoint)
                          {
                              std::cout << Attendance::header_att() << std::endl;   //�����ͷ

                              std::cout << *s << std::endl;   //��ӡ������Ϣ
                              std::cout << "���ҵ���ѧ���������������ѧ����ȱ�μ�¼:" << endl;
                              int  date, classtime;
                              string  classname, classtype;
                              cout << "��ȱ�����ڡ���"; cin >> date;
                              cout << "���ڼ��ڿΡ���"; cin >> classtime;
                              cout << "���γ����ơ���"; cin >> classname;
                              cout << "��ȱ������ <�ٵ�><����><���><����>����"; cin >> classtype;

                              (*s).date = date;
                              (*s).classtime = classtime;
                              (*s).classname = classname;
                              (*s).classtype = classtype;

                              flag = 1;
                          }
                      }
                  }
                  if (flag == -1)
                      std::cout << "�����޴��ˡ�" << endl;
                  std::cout << "���Ľ�����";
              }

              //ͳ��ȱ�μ�¼
                    
              void Studentmanager::statistics()
              {
                  system("cls");
                  int flag = -1;
                  int numberpoint;
                  string namepoint;
                  std::cout << "*********************************************" << std::endl;
                  std::cout << "*                 ȱ�μ�¼ͳ��              *" << std::endl;
                  std::cout << "*********************************************" << std::endl;
                  std::cout << endl;
                  std::cout << "����ȱ�μ�¼�����ٵ���  �����ˡ�  ����١�  �����Ρ�" << endl;
                  std::cout << "������һ��ȱ�μ�¼���ͣ�";
                  cin >> namepoint;
                  for (auto& s : att_students)
                  {
                      if ((*s).classtype == namepoint)
                      {
                          std::cout << Attendance::header_att() << std::endl;   //�����ͷ

                          std::cout << *s << std::endl;   //��ӡ����ȱ�μ�¼

                          flag = 1;
                      }
                  }

                  if (flag == -1)
                      std::cout << "���������" << endl;
                  std::cout << "���ҽ�����";
              }

