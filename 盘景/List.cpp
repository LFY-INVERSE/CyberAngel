#include"Students.h"

using namespace std;

//List���� ��������ʽ��



List::List() {//List�๹�캯��
	nsize = 20;//
	start = end = NULL;
	stu_num = 0;
}




List::List(int n_size = 20) //List�๹�캯��
{
	nsize = n_size;//
	start = end = NULL;
	stu_num = 0;
}



List::~List() //List�����캯��
{
	Node* temp;
	while (start != NULL)
	{
		temp = start;
		start = start->next;
		delete temp;
	}
}

//��ʾ������е�ѧ����Ϣ
bool List::show()
{
	Node* temp = start;
	if (is_empty())
	{
		cout << "ѧ���б�Ϊ0.\n";
		return true;
	}
	while (temp->next != NULL)
	{
		temp->stu.Show();
		temp = temp->next;
	}
	end->stu.Show();
	cout << "��ʾ���.\n";
	return true;
}

//�����Ƿ�Ϊ��
bool List::is_empty()const {
	return stu_num == 0;
}



//���Ƿ�����
bool List::is_full()const {
	return stu_num == nsize;
}



//�ڱ�������ѧ����Ϣ
bool List::add_Stu(const Student& stu) {
	if (is_full())
	{
		cout << "�����������޷�¼��" << endl;
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



//�ڱ���ɾ��ѧ����Ϣ
bool List::del_Stu() {
	short num;
	cout << "������Ҫɾ��ѧ�������";//�����������ȷ��˭Ҫ��ɾ
	cin >> num;
	if (is_empty())//���������
	{
		cout << "ѧ���б�Ϊ��,ɾ��ʧ��." << endl;
		return false;
	}

	if (start->stu.get_Num() == num)//Ҫɾ����ͷ�ڵ�����
	{
		Node* temp0 = start->next;
		Node* temp = start;
		start = start->next;
		delete temp;
		start->stu.change_Num();
		while (temp0->next != NULL)
		{
			start->next->stu.change_Num();//�ı䱻ɾ��ѧ��֮���ѧ�������

		}
		cout << "ɾ���ɹ�." << endl;
		return true;
	}
	//ɾ�������м��ĩβ�ڵ�����
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
			cur->stu.change_Num();//�ı䱻ɾ��ѧ��֮���ѧ�������
			cur = cur->next;
		}
		end->stu.change_Num();
	}
	cout << "ɾ���ɹ�." << endl;
	return true;
}

//���淽������Ϊ�˸ı���е�ѧ����Ϣ���ҵ��뷨��ͨ��ѧ���ڱ��е�����޸�
//����Ϊ���ڱ��з���Ȩ�޵����⣬ֻ��ͨ�������ڵ��ҵ���ȷ����ţ��������˲���ѧǳ��
//���Ը�ú��鷳��ÿ���ı䶼Ҫ�ظ�����������̡�����翴����û��ʲô�Ż�����
//(���߾��øĲ������Ƶ�������)



//�����������Ϊ����ע�ͣ�����200�оͲ��ÿ���
bool List::change_studentID()
{
	short num;
	cout << "������Ҫ�޸ĵ�ѧ�����:";//�����������ȷ��˭Ҫ����
	cin >> num;
	if (is_empty())
	{
		cout << "ѧ���б�Ϊ��,�����޸�><" << endl;
		return false;
	}

	//ͷ�ڵ�ΪҪ�Ķ���
	if (start->stu.get_Num() == num)
	{
		start->stu.change_studentID();
		cout << "�޸ĳɹ�." << endl;
		return true;
	}

	//��ͷ�ڵ�ΪҪ�Ķ���
	Node* cur = start;
	while (cur->next != NULL)
	{
		if (cur->stu.get_Num() == num)
		{
			cur->stu.change_studentID();//�޸�
			cout << "�޸ĳɹ�." << endl;
			return true;
		}
		else
		{
			cur = cur->next;
		}
	}
	//Ҫ�ĵ���ĩβ�ڵ�
	if (end->stu.get_Num() == num)
	{
		end->stu.change_studentID();
		cout << "�޸ĳɹ�." << endl;
		return true;
	}

	return true;
}


