#include"Students.h"

using namespace std;

//List方法 （链表形式）



List::List() {//List类构造函数
	nsize = 20;//
	start = end = NULL;
	stu_num = 0;
}




List::List(int n_size = 20) //List类构造函数
{
	nsize = n_size;//
	start = end = NULL;
	stu_num = 0;
}



List::~List() //List类析造函数
{
	Node* temp;
	while (start != NULL)
	{
		temp = start;
		start = start->next;
		delete temp;
	}
}

//显示存入表中的学生信息
bool List::show()
{
	Node* temp = start;
	if (is_empty())
	{
		cout << "学生列表为0.\n";
		return true;
	}
	while (temp->next != NULL)
	{
		temp->stu.Show();
		temp = temp->next;
	}
	end->stu.Show();
	cout << "显示完毕.\n";
	return true;
}

//表中是否为空
bool List::is_empty()const {
	return stu_num == 0;
}



//表是否满了
bool List::is_full()const {
	return stu_num == nsize;
}



//在表中增加学生信息
bool List::add_Stu(const Student& stu) {
	if (is_full())
	{
		cout << "人数已满，无法录入" << endl;
		return false;
	}
	Node* add = new Node;
	add->stu = stu;
	add->next = NULL;
	stu_num++;
	if (start == NULL)
	{
		start = add;
	}
	else
	{
		end->next = add;
	}
	end = add;
	return true;
}



//在表中删除学生信息
bool List::del_Stu() {
	short num;
	cout << "请输入要删除学生的序号";//根据输入序号确认谁要被删
	cin >> num;
	if (is_empty())//空链表情况
	{
		cout << "学生列表为空,删除失败." << endl;
		return false;
	}

	if (start->stu.get_Num() == num)//要删的是头节点的情况
	{
		Node* temp0 = start->next;
		Node* temp = start;
		start = start->next;
		delete temp;
		start->stu.change_Num();
		while (temp0->next != NULL)
		{
			start->next->stu.change_Num();//改变被删除学生之后的学生的序号

		}
		cout << "删除成功." << endl;
		return true;
	}
	//删除的是中间或末尾节点的情况
	Node* cur = start;
	while (cur->next != NULL)
	{
		if (cur->next->stu.get_Num() == num)
		{
			Node* temp = cur->next;
			cur->next = cur->next->next;
			delete temp;

		}
		else
		{
			cur = cur->next;
		}
		cur = cur->next;
		while (cur->next != NULL)
		{
			cur->stu.change_Num();//改变被删除学生之后的学生的序号
			cur = cur->next;
		}
		end->stu.change_Num();
	}
	cout << "删除成功." << endl;
	return true;
}

//下面方法都是为了改变表中的学生信息，我的想法是通过学生在表中的序号修改
//但因为由于表中访问权限的问题，只能通过遍历节点找到正确的序号（都赖本人才疏学浅）
//所以搞得很麻烦，每个改变都要重复遍历这个过程。飞扬哥看看有没有什么优化方法
//(或者觉得改不了我推倒重来？)



//仅以这个函数为例子注释，看到200行就不用看了
bool List::change_studentID()
{
	short num;
	cout << "请输入要修改的学生序号:";//根据输入序号确认谁要被改
	cin >> num;
	if (is_empty())
	{
		cout << "学生列表为空,无需修改><" << endl;
		return false;
	}

	//头节点为要改对象
	if (start->stu.get_Num() == num)
	{
		start->stu.change_studentID();
		cout << "修改成功." << endl;
		return true;
	}

	//非头节点为要改对象
	Node* cur = start;
	while (cur->next != NULL)
	{
		if (cur->stu.get_Num() == num)
		{
			cur->stu.change_studentID();//修改
			cout << "修改成功." << endl;
			return true;
		}
		else
		{
			cur = cur->next;
		}
	}
	//要改的是末尾节点
	if (end->stu.get_Num() == num)
	{
		end->stu.change_studentID();
		cout << "修改成功." << endl;
		return true;
	}

	return true;
}


bool List::change_name()
{
	short num;
	cout << "请输入要修改的学生序号:";
	cin >> num;
	if (is_empty())
	{
		cout << "学生列表为空,无需修改><" << endl;
		return false;
	}

	if (start->stu.get_Num() == num)
	{
		start->stu.change_name();
		cout << "修改成功." << endl;
		return true;
	}

	Node* cur = start;
	while (cur->next != NULL)
	{
		if (cur->stu.get_Num() == num)
		{
			cur->stu.change_name();
			cout << "修改成功." << endl;
			return true;
		}
		else
		{
			cur = cur->next;
		}
	}
	if (end->stu.get_Num() == num)
	{
		end->stu.change_name();
		cout << "修改成功." << endl;
		return true;
	}

	return true;
}


