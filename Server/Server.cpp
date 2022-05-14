#define _AFXDLL 
#
#include <iostream>
#include <afx.h>  
#include <winsock2.h>
#include <process.h> 
#include <string>
#include <fstream>
#include <list>
#include <iomanip>
#define SIZE 40
#define length 17
//#include "Windows.h"

using namespace std;

CFile f;
CFileException ex;

int check_int() {
	int a;
	while (true)
	{
		cin >> a;
		if (cin.get() != '\n')
		{
			cout << "Ошибка ввода, повторите попытку." << endl;
			cin.clear();
			cin.ignore(32767, '\n');
		}
		else return a;
	}
}


class Account {

protected:
	char login[length];               //логин учетной записи
	char password[length];            //пароль учетонй записи
public:
	Account() { login[0] = '\0'; password[0] = '\0'; }
	void enter_logpass() {};             //ввод логина и пароля
	void encrypt_pass() {};              //шифровка пароля
	void create_account();
	char* get_login() { return login; }  //получение логина
	void pass(char* str) {};   //ввод пароля звездочками
	char* Get_pass()
	{
		return password;
	}

	char* Get_log()
	{
		return login;
	}
	void Set_login(const char* log) {
		strcpy_s(login, log);

	}

	void Set_pass(const char* pas) {
		strcpy_s(password, pas);
	}
	
	/*Account(const Account& obj) {

		strcpy_s(this->login, obj.login);
		strcpy_s(this->password, obj.password);

	}*/
};

class Admin : public Account {
public:
	bool autorization() {};                       //авторизация администратора
	void create_account() {};                     //создание администратора
	bool enter() {};                              //вход администратора
	bool account_exist() {};                      //проверка на существование аккаунта

	Admin() {  };  //конструктор
	~Admin() {};

	friend bool operator<(const Admin& o1, const Admin& o2);
	friend bool operator>(const Admin& o1, const Admin& o2);
	friend bool operator==(const Admin& o1, const Admin& o2);
	friend bool operator!=(const Admin& o1, const Admin& o2);
	friend void write_in_file_password_admin(list<Admin> lst);

};

bool operator<(const Admin& o1, const Admin& o2) {
	return strcmp(o1.login, o2.login) < 0;
}
bool operator>(const Admin& o1, const Admin& o2) {
	return strcmp(o1.login, o2.login) > 0;
}
bool operator==(const Admin& o1, const Admin& o2) {
	return strcmp(o1.login, o2.login) == 0;
}
bool operator!=(const Admin& o1, const Admin& o2) {
	return strcmp(o1.login, o2.login) != 0;
}

void write_in_file_password_admin(list<Admin> lst)
{
	list<Admin>::iterator ite;
	ofstream file("Admin_log.txt", ios_base::out & ios_base::trunc);

	for (ite = lst.begin(); ite != lst.end(); ite++) {
		for (int i = 0; i < strlen(ite->login); i++) {
			ite->login[i] = (char)((int)ite->login[i] + 3);
		}
		for (int i = 0; i < strlen(ite->password); i++) {
			ite->password[i] = (char)((int)ite->password[i] + 3);
		}
		file << ite->Get_log() << ";" << ite->Get_pass() << ";";
	}
	file << "*;";
	file.close();
}

void read_admin_fromfile(list<Admin>& investors)
{

	Admin admin;
	char stro[100];
	float ff12;
	int k12;
	ifstream fout("Admin_log.txt", ios_base::in);

	if (!fout.is_open() || fout.peek() == EOF) {
		cout << "Файл не удалось открыть или он пуст (админ)." << endl;
		return;
	}
	while (1) {
		fout.getline(stro, 100, ';');
		if (strcmp(stro, "*") == 0) {
			break;
		}
		for (int i = 0; i < strlen(stro); i++) {
			stro[i] = (char)((int)stro[i] - 3);
		}
		admin.Set_login(stro);
		fout.getline(stro, 100, ';');
		for (int i = 0; i < strlen(stro); i++) {
			stro[i] = (char)((int)stro[i] - 3);
		}
		admin.Set_pass(stro);
		investors.push_back(admin);
	}
	fout.close();
}

class Expert : public Account {
protected:
	char F[20];
	char I[10];
	int exp;
	char position[50];
	char email[50];

public:
	Expert() { F[0] = '\0'; I[0] = '\0', exp = 0; login[0] = '\0'; password[0] = '\0'; position[0] = '\0'; email[0] = '\0'; }; //конструктор без параметров
	
	//Expert(char*, char*) {};                              //конструктор с параметрами
	bool autorization() {};                            //авторизация клиента
	void create_account(list<Expert>&) {};               //регистрация клиента
	bool enter(list<Expert>) {};                         //метод входа клиента
	bool account_exist(list<Expert>) {};                 //проверка на существование аккаунта
	~Expert() {};                                      //пустой деструктор
	
	char* Get_F()
	{
		return F;
	}
	char* Get_I()
	{
		return I;
	}

	char* Get_email()
	{
		return email;
	}

	char* Get_position()
	{
		return position;

	}

	int Get_exp() {
		return exp;
	}

	void Set_F(const char* lastname)
	{
		strcpy_s(F, lastname);
	}


	void Set_I(const char* name)
	{
		strcpy_s(I, name);
	}

	void Set_position(const char* name)
	{
		strcpy_s(position, name);
	}

	void Set_email(const char* em)
	{
		strcpy_s(email, em);
	}

	void Set_exp(int ex) {
		this->exp = ex;
	}
	friend void write_in_file_password_experts(list<Expert> lst);


	void write_expert_sort(list<Expert> lst)
	{
		
		list<Expert>::iterator p;
		ofstream file("Experts_sort.txt", ios_base::out & ios_base::trunc);
		for (int i = 0; i < 85; i++)
			file << "-";
		file << endl;
		file << "|             Фамилия|       Имя| Стаж|        Должность|                     e-mail|" << endl;
		for (int i = 0; i < 85; i++)
			file << "-";
		file << endl;
		for (p = lst.begin(); p != lst.end(); p++) {
			file << "|" << setw(20) << p->Get_F() << "|" << setw(10) << p->Get_I()<<"|"<< setw(5) << p->Get_exp() << "|" << setw(17) << p->Get_position() << "|"<< setw(27) <<p-> Get_email() << "|" << endl;
		}
		for (int i = 0; i < 85; i++) {
			file << "-";
		}
			
		file << endl;
		file << "*;";
		file.close();
	}