bool List::change_name()
{
	short num;
	cout << "������Ҫ�޸ĵ�ѧ�����:";
	cin >> num;
	if (is_empty())
	{
		cout << "ѧ���б�Ϊ��,�����޸�><" << endl;
		return false;
	}

	if (start->stu.get_Num() == num)
	{
		start->stu.change_name();
		cout << "�޸ĳɹ�." << endl;
		return true;
	}

	Node* cur = start;
	while (cur->next != NULL)
	{
		if (cur->stu.get_Num() == num)
		{
			cur->stu.change_name();
			cout << "�޸ĳɹ�." << endl;
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
		cout << "�޸ĳɹ�." << endl;
		return true;
	}

	return true;
}


bool List::change_gender()
{
	short num;
	cout << "������Ҫ�޸ĵ�ѧ�����:";
	cin >> num;
	if (is_empty())
	{
		cout << "ѧ���б�Ϊ��,�����޸�><" << endl;
		return false;
	}

	if (start->stu.get_Num() == num)
	{
		start->stu.change_gender();
		cout << "�޸ĳɹ�." << endl;
		return true;
	}

	Node* cur = start;
	while (cur->next != NULL)
	{
		if (cur->stu.get_Num() == num)
		{
			cur->stu.change_gender();
			cout << "�޸ĳɹ�." << endl;
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
		cout << "�޸ĳɹ�." << endl;
		return true;
	}

	return true;
}


bool List::change_birthplace()
{
	short num;
	cout << "������Ҫ�޸ĵ�ѧ�����:";
	cin >> num;
	if (is_empty())
	{
		cout << "ѧ���б�Ϊ��,�����޸�><" << endl;
		return false;
	}

	if (start->stu.get_Num() == num)
	{
		start->stu.change_birthplace();
		cout << "�޸ĳɹ�." << endl;
		return true;
	}

	Node* cur = start;
	while (cur->next != NULL)
	{
		if (cur->stu.get_Num() == num)
		{
			cur->stu.change_birthplace();
			cout << "�޸ĳɹ�." << endl;
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
		cout << "�޸ĳɹ�." << endl;
		return true;
	}

	return true;
}


bool List::change_birthday()
{
	short num;
	cout << "������Ҫ�޸ĵ�ѧ�����:";
	cin >> num;
	if (is_empty())
	{
		cout << "ѧ���б�Ϊ��,�����޸�><" << endl;
		return false;
	}

	if (start->stu.get_Num() == num)
	{
		start->stu.change_birthday();
		cout << "�޸ĳɹ�." << endl;
		return true;
	}

	Node* cur = start;
	while (cur->next != NULL)
	{
		if (cur->stu.get_Num() == num)
		{
			cur->stu.change_birthday();
			cout << "�޸ĳɹ�." << endl;
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
		cout << "�޸ĳɹ�." << endl;
		return true;
	}

	return true;
}


bool List::change_institute()
{
	short num;
	cout << "������Ҫ�޸ĵ�ѧ�����:";
	cin >> num;
	if (is_empty())
	{
		cout << "ѧ���б�Ϊ��,�����޸�><" << endl;
		return false;
	}

	if (start->stu.get_Num() == num)
	{
		start->stu.change_institute();
		cout << "�޸ĳɹ�." << endl;
		return true;
	}

	Node* cur = start;
	while (cur->next != NULL)
	{
		if (cur->stu.get_Num() == num)
		{
			cur->stu.change_institute();
			cout << "�޸ĳɹ�." << endl;
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
		cout << "�޸ĳɹ�." << endl;
		return true;
	}

	return true;
}


bool List::change_major()
{
	short num;
	cout << "������Ҫ�޸ĵ�ѧ�����:";
	cin >> num;
	if (is_empty())
	{
		cout << "ѧ���б�Ϊ��,�����޸�><" << endl;
		return false;
	}

	if (start->stu.get_Num() == num)
	{
		start->stu.change_major();
		cout << "�޸ĳɹ�." << endl;
		return true;
	}

	Node* cur = start;
	while (cur->next != NULL)
	{
		if (cur->stu.get_Num() == num)
		{
			cur->stu.change_major();
			cout << "�޸ĳɹ�." << endl;
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
		cout << "�޸ĳɹ�." << endl;
		return true;
	}

	return true;
}



bool List::change_class()
{
	short num;
	cout << "������Ҫ�޸ĵ�ѧ�����:";
	cin >> num;
	if (is_empty())
	{
		cout << "ѧ���б�Ϊ��,�����޸�><" << endl;
		return false;
	}

	if (start->stu.get_Num() == num)
	{
		start->stu.change_class();
		cout << "�޸ĳɹ�." << endl;
		return true;
	}

	Node* cur = start;
	while (cur->next != NULL)
	{
		if (cur->stu.get_Num() == num)
		{
			cur->stu.change_class();
			cout << "�޸ĳɹ�." << endl;
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
		cout << "�޸ĳɹ�." << endl;
		return true;
	}

	return true;
}



bool List::change_gpa()
{
	short num;
	cout << "������Ҫ�޸ĵ�ѧ�����:";
	cin >> num;
	if (is_empty())
	{
		cout << "ѧ���б�Ϊ��,�����޸�><" << endl;
		return false;
	}

	if (start->stu.get_Num() == num)
	{
		start->stu.change_gpa();
		cout << "�޸ĳɹ�." << endl;
		return true;
	}

	Node* cur = start;
	while (cur->next != NULL)
	{
		if (cur->stu.get_Num() == num)
		{
			cur->stu.change_gpa();
			cout << "�޸ĳɹ�." << endl;
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
		cout << "�޸ĳɹ�." << endl;
		return true;
	}

	return true;
}



bool List::change_cet4()
{
	short num;
	cout << "������Ҫ�޸ĵ�ѧ�����:";
	cin >> num;
	if (is_empty())
	{
		cout << "ѧ���б�Ϊ��,�����޸�><" << endl;
		return false;
	}

	if (start->stu.get_Num() == num)
	{
		start->stu.change_cet4();
		cout << "�޸ĳɹ�." << endl;
		return true;
	}

	Node* cur = start;
	while (cur->next != NULL)
	{
		if (cur->stu.get_Num() == num)
		{
			cur->stu.change_cet4();
			cout << "�޸ĳɹ�." << endl;
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
		cout << "�޸ĳɹ�." << endl;
		return true;
	}

	return true;
}



bool List::change_cet6()
{
	short num;
	cout << "������Ҫ�޸ĵ�ѧ�����:";
	cin >> num;
	if (is_empty())
	{
		cout << "ѧ���б�Ϊ��,�����޸�><" << endl;
		return false;
	}

	if (start->stu.get_Num() == num)
	{
		start->stu.change_cet6();
		cout << "�޸ĳɹ�." << endl;
		return true;
	}

	Node* cur = start;
	while (cur->next != NULL)
	{
		if (cur->stu.get_Num() == num)
		{
			cur->stu.change_cet6();
			cout << "�޸ĳɹ�." << endl;
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
		cout << "�޸ĳɹ�." << endl;
		return true;
	}

	return true;
}



bool List::change_com_stu_num()
{
	short num;
	cout << "������Ҫ�޸ĵ�ѧ�����:";
	cin >> num;
	if (is_empty())
	{
		cout << "ѧ���б�Ϊ��,�����޸�><" << endl;
		return false;
	}

	if (start->stu.get_Num() == num)
	{
		start->stu.change_com_stu_num();
		cout << "�޸ĳɹ�." << endl;
		return true;
	}

	Node* cur = start;
	while (cur->next != NULL)
	{
		if (cur->stu.get_Num() == num)
		{
			cur->stu.change_com_stu_num();
			cout << "�޸ĳɹ�." << endl;
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
		cout << "�޸ĳɹ�." << endl;
		return true;
	}

	return true;
}


bool List::change_exl_stu_num()
{
	short num;
	cout << "������Ҫ�޸ĵ�ѧ�����:";
	cin >> num;
	if (is_empty())
	{
		cout << "ѧ���б�Ϊ��,�����޸�><" << endl;
		return false;
	}

	if (start->stu.get_Num() == num)
	{
		start->stu.change_exl_stu_num();
		cout << "�޸ĳɹ�." << endl;
		return true;
	}

	Node* cur = start;
	while (cur->next != NULL)
	{
		if (cur->stu.get_Num() == num)
		{
			cur->stu.change_exl_stu_num();
			cout << "�޸ĳɹ�." << endl;
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
		cout << "�޸ĳɹ�." << endl;
		return true;
	}

	return true;
}



bool List::change_exl_carders_num()
{
	short num;
	cout << "������Ҫ�޸ĵ�ѧ�����:";
	cin >> num;
	if (is_empty())
	{
		cout << "ѧ���б�Ϊ��,�����޸�><" << endl;
		return false;
	}

	if (start->stu.get_Num() == num)
	{
		start->stu.change_exl_carders_num();
		cout << "�޸ĳɹ�." << endl;
		return true;
	}

	Node* cur = start;
	while (cur->next != NULL)
	{
		if (cur->stu.get_Num() == num)
		{
			cur->stu.change_exl_carders_num();
			cout << "�޸ĳɹ�." << endl;
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
		cout << "�޸ĳɹ�." << endl;
		return true;
	}

	return true;
}