bool List::change_gender()
{
	short num;
	cout << "请输入要修改的学生序号:";
	cin >> num;
	if (is_empty())
	{
		cout << "学生列表为空,无需修改><" << endl;
		return false;
	}

	if (start->stu.get_Num() == num)
	{
		start->stu.change_gender();
		cout << "修改成功." << endl;
		return true;
	}

	Node* cur = start;
	while (cur->next != NULL)
	{
		if (cur->stu.get_Num() == num)
		{
			cur->stu.change_gender();
			cout << "修改成功." << endl;
			return true;
		}
		else
		{
			cur = cur->next;
		}
	}
	if (end->stu.get_Num() == num)
	{
		end->stu.change_gender();
		cout << "修改成功." << endl;
		return true;
	}

	return true;
}


bool List::change_birthplace()
{
	short num;
	cout << "请输入要修改的学生序号:";
	cin >> num;
	if (is_empty())
	{
		cout << "学生列表为空,无需修改><" << endl;
		return false;
	}

	if (start->stu.get_Num() == num)
	{
		start->stu.change_birthplace();
		cout << "修改成功." << endl;
		return true;
	}

	Node* cur = start;
	while (cur->next != NULL)
	{
		if (cur->stu.get_Num() == num)
		{
			cur->stu.change_birthplace();
			cout << "修改成功." << endl;
			return true;
		}
		else
		{
			cur = cur->next;
		}
	}
	if (end->stu.get_Num() == num)
	{
		end->stu.change_birthplace();
		cout << "修改成功." << endl;
		return true;
	}

	return true;
}


bool List::change_birthday()
{
	short num;
	cout << "请输入要修改的学生序号:";
	cin >> num;
	if (is_empty())
	{
		cout << "学生列表为空,无需修改><" << endl;
		return false;
	}

	if (start->stu.get_Num() == num)
	{
		start->stu.change_birthday();
		cout << "修改成功." << endl;
		return true;
	}

	Node* cur = start;
	while (cur->next != NULL)
	{
		if (cur->stu.get_Num() == num)
		{
			cur->stu.change_birthday();
			cout << "修改成功." << endl;
			return true;
		}
		else
		{
			cur = cur->next;
		}
	}
	if (end->stu.get_Num() == num)
	{
		end->stu.change_birthday();
		cout << "修改成功." << endl;
		return true;
	}

	return true;
}


bool List::change_institute()
{
	short num;
	cout << "请输入要修改的学生序号:";
	cin >> num;
	if (is_empty())
	{
		cout << "学生列表为空,无需修改><" << endl;
		return false;
	}

	if (start->stu.get_Num() == num)
	{
		start->stu.change_institute();
		cout << "修改成功." << endl;
		return true;
	}

	Node* cur = start;
	while (cur->next != NULL)
	{
		if (cur->stu.get_Num() == num)
		{
			cur->stu.change_institute();
			cout << "修改成功." << endl;
			return true;
		}
		else
		{
			cur = cur->next;
		}
	}
	if (end->stu.get_Num() == num)
	{
		end->stu.change_institute();
		cout << "修改成功." << endl;
		return true;
	}

	return true;
}


bool List::change_major()
{
	short num;
	cout << "请输入要修改的学生序号:";
	cin >> num;
	if (is_empty())
	{
		cout << "学生列表为空,无需修改><" << endl;
		return false;
	}

	if (start->stu.get_Num() == num)
	{
		start->stu.change_major();
		cout << "修改成功." << endl;
		return true;
	}

	Node* cur = start;
	while (cur->next != NULL)
	{
		if (cur->stu.get_Num() == num)
		{
			cur->stu.change_major();
			cout << "修改成功." << endl;
			return true;
		}
		else
		{
			cur = cur->next;
		}
	}
	if (end->stu.get_Num() == num)
	{
		end->stu.change_major();
		cout << "修改成功." << endl;
		return true;
	}

	return true;
}



bool List::change_class()
{
	short num;
	cout << "请输入要修改的学生序号:";
	cin >> num;
	if (is_empty())
	{
		cout << "学生列表为空,无需修改><" << endl;
		return false;
	}

	if (start->stu.get_Num() == num)
	{
		start->stu.change_class();
		cout << "修改成功." << endl;
		return true;
	}

	Node* cur = start;
	while (cur->next != NULL)
	{
		if (cur->stu.get_Num() == num)
		{
			cur->stu.change_class();
			cout << "修改成功." << endl;
			return true;
		}
		else
		{
			cur = cur->next;
		}
	}
	if (end->stu.get_Num() == num)
	{
		end->stu.change_class();
		cout << "修改成功." << endl;
		return true;
	}

	return true;
}



