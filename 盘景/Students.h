#ifndef STUDENTSH
#define STUDENTSH


#include<iostream>
#include<ctime>
#include<string>
#include<cctype>
#include<cstdlib>
#include<cstring>

class Student
{
private:
	std::string StudentID;
	std::string Name;
	std::string Gender;
	std::string Birthplace; 
	std::string Birthday;
	std::string Institute;
	std::string Major;
	short Num;
    short Class;
	double GPA;
	double CET4;
	double CET6;
	short Com_MeritStudent_Num;
	short Exl_MeritStudent_Num;
	short ExcellentStuCarders_Num;
  
public:
	
	Student();
	~Student();
	short get_Num()
	{
		return Num;
	}
	void change_Num()
	{
		Num--;
	}
	void insert();
	
	void change_studentID();
	void change_name();
	void change_gender();
	void change_birthplace();
	void change_birthday();
	void change_institute();
	void change_major();
	void change_class();
	void change_gpa();
	void change_cet4();
	void change_cet6();
	void change_com_stu_num();
	void change_exl_stu_num();
	void change_exl_carders_num();
	
	
	void Show();
};



class List
{
private:
	struct Node
	{
		Student stu;
		struct Node* next;
	};
	
	int nsize; //const????
	Node* start;
	Node* end;
	int stu_num;

	

public:
	List();
	List(int n_size);
	~List();
	bool show();
	bool is_empty()const;
	bool is_full()const;
	//void set_qisize(int n) { nsize = n; }
	bool add_Stu(const Student& stu);//add student to the end
	bool del_Stu();//delete student from the start
	bool change_studentID();
	bool change_name();
	bool change_gender();
	bool change_birthplace();
	bool change_birthday();
	bool change_institute();
	bool change_major();
	bool change_class();
	bool change_gpa();
	bool change_cet4();
	bool change_cet6();
	bool change_com_stu_num();
	bool change_exl_stu_num();
	bool change_exl_carders_num();
	bool Show();
};




#endif
