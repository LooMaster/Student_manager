#pragma once

#include<iostream>
#include<cstdint>  //�ַ���(û����)
#include<string>

class Student
{
public:
	int number;               //ѧ�� 
	std::string name;         //����
	int sex;                  //�Ա� (1��0Ů)
	int age;                  //����
	std::string classroom;            //ѧ���༶



	Student();
	Student(int number, std::string name,int sex,int age, std::string classroom);  //���캯��


	//��ͷ ѧ��
	static std::string header_stu();



	//���������� cin>>stu;
	friend std::istream& operator>>(std::istream& is, Student& stu);
	//��������� cout<<stu;
	friend std::ostream& operator<<(std::ostream& os, Student& stu);
};