bool List::change_gpa()
{
	short num;
	cout << "请输入要修改的学生序号:";
	cin >> num;
	if (is_empty())
	{
		cout << "学生列表为空,无需修改><" << endl;
		return false;
	}

	if (start->stu.get_Num() == num)
	{
		start->stu.change_gpa();
		cout << "修改成功." << endl;
		return true;
	}

	Node* cur = start;
	while (cur->next != NULL)
	{
		if (cur->stu.get_Num() == num)
		{
			cur->stu.change_gpa();
			cout << "修改成功." << endl;
			return true;
		}
		else
		{
			cur = cur->next;
		}
	}
	if (end->stu.get_Num() == num)
	{
		end->stu.change_gpa();
		cout << "修改成功." << endl;
		return true;
	}

	return true;
}



bool List::change_cet4()
{
	short num;
	cout << "请输入要修改的学生序号:";
	cin >> num;
	if (is_empty())
	{
		cout << "学生列表为空,无需修改><" << endl;
		return false;
	}

	if (start->stu.get_Num() == num)
	{
		start->stu.change_cet4();
		cout << "修改成功." << endl;
		return true;
	}

	Node* cur = start;
	while (cur->next != NULL)
	{
		if (cur->stu.get_Num() == num)
		{
			cur->stu.change_cet4();
			cout << "修改成功." << endl;
			return true;
		}
		else
		{
			cur = cur->next;
		}
	}
	if (end->stu.get_Num() == num)
	{
		end->stu.change_cet4();
		cout << "修改成功." << endl;
		return true;
	}

	return true;
}



bool List::change_cet6()
{
	short num;
	cout << "请输入要修改的学生序号:";
	cin >> num;
	if (is_empty())
	{
		cout << "学生列表为空,无需修改><" << endl;
		return false;
	}

	if (start->stu.get_Num() == num)
	{
		start->stu.change_cet6();
		cout << "修改成功." << endl;
		return true;
	}

	Node* cur = start;
	while (cur->next != NULL)
	{
		if (cur->stu.get_Num() == num)
		{
			cur->stu.change_cet6();
			cout << "修改成功." << endl;
			return true;
		}
		else
		{
			cur = cur->next;
		}
	}
	if (end->stu.get_Num() == num)
	{
		end->stu.change_cet6();
		cout << "修改成功." << endl;
		return true;
	}

	return true;
}



bool List::change_com_stu_num()
{
	short num;
	cout << "请输入要修改的学生序号:";
	cin >> num;
	if (is_empty())
	{
		cout << "学生列表为空,无需修改><" << endl;
		return false;
	}

	if (start->stu.get_Num() == num)
	{
		start->stu.change_com_stu_num();
		cout << "修改成功." << endl;
		return true;
	}

	Node* cur = start;
	while (cur->next != NULL)
	{
		if (cur->stu.get_Num() == num)
		{
			cur->stu.change_com_stu_num();
			cout << "修改成功." << endl;
			return true;
		}
		else
		{
			cur = cur->next;
		}
	}
	if (end->stu.get_Num() == num)
	{
		end->stu.change_com_stu_num();
		cout << "修改成功." << endl;
		return true;
	}

	return true;
}


bool List::change_exl_stu_num()
{
	short num;
	cout << "请输入要修改的学生序号:";
	cin >> num;
	if (is_empty())
	{
		cout << "学生列表为空,无需修改><" << endl;
		return false;
	}

	if (start->stu.get_Num() == num)
	{
		start->stu.change_exl_stu_num();
		cout << "修改成功." << endl;
		return true;
	}

	Node* cur = start;
	while (cur->next != NULL)
	{
		if (cur->stu.get_Num() == num)
		{
			cur->stu.change_exl_stu_num();
			cout << "修改成功." << endl;
			return true;
		}
		else
		{
			cur = cur->next;
		}
	}
	if (end->stu.get_Num() == num)
	{
		end->stu.change_exl_stu_num();
		cout << "修改成功." << endl;
		return true;
	}

	return true;
}



bool List::change_exl_carders_num()
{
	short num;
	cout << "请输入要修改的学生序号:";
	cin >> num;
	if (is_empty())
	{
		cout << "学生列表为空,无需修改><" << endl;
		return false;
	}

	if (start->stu.get_Num() == num)
	{
		start->stu.change_exl_carders_num();
		cout << "修改成功." << endl;
		return true;
	}

	Node* cur = start;
	while (cur->next != NULL)
	{
		if (cur->stu.get_Num() == num)
		{
			cur->stu.change_exl_carders_num();
			cout << "修改成功." << endl;
			return true;
		}
		else
		{
			cur = cur->next;
		}
	}
	if (end->stu.get_Num() == num)
	{
		end->stu.change_exl_carders_num();
		cout << "修改成功." << endl;
		return true;
	}

	return true;
}