#include"Students.h"
using namespace std;


//STUDENT ����:

void Student::insert()//���û�����ѧ�����ݵ�ѧ������δ������У�
{
	cout << "������ѧ����ѧ��: ";
	cin >> StudentID;
	cout << "�ڱ��е����:";
	cin >> Num;
	cout << "����:";
	cin >> Name;
	cout << "�Ա�:";
	cin >> Gender;
	cout << "����:";
	cin >> Birthplace;
	cout << "��������:";
	cin >> Birthday;
	cout << "ѧԺ:";
	cin >> Institute;
	cout << "רҵ:";
	cin >> Major;
	cout << "�༶:";
	cin >> Class;
	cout << "������:";
	cin >> GPA;
	cout << "Ӣ���ļ��ɼ�:";
	cin >> CET4;
	cout << "Ӣ�������ɼ�:";
	cin >> CET6;
	cout << "��ͨ����ѧ������:";
	cin >> Com_MeritStudent_Num;
	cout << "��������ѧ������:";
	cin >> Exl_MeritStudent_Num;
	cout << "����ѧ���ɲ�����:";
	cin >> ExcellentStuCarders_Num;
	cout << "����ɹ�." << endl;
}

Student::Student() //student��Ĺ��캯��
{
	string StudentID="0";
	string Name="xxx";
	string Gender="Secret";
	string Birthplace="China";
	string Birthday="00.0.0";
	string Institute="�Զ�����ѧ�빤��ѧԺ";
	string Major="�Զ���";
	short Num=0;
	short Class=3;
	double GPA=4.0;
	double CET4=1000;
	double CET6=1000;
	short Com_MeritStudent_Num=0;
	short Exl_MeritStudent_Num=0;
	short ExcellentStuCarders_Num=0;
}


Student::~Student()//student����������
{

}

void Student::Show() //��ʾѧ����Ϣ
{
	cout << Name <<"�ڱ��������:"<<Num << "��ѧ����:" << StudentID
		<< "  �Ա�:" << Gender << "  ���᣺" << Birthplace
		<< "  �������ڣ�" << Birthday << "  ѧԺ��" << Institute
		<< "  רҵ��" << Major << "  �༶��" << Class
		<< "  ���㣺" << GPA << "  Ӣ���ļ��ɼ���" << CET4
		<< "  Ӣ�������ɼ�:" << CET6 << "  ����ͨ����ѧ��������" << Com_MeritStudent_Num
		<< "  ����������ѧ��������" << Exl_MeritStudent_Num << "  �������ɲ�������" << ExcellentStuCarders_Num;
}




//student �����Ϣ���ĺ���������ѧ����Ϣ��δ������У�
void Student::change_studentID() {
	cout << "������ĺ��id��";
	cin >> StudentID;
}
void Student::change_name() {
	cout << "������ĺ�����֣�";
	cin >> Name;
}
void Student::change_gender() {
	cout << "������ĺ���Ա�";
	cin >> Gender;
}
void Student::change_birthplace() {
	cout << "������ĺ�ļ��᣺";
	cin >> Birthplace;
}
void Student::change_birthday() {
	cout << "������ĺ�ĳ������ڣ�";
	cin >> Birthday;
}
void Student::change_institute() {
	cout << "������ĺ��ѧԺ��";
	cin >> Institute;
}
void Student::change_major() {
	cout << "������ĺ��רҵ��";
	cin >> Major;
}
void Student::change_class() {
	cout << "������ĺ�İ༶��";
	cin >> Class;
}
void Student::change_gpa() {
	cout << "�����µļ��㣺";
	cin >> GPA;
}
void Student::change_cet4() {
	cout << "�����µ��ļ��ɼ���";
	cin >> CET4;
}
void Student::change_cet6() {
	cout << "�����µ������ɼ���";
	cin >> CET6;
}
void Student::change_com_stu_num() {
	cout << "�����µ� ����ͨ����ѧ��������";
	cin >> Com_MeritStudent_Num;
}
void Student::change_exl_stu_num() {
	cout << "�����µ� ����������ѧ��������";
	cin >> Exl_MeritStudent_Num;
}
void Student::change_exl_carders_num() {
	cout << "�����µ� �������ɲ�������";
	cin >> ExcellentStuCarders_Num;
}