	int write_expert_search(list<Expert> lst,char* str)
	{
		int i = 0;
		list<Expert>::iterator p;
		ofstream file("Experts_search.txt", ios_base::out & ios_base::trunc);
		for (int i = 0; i < 85; i++)
			file << "-";
		file << endl;
		file << "|             Фамилия|       Имя| Стаж|        Должность|                     e-mail|" << endl;
		for (int i = 0; i < 85; i++)
			file << "-";
		file << endl;
		for (p = lst.begin(); p != lst.end(); p++) {
			if (strcmp(p->Get_F(), str) == 0) {
				file << "|" << setw(20) << p->Get_F() << "|" << setw(10) << p->Get_I() << "|" << setw(5) << p->Get_exp() << "|" << setw(17) << p->Get_position() << "|" << setw(27) << p->Get_email() << "|" << endl;
				i++;
			}
			}
		for (int i = 0; i < 85; i++) {
			file << "-";
		}

		file << endl;
		file << "*;";
		file.close();
		return i;
	}
	

};


void write_expert_infile(list<Expert> lst)
{
	list<Expert>::iterator p;
	ofstream file("Experts.txt", ios_base::out & ios_base::trunc);
	for (p = lst.begin(); p != lst.end(); p++) {
		file << p->Get_F() << ";" << p->Get_I() << ";" << p->Get_exp() << ";" << p->Get_position() << ";" << p->Get_email() << ";";
	}
	file << "*;";
	file.close();
}

void write_in_file_password_experts(list<Expert> lst)
{
	list<Expert>::iterator p;
	ofstream file("Experts_log.txt", ios_base::out & ios_base::trunc);

	for (p = lst.begin(); p != lst.end(); p++) {
		for (int i = 0; i < strlen(p->login); i++) {
			p->login[i] = (char)((int)p->login[i] + 3);
		}
		for (int i = 0; i < strlen(p->password); i++) {
			p->password[i] = (char)((int)p->password[i] + 3);
		}
		file << p->Get_log() << ";" << p->Get_pass() << ";";
	}
	file << "*;";
	file.close();
}

void read_experts_fromfile(list<Expert>& experts)
{

	Expert expert;
	char str[100];
	float ff;
	int k;
	ifstream f("Experts.txt", ios_base::in);
	if (!f.is_open() || f.peek() == EOF) {
		cout << "Файл не удалось открыть или он пуст(эксперты)." << endl;
		return;
	}

	ifstream file("Experts_log.txt", ios_base::in);
	if (!file.is_open() || file.peek() == EOF) {
		cout << "Файл не удалось открыть или он пуст (эксперты)." << endl;
		return;
	}
	while (1) {
		f.getline(str, 100, ';');
		if (strcmp(str, "*") == 0) {
			break;
		}
		expert.Set_F(str);
		f.getline(str, 100, ';');
		expert.Set_I(str);
		
		f.getline(str, 100, ';');
		k = 0;
		k = atoi(str);
		expert.Set_exp(k);

		f.getline(str, 100, ';');
		expert.Set_position(str);
		f.getline(str, 100, ';');

		expert.Set_email(str);

		file.getline(str, 100, ';');
		if (strcmp(str, "*") == 0) {
			break;
		}
		for (int i = 0; i < strlen(str); i++) {
			str[i] = (char)((int)str[i] - 3);
		}
		expert.Set_login(str);
		file.getline(str, 100, ';');
		for (int i = 0; i < strlen(str); i++) {
			str[i] = (char)((int)str[i] - 3);
		}
		expert.Set_pass(str);
		experts.push_back(expert);
	}
	f.close();
	file.close();
}
class Investor : public Account {
protected:
	char F[20];
	char I[10];
	int practice;
	float capital;
	int projects;

public:
	Investor() { F[0] = '\0'; I[0] = '\0', practice = 0; capital = 0; projects = 0; } //конструктор без параметров
	//Investor(char*, char*) {}                            //конструктор с параметрами
	void action() {}
	bool autorization() {}                            //авторизация клиента
	void create_account(list<Investor>&) {}             //регистрация клиента
	bool enter(list<Investor>) {}                      //метод входа клиента
	bool account_exist(list<Investor>) {}          //проверка на существование аккаунта
	~Investor() {};      //пустой деструктор
	
	char* Get_F()
	{
		return F;
	}
	char* Get_I()
	{
		return I;
	}

	void Set_F(const char* lastname)
	{
		strcpy_s(F, lastname);
	}

	void Set_I(const char* name)
	{
		strcpy_s(I, name);
	}

	int Get_practice() {
		return practice;
	}

	int Get_projects() {
		return projects;
	}

	float Get_capital() {
		return capital;
	}

	void Set_practice(int pr) {
		this->practice = pr;
	}

	void Set_projects(int project) {
		this->projects = project;
	}

	void Set_capital(float cap) {
		this->capital = cap;

	}

	void write_investor_sort(list<Investor> lst)
	{
		lst.sort();
		list<Investor>::iterator p;
		ofstream file("Investors_sort.txt", ios_base::out & ios_base::trunc);
		for (int i = 0; i < 55; i++)
			file << "-";
		file << endl;
		file << "|             Фамилия|       Имя|Капитал|Проекты| Стаж|" << endl;
		for (int i = 0; i < 55; i++)
			file << "-";
		file << endl;
		for (p = lst.begin(); p != lst.end(); p++) {
			file << "|" << setw(20) << p->Get_F() << "|" << setw(10) << p->Get_I() << "|" << setw(7) << p->Get_capital() << "|" << setw(7) << p->Get_projects() << "|" << setw(5) << p->Get_practice() << "|" << endl;
		}
		for (int i = 0; i < 55; i++)
			file << "-";
		file << endl;
		file << "*;";
		file.close();
	}


	int write_investor_filtration(list<Investor> lst,int min,int max)
	{
		int i = 0;
		//lst.sort();
		list<Investor>::iterator p;
		ofstream file("Investors_filtr.txt", ios_base::out & ios_base::trunc);
		for (int i = 0; i < 55; i++)
			file << "-";
		file << endl;
		file << "|             Фамилия|       Имя|Капитал|Проекты| Стаж|" << endl;
		for (int i = 0; i < 55; i++)
			file << "-";
		file << endl;
		for (p = lst.begin(); p != lst.end(); p++) {
			if ((p->Get_practice() >= min) &&( p->Get_practice() <= max)) {
				file << "|" << setw(20) << p->Get_F() << "|" << setw(10) << p->Get_I() << "|" << setw(7) << p->Get_capital() << "|" << setw(7) << p->Get_projects() << "|" << setw(5) << p->Get_practice() << "|" << endl;
				i++;
			}
		}
		for (int i = 0; i < 55; i++) {
			file << "-";
		}
		file << endl;
		file << "*;";
		file.close();
		return i;
	}


