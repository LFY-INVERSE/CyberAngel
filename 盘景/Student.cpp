#include"Students.h"
using namespace std;


//STUDENT 方法:

void Student::insert()//让用户输入学生数据到学生对象（未存入表中）
{
	cout << "请输入学生的学号: ";
	cin >> StudentID;
	cout << "在表中的序号:";
	cin >> Num;
	cout << "姓名:";
	cin >> Name;
	cout << "性别:";
	cin >> Gender;
	cout << "籍贯:";
	cin >> Birthplace;
	cout << "出生日期:";
	cin >> Birthday;
	cout << "学院:";
	cin >> Institute;
	cout << "专业:";
	cin >> Major;
	cout << "班级:";
	cin >> Class;
	cout << "绩点数:";
	cin >> GPA;
	cout << "英语四级成绩:";
	cin >> CET4;
	cout << "英语六级成绩:";
	cin >> CET6;
	cout << "普通三好学生次数:";
	cin >> Com_MeritStudent_Num;
	cout << "优秀三好学生次数:";
	cin >> Exl_MeritStudent_Num;
	cout << "优秀学生干部次数:";
	cin >> ExcellentStuCarders_Num;
	cout << "输入成功." << endl;
}

Student::Student() //student类的构造函数
{
	string StudentID="0";
	string Name="xxx";
	string Gender="Secret";
	string Birthplace="China";
	string Birthday="00.0.0";
	string Institute="自动化科学与工程学院";
	string Major="自动化";
	short Num=0;
	short Class=3;
	double GPA=4.0;
	double CET4=1000;
	double CET6=1000;
	short Com_MeritStudent_Num=0;
	short Exl_MeritStudent_Num=0;
	short ExcellentStuCarders_Num=0;
}


Student::~Student()//student类析构函数
{

}

void Student::Show() //显示学生信息
{
	cout << Name <<"在表中序号是:"<<Num << "的学号是:" << StudentID
		<< "  性别:" << Gender << "  籍贯：" << Birthplace
		<< "  出生日期：" << Birthday << "  学院：" << Institute
		<< "  专业：" << Major << "  班级：" << Class
		<< "  绩点：" << GPA << "  英语四级成绩：" << CET4
		<< "  英语六级成绩:" << CET6 << "  获普通三好学生次数：" << Com_MeritStudent_Num
		<< "  获优秀三好学生次数：" << Exl_MeritStudent_Num << "  获优秀班干部次数：" << ExcellentStuCarders_Num;
}




//student 类的信息更改函数：更改学生信息（未存入表中）
void Student::change_studentID() {
	cout << "输入更改后的id：";
	cin >> StudentID;
}
void Student::change_name() {
	cout << "输入更改后的名字：";
	cin >> Name;
}
void Student::change_gender() {
	cout << "输入更改后的性别：";
	cin >> Gender;
}
void Student::change_birthplace() {
	cout << "输入更改后的籍贯：";
	cin >> Birthplace;
}
void Student::change_birthday() {
	cout << "输入更改后的出生日期：";
	cin >> Birthday;
}
void Student::change_institute() {
	cout << "输入更改后的学院：";
	cin >> Institute;
}
void Student::change_major() {
	cout << "输入更改后的专业：";
	cin >> Major;
}
void Student::change_class() {
	cout << "输入更改后的班级：";
	cin >> Class;
}
void Student::change_gpa() {
	cout << "输入新的绩点：";
	cin >> GPA;
}
void Student::change_cet4() {
	cout << "输入新的四级成绩：";
	cin >> CET4;
}
void Student::change_cet6() {
	cout << "输入新的六级成绩：";
	cin >> CET6;
}
void Student::change_com_stu_num() {
	cout << "输入新的 获普通三好学生次数：";
	cin >> Com_MeritStudent_Num;
}
void Student::change_exl_stu_num() {
	cout << "输入新的 获优秀三好学生次数：";
	cin >> Exl_MeritStudent_Num;
}
void Student::change_exl_carders_num() {
	cout << "输入新的 获优秀班干部次数：";
	cin >> ExcellentStuCarders_Num;
}






