#pragma once

#include<iostream>
#include<cstdint>  //�ַ���(û����)
#include<string>


class Attendance
{
	public:
		int number;               //ѧ�� 
		std::string name;         //����
		int date;         //ȱ������
		int classtime;    //�ڼ��ڿ�
		std::string classname;    //�γ�����
		std::string classtype;    //ȱ�����ͣ����֣��ٵ������ˣ���٣����Σ�
		 

		Attendance();
		Attendance(int number, std::string name, int date, int classtime, std::string classname, std::string classtype);  //���캯��


		//��ͷ ȱ��
		static std::string header_att();





		//���������� cin>>stu;
		friend std::istream& operator>>(std::istream& is, Attendance& attend);
		//��������� cout<<stu;
		friend std::ostream& operator<<(std::ostream& os, Attendance& attend);
	

};