	int write_investor_search(list<Investor> lst, char* str)
	{
		int i = 0;
		//lst.sort();
		list<Investor>::iterator p;
		ofstream file("Investors_search.txt", ios_base::out & ios_base::trunc);
		for (int i = 0; i < 55; i++)
			file << "-";
		file << endl;
		file << "|             Фамилия|       Имя|Капитал|Проекты| Стаж|" << endl;
		for (int i = 0; i < 55; i++)
			file << "-";
		file << endl;
		for (p = lst.begin(); p != lst.end(); p++) {
			if (strcmp(p->Get_F(),str)==0) {
				file << "|" << setw(20) << p->Get_F() << "|" << setw(10) << p->Get_I() << "|" << setw(7) << p->Get_capital() << "|" << setw(7) << p->Get_projects() << "|" << setw(5) << p->Get_practice() << "|" << endl;
				i++;
			}
		}
		for (int i = 0; i < 55; i++) {
			file << "-";
		}
		file << endl;
		file << "*;";
		file.close();
		return i;
	}


	friend void write_in_file_password(list<Investor> lst);
	friend bool operator<(const Investor& o1, const Investor& o2);
	friend bool operator>(const Investor& o1, const Investor& o2);
	friend bool operator==(const Investor& o1, const Investor& o2);
	friend bool operator!=(const Investor& o1, const Investor& o2);
};


bool operator<(const Investor& o1, const Investor& o2) {
	return strcmp(o1.F, o2.F) < 0;
}
bool operator>(const Investor& o1, const Investor& o2) {
	return strcmp(o1.F, o2.F) > 0;
}
bool operator==(const Investor& o1, const Investor& o2) {
	return strcmp(o1.F, o2.F) == 0;
}
bool operator!=(const Investor& o1, const Investor& o2) {
	return strcmp(o1.F, o2.F) != 0;
}

void write_investor_infile(list<Investor> lst)
{
	list<Investor>::iterator p;
	ofstream file("Investors.txt", ios_base::out & ios_base::trunc);
	for (p = lst.begin(); p != lst.end(); p++) {
		file << p->Get_F() << ";" << p->Get_I() << ";" << p->Get_capital() << ";" << p->Get_projects() << ";" << p->Get_practice() << ";";
	}
	file << "*;";
	file.close();
}



void write_in_file_password(list<Investor> lst)
{
	list<Investor>::iterator p;
	ofstream file("Investors_log.txt", ios_base::out & ios_base::trunc);

	for (p = lst.begin(); p != lst.end(); p++) {
		for (int i = 0; i < strlen(p->login); i++) {
			p->login[i] = (char)((int)p->login[i] + 3);
		}
		for (int i = 0; i < strlen(p->password); i++) {
			p->password[i] = (char)((int)p->password[i] + 3);
		}
		file << p->Get_log() << ";" << p->Get_pass() << ";";
	}
	file << "*;";
	file.close();
}

void read_investors_fromfile(list<Investor>& investors)
{

	Investor investor;
	char str[100];
	float ff;
	int k;
	ifstream f("Investors.txt", ios_base::in);
	if (!f.is_open() || f.peek() == EOF) {
		cout << "Файл не удалось открыть или он пуст(инвесторы)." << endl;
		return;
	}

	ifstream file("Investors_log.txt", ios_base::in);
	if (!file.is_open() || file.peek() == EOF) {
		cout << "Файл не удалось открыть или он пуст (инвесторы)." << endl;
		return;
	}
	while (1) {
		f.getline(str, 100, ';');
		if (strcmp(str, "*") == 0) {
			break;
		}
		investor.Set_F(str);
		f.getline(str, 100, ';');
		investor.Set_I(str);
		f.getline(str, 100, ';');
		ff = stof(str);
		investor.Set_capital(ff);
		f.getline(str, 100, ';');
		k = atoi(str);
		investor.Set_projects(k);
		f.getline(str, 100, ';');
		k = 0;
		k = atoi(str);
		investor.Set_practice(k);
		file.getline(str, 100, ';');
		if (strcmp(str, "*") == 0) {
			break;
		}
		for (int i = 0; i < strlen(str); i++) {
			str[i] = (char)((int)str[i] - 3);
		}
		investor.Set_login(str);
		file.getline(str, 100, ';');
		for (int i = 0; i < strlen(str); i++) {
			str[i] = (char)((int)str[i] - 3);
		}
		investor.Set_pass(str);
		investors.push_back(investor);
	}
	f.close();
	file.close();
}
	class Contract :public Investor {
	protected:

	};
	class Company : public Admin {

	};

	class Exception {

	};


	class Method
	{

	};

	class Matrix : public Method {

	};



