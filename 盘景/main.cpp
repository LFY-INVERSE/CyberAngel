#include"Students.h"


int main()
{
	
    Student stu1,stu2;
	stu1.insert();
	//stu2.insert();
	List list;
	list.add_Stu(stu1);
	/*fun.add_Stu(stu2);
	fun.show();
	fun.del_Stu();
	fun.show();
	fun.change_studentID();
	fun.show();*/
	list.show();
	list.change_studentID();
	list.show();
	system("pause");
	return 0;
}