void mailWorking(void* newS) {
	int c, c1 = 0, c2 = 0, c11 = 0, c3 = 0; int e = 0;
	int flag = 0;
	char p[500], com[200], k[500], m[500],q[500],buf[500];
	com[0] = '\0'; p[0] = '\0'; k[0] = '\0'; m[0] = '\0'; q[0] = '\0';buf[0]='\0';

	
	cout << "Сервер работает.\n";
	Investor invest;
	Admin adm;
	Expert expe;

	list<Investor> investor;
	list<Investor> investor1;
	list<Admin> admin;
	list<Expert> expert;

	list<Investor>::iterator it;
	list<Admin>::iterator it_2;
	list<Expert>:: iterator it3;

	char* login_admin;
	char password_admin[20];

	read_investors_fromfile(investor);
	
	read_admin_fromfile(admin);

	read_experts_fromfile(expert);

	for (it = investor.begin(); it != investor.end(); it++) {
		cout << (*it).Get_F() << (*it).Get_I() << (*it).Get_capital() << (*it).Get_projects() << (*it).Get_practice() << (*it).Get_log() << (*it).Get_pass() << endl;
	}

	for (it_2 = admin.begin(); it_2 != admin.end(); it_2++) {
		cout << (*it_2).Get_log() << (*it_2).Get_pass() << endl;
	}

	for (it3 = expert.begin(); it3 != expert.end(); it3++) {
		cout << (*it3).Get_F() << (*it3).Get_I() << (*it3).Get_exp() << (*it3).Get_position()<<(*it3).Get_email() <<(*it3).Get_log() << (*it3).Get_pass() << endl;
	}
	//strcpy_s(adm.Get_log(), login_admin);
	//strcpy_s(adm.Get_pass(), password_admin);

	cout << endl;
	while (1) {
		strcpy_s(p, "Добро пожаловать!\n");
		send((SOCKET)newS, p, sizeof(p), 0);
		strcpy_s(k, "Выберите действие:\n 1 - Аккаунт администратора\n 2 - Аккаунт инвестора\n 3 - Аккаунт эксперта\n 4 - Выход.\n ");
		send((SOCKET)newS, k, sizeof(k), 0);
		p[0] = '\0'; k[0] = '\0';
		recv((SOCKET)newS, m, sizeof(m), 0);
		c = atoi(m);
		switch (c) {
		case 1: {
			strcpy_s(p, "1");
			send((SOCKET)newS, p, sizeof(p), 0);
			
			if (admin.size() == 0) {
				cout << "Регистрация." << endl;
				m[0] = '\0';
				strcpy_s(m, "0");
				send((SOCKET)newS, m, sizeof(m), 0);
				//получили логин
				recv((SOCKET)newS, m, sizeof(m), 0);
				cout << m << endl;

				adm.Set_login(m);

				m[0] = '\0';
				//получили пароль
				recv((SOCKET)newS, m, sizeof(m), 0);
				cout << m << endl;
				adm.Set_pass(m);

				admin.push_back(adm);

				cout << adm.Get_log() << adm.Get_pass() << endl;
				write_in_file_password_admin(admin);

			}

			else {
				cout << "Вход." << endl;
				m[0] = '\0';
				strcpy_s(m, "1");
				send((SOCKET)newS, m, sizeof(m), 0);
				int try_1 = 0;
				char ex1[30];
				char ex21[5];
				int flag = 0;
				e = 1;
				int iteratorr = 0;

				while (e == 1) {
					flag = 0;
					recv((SOCKET)newS, m, sizeof(m), 0);
					cout << m << endl;
					e = 1;
					strcpy_s(ex1, "Такого пользователя нет!");
					strcpy_s(ex21, "0");

					if (admin.size() != 0) {
						for (it_2 = admin.begin(); it_2 != admin.end(); it_2++) {
							if (strcmp(m, it_2->Get_log()) == 0) {
								send((SOCKET)newS, ex21, sizeof(ex21), 0);
								flag = 1;
								e = 2;
								//cout << "Логин существует!" << endl;	
							}
						}

						if (flag == 0) {
							send((SOCKET)newS, ex1, sizeof(ex1), 0);

						}
					}
				}

				cout << "Это итth " << iteratorr << endl;
				e = 0;
				try_1 = 0;
				
					
					while (e == 0) {
						flag = 0;
						//cout << "33333" << m << endl;
						recv((SOCKET)newS, m, sizeof(m), 0);
						e = 0;
						strcpy_s(ex1, "Такого пользователя нет!");
						strcpy_s(ex21, "0");
						int it1 = 0;

						if (admin.size() != 0) {

							for (it_2 = admin.begin(); it_2 != admin.end(); it_2++) {
								cout << endl;
								cout << it_2->Get_pass() << endl;
								if (strcmp(m, it_2->Get_pass()) == 0) {
									send((SOCKET)newS, ex21, sizeof(ex21), 0);
									flag = 1;
									e++;
									//cout << "Пароль совпадает!" << endl;
								}
							}

						}
						if (flag == 0) {
							send((SOCKET)newS, ex1, sizeof(ex1), 0);
							
						}



					}
				
				
			}
			while (c1 != 5) {
				strcpy_s(k, "Меню администратора:\n 1 - Раздел работы с экспертами \n 2 - Раздел работы с инвесторами \n 3 - Изменить пароль и/или логин;\n 4 - Информация о компании; \n 5 - Главное меню.\n ");
				send((SOCKET)newS, k, sizeof(k), 0);
				recv((SOCKET)newS, m, sizeof(m), 0);
				
				c1 = atoi(m);
				switch (c1) {
				case 1: {
					strcpy_s(p, "1");
					send((SOCKET)newS, p, sizeof(p), 0);
					while (c2 != 5) {
						strcpy_s(p, "Работа с экспертами:\n1 - Просмотр экспертов \n2 - Добавить эксперта \n3 - Удалить эксперта \n4 - Просмотреть оценки экспертов\n5 - Выход.\n");


						send((SOCKET)newS, p, sizeof(p), 0);
						recv((SOCKET)newS, m, sizeof(m), 0);
						c2 = atoi(m);
						ifstream file5("Experts_sort.txt");
						switch (c2) {
						case 1: {
							strcpy_s(p, "1");
							send((SOCKET)newS, p, sizeof(p), 0);


							expe.write_expert_sort(expert);
							while (!file5.eof()) {
								k[0] = '\0';
								file5.getline(k, 256, '\n');
								m[0] = '\0';
								strcpy_s(m, "*");
								if (file5.eof()) {
									send((SOCKET)newS, m, sizeof(m), 0);
								}

								else {
									send((SOCKET)newS, k, sizeof(k), 0);
									//cout << k << endl;
								}
							}

							file5.close();
							m[0] = '\0';
							k[0] = '\0';
							break;
						}
						case 2: {
							strcpy_s(p, "2");
							send((SOCKET)newS, p, sizeof(p), 0);

							p[0] = '\0';
							strcpy_s(p, "0");
							if (expert.size() < 3) {
								send((SOCKET)newS, p, sizeof(p), 0);

								//получение фамилии
								recv((SOCKET)newS, m, sizeof(m), 0);
								cout << m << endl;
								expe.Set_F(m);

								//получение имени
								recv((SOCKET)newS, m, sizeof(m), 0);
								cout << m << endl;

								expe.Set_I(m);

								int temp = 0;

								//получение стажа работы
								recv((SOCKET)newS, m, sizeof(m), 0);
								cout << m << endl;
								temp = atoi(m);
								expe.Set_exp(temp);

								
								//получение должности
								recv((SOCKET)newS, m, sizeof(m), 0);
								cout << m << endl;
								expe.Set_position(m);

								//получение почты
								recv((SOCKET)newS, m, sizeof(m), 0);
								cout << m << endl;
								expe.Set_email(m);


								char ex[30];
								char ex2[5];
								int flag = 0;
								e = 0;
								while (e == 0) {
									flag = 0;
									recv((SOCKET)newS, m, sizeof(m), 0);
									cout << m << endl;
									e = 0;
									strcpy_s(ex, "Такой логин уже существует!");
									strcpy_s(ex2, "0");
									if (expert.size() != 0) {
										for (it3 = expert.begin(); it3 != expert.end(); it3++) {
											if (strcmp(m, it3->Get_log()) == 0) {
												send((SOCKET)newS, ex, sizeof(ex), 0);
												flag = 1;
												//cout << "Логин существует!" << endl;
											}
										}
									}
									if (flag == 0) {
										send((SOCKET)newS, ex2, sizeof(ex2), 0);
										e++;
									}
								}
								expe.Set_login(m);
								cout << expe.Get_log() << endl;
								//получили пароль
								recv((SOCKET)newS, m, sizeof(m), 0);
								cout << m << endl;
								expe.Set_pass(m);


								expert.push_back(expe);
								write_expert_infile(expert);
								write_in_file_password_experts(expert);

								for (it3 =expert.begin(); it3 != expert.end(); it3++) {
									cout << (*it3).Get_F() << (*it3).Get_I() << (*it3).Get_exp() << (*it3).Get_position() << (*it3).Get_email() << (*it3).Get_log() << (*it3).Get_pass() << endl;
								}

							}
							
							else {
								p[0] = '\0';
								strcpy_s(p, "1");
								send((SOCKET)newS, p, sizeof(p), 0);
							}
							
							break;
						}
						case 3: {
							ifstream file6("Experts_search.txt");
							ifstream file7("Experts_sort.txt");
							strcpy_s(p, "3");
							send((SOCKET)newS, p, sizeof(p), 0);


							expe.write_expert_sort(expert);
							while (!file7.eof()) {
								k[0] = '\0';
								file7.getline(k, 256, '\n');
								m[0] = '\0';
								strcpy_s(m, "*");
								if (file7.eof()) {
									send((SOCKET)newS, m, sizeof(m), 0);
								}

								else {
									send((SOCKET)newS, k, sizeof(k), 0);
									//cout << k << endl;
								}
							}

							file7.close();
							m[0] = '\0';
							k[0] = '\0';



							//получение фамилии
							recv((SOCKET)newS,buf , sizeof(buf), 0);
							cout << buf << endl;
							int temp4 = 0;

							temp4 = expe.write_expert_search(expert,buf);

							if (temp4 == 0) {
								m[0] = '\0';
								strcpy_s(m, "1");
								send((SOCKET)newS, m, sizeof(m), 0);
							}
							else {
								while (!file6.eof()) {
									k[0] = '\0';
									file6.getline(k, 256, '\n');
									m[0] = '\0';
									strcpy_s(m, "*");
									if (file6.eof()) {
										send((SOCKET)newS, m, sizeof(m), 0);
									}

									else {
										send((SOCKET)newS, k, sizeof(k), 0);
										//cout << k << endl;
									}
								}
								file6.close();
								m[0] = '\0';
								k[0] = '\0';
							}

							for (it3 = expert.begin(); it3 != expert.end(); it3++) {
								
								if (strcmp(buf, it3->Get_F()) == 0)
									expert.erase(it3);
								break;
							}
							write_expert_infile(expert);
							write_in_file_password_experts(expert);
							break;
							}
						case 4: {
							strcpy_s(p, "4");
							send((SOCKET)newS, p, sizeof(p), 0);
							break;
						}
						case 5: {
							strcpy_s(p, "5");
							send((SOCKET)newS, p, sizeof(p), 0);

							break;
						}

						}
					}
					c2 = 0;
					break;
				}
				case 2: {
					strcpy_s(p, "2");
					send((SOCKET)newS, p, sizeof(p), 0);
					while (c2 != 5) {
						strcpy_s(p, "Работа с инвесторами:\n 1 - Просмотреть данные об инвесторах \n 2 - Удалить инвестора \n 3 - Заключить договор \n 4 - Расторгнуть договор \n 5 - Выход.");
						send((SOCKET)newS, p, sizeof(p), 0);//отправили меню
						recv((SOCKET)newS, m, sizeof(m), 0);
						c2 = atoi(m);
						switch (c2) {
						case 1: {
							strcpy_s(p, "1");
							send((SOCKET)newS, p, sizeof(p), 0);
							//просмотр информации

							char menu[500];
							menu[0] = '\n';
							
							while (c3!=4) {
								m[0] = '\0';
								strcpy_s(menu, "Просмотр информации:\n1 - Сортировка \n2 - Фильтрация \n3 - Поиск \n4 - Выход.\n");
								send((SOCKET)newS, menu, sizeof(menu), 0);
								recv((SOCKET)newS, m, sizeof(m), 0);
								c3 = atoi(m);
								ifstream file("Investors_sort.txt");
								ifstream file2("Investors_filtr.txt");
								ifstream file3("Investors_search.txt");
								int temp = 0;
								int tem2 = 0;
								int temp3 = 0;
								int temp4 = 0;
								switch (c3) {
									
								case 1: {
									strcpy_s(p, "1");
									send((SOCKET)newS, p, sizeof(p), 0);

									invest.write_investor_sort(investor);

									while (!file.eof()) {
										k[0] = '\0';
										file.getline(k, 256, '\n');
										m[0] = '\0';
										strcpy_s(m, "*");
										if (file.eof()) {
											send((SOCKET)newS, m, sizeof(m), 0);
										}

										else {
											send((SOCKET)newS, k, sizeof(k), 0);
											//cout << k << endl;
										}
									}

									file.close();
									m[0] = '\0';
									k[0] = '\0';
									break;
								}
									
									
								case 2:
									strcpy_s(p, "2");
									send((SOCKET)newS, p, sizeof(p), 0);
									
									

									//получение минимального значения
									recv((SOCKET)newS, m, sizeof(m), 0);
									cout << m << endl;
									temp = atoi(m);
									
									//получение максимального значения
									recv((SOCKET)newS, m, sizeof(m), 0);
									cout << m << endl;
									tem2 = atoi(m);

									temp3 = invest.write_investor_filtration(investor,temp,tem2);

									if (temp3 == 0) {
										m[0] = '\0';
										strcpy_s(m, "1");
										send((SOCKET)newS, m, sizeof(m), 0);
									}
									else {
										while (!file2.eof()) {
											k[0] = '\0';
											file2.getline(k, 256, '\n');
											m[0] = '\0';
											strcpy_s(m, "*");
											if (file2.eof()) {
												send((SOCKET)newS, m, sizeof(m), 0);
											}

											else {
												send((SOCKET)newS, k, sizeof(k), 0);
												//cout << k << endl;
											}
										}

										file2.close();
										m[0] = '\0';
										k[0] = '\0';

									}
									

									break;

								case 3:
									strcpy_s(p, "3");
									send((SOCKET)newS, p, sizeof(p), 0);
									

									//получение фамилии
									recv((SOCKET)newS, m, sizeof(m), 0);
									cout << m << endl;


									temp4=invest.write_investor_search(investor,m );
									
									if (temp4 == 0) {
										m[0] = '\0';
										strcpy_s(m, "1");
										send((SOCKET)newS, m, sizeof(m), 0);
									}
									else {
										while (!file3.eof()) {
											k[0] = '\0';
											file3.getline(k, 256, '\n');
											m[0] = '\0';
											strcpy_s(m, "*");
											if (file3.eof()) {
												send((SOCKET)newS, m, sizeof(m), 0);
											}

											else {
												send((SOCKET)newS, k, sizeof(k), 0);
												//cout << k << endl;
											}
										}
										file3.close();
										m[0] = '\0';
										k[0] = '\0';
									}
									break;

								case 4:
									strcpy_s(p, "4");
									send((SOCKET)newS, p, sizeof(p), 0);
									break;
								}
								
							}
							c3 = 0;
							break;
						}
						case 2: {
							ifstream file9("Investors_sort.txt");
							ifstream file10("Investors_search.txt");
							strcpy_s(p, "2");
							send((SOCKET)newS, p, sizeof(p), 0);

							invest.write_investor_sort(investor);
							while (!file9.eof()) {
								k[0] = '\0';
								file9.getline(k, 256, '\n');
								m[0] = '\0';
								strcpy_s(m, "*");
								if (file9.eof()) {
									send((SOCKET)newS, m, sizeof(m), 0);
								}

								else {
									send((SOCKET)newS, k, sizeof(k), 0);
									//cout << k << endl;
								}
							}

							file9.close();
							m[0] = '\0';
							k[0] = '\0';

							//получение фамилии
							recv((SOCKET)newS, buf, sizeof(buf), 0);
							cout << buf << endl;
							int temp4 = 0;

							temp4 = invest.write_investor_search(investor, buf);

							if (temp4 == 0) {
								m[0] = '\0';
								strcpy_s(m, "1");
								send((SOCKET)newS, m, sizeof(m), 0);
							}
							else {
								while (!file10.eof()) {
									k[0] = '\0';
									file10.getline(k, 256, '\n');
									m[0] = '\0';
									strcpy_s(m, "*");
									if (file10.eof()) {
										send((SOCKET)newS, m, sizeof(m), 0);
									}

									else {
										send((SOCKET)newS, k, sizeof(k), 0);
										//cout << k << endl;
									}
								}
								file10.close();
								m[0] = '\0';
								k[0] = '\0';
							}
							
							for (it = investor.begin(); it != investor.end(); it++) {

								if (strcmp(buf, it->Get_F()) == 0) {
									investor.erase(it);
									break;
								}	
							}
							write_investor_infile(investor);
							write_in_file_password(investor);
							
							break;
						}
						case 3: {
							strcpy_s(p, "3");
							send((SOCKET)newS, p, sizeof(p), 0);
							break;
						}
						case 4: {
							strcpy_s(p, "4");
							send((SOCKET)newS, p, sizeof(p), 0);
							break;
						}
						case 5: {
							strcpy_s(p, "5");
							send((SOCKET)newS, p, sizeof(p), 0);
							break;
						}
						}
					}
					c2 = 0;
					break;
				}
				case 3: {
					strcpy_s(p, "3");
					send((SOCKET)newS, p, sizeof(p), 0);

					m[0] = '\0';
					
					int try_1 = 0;
					char ex1[30];
					char ex21[5];
					int flag = 0;
					e = 1;
					int iteratorr = 0;

					while (e == 1) {
						flag = 0;
						recv((SOCKET)newS, m, sizeof(m), 0);
						cout << m << endl;
						e = 1;
						strcpy_s(ex1, "Такого пользователя нет!");
						strcpy_s(ex21, "0");

						if (admin.size() != 0) {
							for (it_2 = admin.begin(); it_2 != admin.end(); it_2++) {
								if (strcmp(m, it_2->Get_log()) == 0) {
									send((SOCKET)newS, ex21, sizeof(ex21), 0);
									flag = 1;
									e = 2;
									//cout << "Логин существует!" << endl;	
								}
							}

							if (flag == 0) {
								send((SOCKET)newS, ex1, sizeof(ex1), 0);

							}
						}
					}

					cout << "Это итth " << iteratorr << endl;
					e = 0;
					try_1 = 0;


					while (e == 0) {
						flag = 0;
						//cout << "33333" << m << endl;
						recv((SOCKET)newS, m, sizeof(m), 0);
						e = 0;
						strcpy_s(ex1, "Такого пользователя нет!");
						strcpy_s(ex21, "0");
						int it1 = 0;

						if (admin.size() != 0) {

							for (it_2 = admin.begin(); it_2 != admin.end(); it_2++) {
								cout << endl;
								cout << it_2->Get_pass() << endl;
								if (strcmp(m, it_2->Get_pass()) == 0) {
									send((SOCKET)newS, ex21, sizeof(ex21), 0);
									flag = 1;
									e++;
									//cout << "Пароль совпадает!" << endl;
								}
							}

						}
						if (flag == 0) {
							send((SOCKET)newS, ex1, sizeof(ex1), 0);

						}

					}


			
					while (c2 != 3) {
						strcpy_s(p, "Меню изменения пароля и/или логина:\n 1 - Изменить логин \n 2 - Изменить пароль;\n 3 - Выход.\n");
						send((SOCKET)newS, p, sizeof(p), 0);
						recv((SOCKET)newS, m, sizeof(m), 0);
						c2 = atoi(m);
						switch (c2) {
						case 1: {
							strcpy_s(p, "1");
							send((SOCKET)newS, p, sizeof(p), 0);

							m[0] = '\0';
							
							//получили логин
							recv((SOCKET)newS, m, sizeof(m), 0);
							cout << m << endl;

							
							for (it_2 = admin.begin(); it_2 != admin.end(); it_2++) {
								
									it_2->Set_login(m);

							}

							
							write_in_file_password_admin(admin);
							break;
						}
						case 2: {
							strcpy_s(p, "2");
							send((SOCKET)newS, p, sizeof(p), 0);
							m[0] = '\0';
							//получили пароль
							recv((SOCKET)newS, m, sizeof(m), 0);
							cout << m << endl;
							for (it_2 = admin.begin(); it_2 != admin.end(); it_2++) {

								it_2->Set_pass(m);

							}

							write_in_file_password_admin(admin);
							break;
						}
						case 3: {
							strcpy_s(p, "3");
							send((SOCKET)newS, p, sizeof(p), 0);
							break;
						}
						}
					}
					c2 = 0;
					break;
				}
				case 4: {
					strcpy_s(p, "4");
					send((SOCKET)newS, p, sizeof(p), 0);
					while (c2 != 3) {
						strcpy_s(p, "Меню работы с информацией:\n 1 - Добавить информацию о компании \n 2 - Удалить информацию о компании;\n 3 - Выход.\n");
						send((SOCKET)newS, p, sizeof(p), 0);
						recv((SOCKET)newS, m, sizeof(m), 0);
						c2 = atoi(m);
						switch (c2) {
						case 1: {
							strcpy_s(p, "1");
							send((SOCKET)newS, p, sizeof(p), 0);





							break;
						}
						case 2: {
							strcpy_s(p, "2");
							send((SOCKET)newS, p, sizeof(p), 0);
							break;
						}
						case 3: {
							strcpy_s(p, "3");
							send((SOCKET)newS, p, sizeof(p), 0);
							break;
						}
						}
					}
					c2 = 0;
					break;
				}
				case 5: {
					strcpy_s(p, "5");
					send((SOCKET)newS, p, sizeof(p), 0);
					break;
				}
				}
			}
			c1 = 0;
			break;
		}
		case 2: {
			cout << endl;
			strcpy_s(p, "2");
			send((SOCKET)newS, p, sizeof(p), 0);
			int c444 = 0;
			while (c444 != 3) {
				strcpy_s(k, "Аккаунт инвестора: \n1 - Зарегистрироваться  \n2 - Войти\n3 - Выход\n ");
				send((SOCKET)newS, k, sizeof(k), 0);
				recv((SOCKET)newS, m, sizeof(m), 0);
				c444 = atoi(m);
				switch(c444){
				case 1: {
					strcpy_s(p, "1");
					send((SOCKET)newS, p, sizeof(p), 0);

					//получение фамилии
					recv((SOCKET)newS, m, sizeof(m), 0);
					cout << m << endl;
					invest.Set_F(m);

					//получение имени
					recv((SOCKET)newS, m, sizeof(m), 0);
					cout << m << endl;

					invest.Set_I(m);

					//получение капитала
					recv((SOCKET)newS, m, sizeof(m), 0);
					cout << m << endl;

					float temp;
					temp = stof(m);
					invest.Set_capital(temp);


					//получение проектов
					recv((SOCKET)newS, m, sizeof(m), 0);
					cout << m << endl;
					temp = atoi(m);
					invest.Set_projects(temp);

					//получение опыта
					recv((SOCKET)newS, m, sizeof(m), 0);
					cout << m << endl;
					temp = atoi(m);
					invest.Set_practice(temp);

					//получили логин
					
					char ex[30];
					char ex2[5];
					int flag = 0;
					e = 0;
					while (e == 0) {
						flag = 0;
						recv((SOCKET)newS, m, sizeof(m), 0);
						cout << m << endl;
						e = 0;
						strcpy_s(ex, "Такой логин уже существует!");
						strcpy_s(ex2, "0");
						if (investor.size()!=0) {
							for (it = investor.begin(); it != investor.end(); it++) {
								if (strcmp(m, it->Get_log()) == 0) {
									send((SOCKET)newS, ex, sizeof(ex), 0);
									flag = 1;
									//cout << "Логин существует!" << endl;
								}
							}
						}
						if (flag == 0) {
							send((SOCKET)newS, ex2, sizeof(ex2), 0);
							e++;
						}
					}
					invest.Set_login(m);
					cout << invest.Get_log() << endl;
					//получили пароль
					recv((SOCKET)newS, m, sizeof(m), 0);
					cout << m << endl;
					invest.Set_pass(m);
					cout << invest.Get_pass()<<endl;
					investor.push_back(invest);
					it = investor.begin();
					
					cout << (*it).Get_log();
					cout << it->Get_pass();

					write_investor_infile(investor);

					write_in_file_password(investor);
					
					for (it = investor.begin(); it != investor.end(); it++) {
						cout << (*it).Get_F() << (*it).Get_I() << (*it).Get_capital() << (*it).Get_projects() << (*it).Get_practice() << (*it).Get_log() << (*it).Get_pass() << endl;
					}
					break;
				}
				case 2: {
					strcpy_s(p, "2");
					send((SOCKET)newS, p, sizeof(p), 0);
					p[0] = '\0';

					char ex1[30];
					char ex21[5];
					int flag = 0;
					e = 1;
					int iteratorr = 0;
					
					while (e == 1) {
						flag = 0;
						recv((SOCKET)newS, m, sizeof(m), 0);
						cout << m << endl;
						e = 1;
						strcpy_s(ex1, "Такого пользователя нет!");
						strcpy_s(ex21, "0");

						if (investor.size() != 0) {
							iteratorr = 0;
								for (it = investor.begin(); it != investor.end(); it++) {
									if (strcmp(m, it->Get_log()) == 0) {
										send((SOCKET)newS, ex21, sizeof(ex21), 0);
										flag = 1;
										e = 2;
										it = investor.end();
										it--;
										//cout << "Логин существует!" << endl;	
									}
									
									iteratorr++;
								}
								
							if (flag == 0) {
								send((SOCKET)newS, ex1, sizeof(ex1), 0);

							}
						}
					}
							

					cout << "Это итth " << iteratorr << endl;

					
					e = 0;

					while (e == 0) {
						flag = 0;
						//cout << "33333" << m << endl;
						recv((SOCKET)newS, m, sizeof(m), 0);
						e = 0;
						strcpy_s(ex1, "Такого пользователя нет!");
						strcpy_s(ex21, "0");
						int it1 = 0;
						
						if (investor.size() != 0) {
				
							for (it = investor.begin(); it !=investor.end(); it++) {
								it1++;
								if (it1 == iteratorr) {
									cout << endl;
									cout << it->Get_pass() << endl;
									if (strcmp(m, it->Get_pass()) == 0) {
										send((SOCKET)newS, ex21, sizeof(ex21), 0);
										flag = 1;
										e++;
										//cout << "Пароль совпадает!" << endl;
									}
								}
								
							}
						}
						if (flag == 0) {
							send((SOCKET)newS, ex1, sizeof(ex1), 0);

						}
					}

					while (c11 != 4) {
						strcpy_s(k, "Меню инвестора: \n1 - Редактировать свои данные \n2 - Просмотреть свои данные \n3 - Просмотреть договоры \n4 - Выход. ");
						send((SOCKET)newS, k, sizeof(k), 0);
						recv((SOCKET)newS, m, sizeof(m), 0);
						c11 = atoi(m);
						switch (c11) {
						//ввод инвестиционных данных
						case 1: {
							strcpy_s(p, "1");
							send((SOCKET)newS, p, sizeof(p), 0);
							while (c2 != 5) {
								char stroka[500];
								stroka[0] = '\0';
								int it2 = 0;
								int strooka;
								for (it = investor.begin(); it != investor.end(); it++) {
									it2++;
									if (it2 == iteratorr) {

										stroka[0] = '\0';
										strcpy_s(stroka, it->Get_F());
										send((SOCKET)newS, stroka, sizeof(stroka), 0);

										stroka[0] = '\0';
										strcpy_s(stroka, it->Get_I());
										send((SOCKET)newS, stroka, sizeof(stroka), 0);

										stroka[0] = '\0';
										strooka = it->Get_capital();
										_itoa_s(strooka, stroka, 10);
										send((SOCKET)newS, stroka, sizeof(stroka), 0);

										stroka[0] = '\0';
										strooka = it->Get_projects();
										_itoa_s(strooka, stroka, 10);
										send((SOCKET)newS, stroka, sizeof(stroka), 0);

										stroka[0] = '\0';
										strooka = it->Get_practice();
										_itoa_s(strooka, stroka, 10);
										send((SOCKET)newS, stroka, sizeof(stroka), 0);
									}
								}



								strcpy_s(k, "Выберите что хотите отредактировать:\n 1 - Фамилию и имя\n 2 - Капиталовложения\n 3 - Опыт работы\n 4 - Количество проектов\n 5 - Выход\n ");
								send((SOCKET)newS, k, sizeof(k), 0);
								recv((SOCKET)newS, m, sizeof(m), 0);
								c2 = atoi(m);
								switch (c2) {
								case 1: {
									strcpy_s(p, "1");
									send((SOCKET)newS, p, sizeof(p), 0);
									
									//получение фамилии
									recv((SOCKET)newS, m, sizeof(m), 0);
									cout << m << endl;

									int it1 = 0;
									for (it = investor.begin(); it != investor.end(); it++) {
										it1++;
										if (it1 == iteratorr) {
											it->Set_F(m);
											
										}

									}

									//получение имени
									recv((SOCKET)newS, m, sizeof(m), 0);
									cout << m << endl;
									 it1 = 0;
									for (it = investor.begin(); it != investor.end(); it++) {
										it1++;
										if (it1 == iteratorr) {
											it->Set_I(m);

										}

									}
									
									write_investor_infile(investor);
									break;
								}
								case 2: {
									strcpy_s(p, "2");
									send((SOCKET)newS, p, sizeof(p), 0);
									//получение капитала
									recv((SOCKET)newS, m, sizeof(m), 0);
									cout << m << endl;

									float temp;
									temp = stof(m);
									int it1 = 0;
									for (it = investor.begin(); it != investor.end(); it++) {
										it1++;
										if (it1 == iteratorr) {
											it->Set_capital(temp);

										}

									}
									write_investor_infile(investor);
									
									break;
								}
								case 3: {
									strcpy_s(p, "3");
									send((SOCKET)newS, p, sizeof(p), 0);
									float temp;
									//получение проектов
									recv((SOCKET)newS, m, sizeof(m), 0);
									cout << m << endl;
									temp = atoi(m);

									int it1 = 0;
									for (it = investor.begin(); it != investor.end(); it++) {
										it1++;
										if (it1 == iteratorr) {
											it->Set_projects(temp);

										}

									}
									
									write_investor_infile(investor);
									break;
								}
								case 4: {
									strcpy_s(p, "4");
									send((SOCKET)newS, p, sizeof(p), 0);
									
									//получение опыта
									recv((SOCKET)newS, m, sizeof(m), 0);
									cout << m << endl;
									int it1 = 0;
									int temp = 0;
									temp = atoi(m);
									for (it = investor.begin(); it != investor.end(); it++) {
										it1++;
										if (it1 == iteratorr) {
											it->Set_practice(temp);

										}
									}
									write_investor_infile(investor);

									break;
								}
								case 5: {
									strcpy_s(p, "5");
									send((SOCKET)newS, p, sizeof(p), 0);
									break;
								}
									  
								}
							}
							c2 = 0;
							break;
							

						}
						case 2: {
							strcpy_s(p, "2");
							send((SOCKET)newS, p, sizeof(p), 0);
							char stroka[500];
							stroka[0] = '\0';
							int it2 = 0;
							int strooka;
							for (it = investor.begin(); it != investor.end(); it++) {
								it2++;
								if (it2 == iteratorr) {

								stroka[0] = '\0';
								strcpy_s(stroka, it->Get_F());
								send((SOCKET)newS, stroka, sizeof(stroka), 0);

								stroka[0] = '\0';
								strcpy_s(stroka, it->Get_I());
								send((SOCKET)newS, stroka, sizeof(stroka), 0);
								
								stroka[0] = '\0';
								strooka = it->Get_capital();
								_itoa_s(strooka, stroka, 10);
								send((SOCKET)newS, stroka, sizeof(stroka), 0);

								stroka[0] = '\0';
								strooka = it->Get_projects();
								_itoa_s(strooka, stroka, 10);
								send((SOCKET)newS, stroka, sizeof(stroka), 0);

								stroka[0] = '\0';
								strooka = it->Get_practice();
								_itoa_s(strooka, stroka, 10);
								send((SOCKET)newS, stroka, sizeof(stroka), 0);	
								}
							}

							break;
						}
						case 3: {
							strcpy_s(p, "3");
							send((SOCKET)newS, p, sizeof(p), 0);
							break;
						}
						case 4: {
							strcpy_s(p, "4");
							send((SOCKET)newS, p, sizeof(p), 0);
							break;
						}
						}
					}
					c11 = 0;
					break;
				}
				case 3: {
					strcpy_s(p, "3");
					send((SOCKET)newS, p, sizeof(p), 0);
					break;
				}
				}
			}
			c444 = 0;
			break;
		}
		case 3: {
			strcpy_s(p, "3");
			send((SOCKET)newS, p, sizeof(p), 0);
			while (c1 != 4) {
				strcpy_s(k, "Меню эксперта:\n 1 - Информация об экспертах \n 2 - Выставить оценки для инвесторов \n 3 - Выбрать наилучший вариант\n 4 - Выход. ");
				send((SOCKET)newS, k, sizeof(k), 0);
				recv((SOCKET)newS, m, sizeof(m), 0);
				c1 = atoi(m);
				switch (c1) {
				case 1: {
					strcpy_s(p, "1");
					send((SOCKET)newS, p, sizeof(p), 0);
					while (c2 != 4) {
						strcpy_s(k, "Меню просмотра информации об инвесторах:\n 1 - Просмотреть информацию в алфавитном порядке \n 2 - Просмотреть информацию  с фильтрацией по капиталовложениям\n 3 - Поиск по конкретной фамилии \n 4 - Выход\n ");
						send((SOCKET)newS, k, sizeof(k), 0);
						recv((SOCKET)newS, m, sizeof(m), 0);
						c1 = atoi(m);
						switch (c1) {
						case 1: {
							strcpy_s(p, "1");
							send((SOCKET)newS, p, sizeof(p), 0);
							break;
						}
						case 2: {
							strcpy_s(p, "2");
							send((SOCKET)newS, p, sizeof(p), 0);
							break;
						}
						case 3: {
							strcpy_s(p, "3");
							send((SOCKET)newS, p, sizeof(p), 0);
							break;
						}
						case 4: {
							strcpy_s(p, "4");
							send((SOCKET)newS, p, sizeof(p), 0);
							break;
						}
						}
					}
					c2 = 0;
					break;
				}
				case 2: {
					strcpy_s(p, "2");
					send((SOCKET)newS, p, sizeof(p), 0);
					break;
				}
				case 3: {
					strcpy_s(p, "3");
					send((SOCKET)newS, p, sizeof(p), 0);
					break;
				}
				}
			}
			c1 = 0;
			break;
		}
		case 4: {
			strcpy_s(p, "4");
			send((SOCKET)newS, p, sizeof(p), 0);
			closesocket((SOCKET)newS);
			exit(EXIT_SUCCESS);
			break;
		}
		}
}

	}


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	wVersionRequested = MAKEWORD(2, 2);
	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0)
		return -1;
	sockaddr_in local;
	local.sin_family = AF_INET;
	local.sin_port = htons(1280);
	local.sin_addr.s_addr = htonl(INADDR_ANY);
	SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
	int c = bind(s, (struct sockaddr*)&local, sizeof(local));
	int r = listen(s, 5);
	while (true) {
		sockaddr_in remote;
		int j = sizeof(remote);
		SOCKET newS = accept(s, (struct sockaddr*)&remote, &j);
		_beginthread(mailWorking, 0, (void*)newS);  //создание потока(Начальный адрес процедуры, который начинает выполнение нового потока; размер стека нового потока или 0; список аргументов, передаваемый в новый поток, или NULL)
	}
	WSACleanup();
	return 0;
}

