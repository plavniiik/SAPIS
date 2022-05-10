#define _AFXDLL
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <iostream>
#include <conio.h>

#define SIZE 40
#define length 17
using namespace std;

void pass(char* str)
{
	int j = 0;
	while (j != 16)
	{
		str[j] = _getch();
		if (str[j] == '\r')
			break;
		if (str[j] == '\b')
		{
			printf("\b \b");
			j--;
		}
		else if (str[j] != '\0')
		{
			printf("*");
			j++;
		}
	}
	str[j] = '\0';
}
void enter_logpass(char* login, char* password) {
	char str[length];

	while (true)
	{
		
		if (login[0] == '\0')
			cin.getline(str, length, '\n');
		else
			pass(str);
		if (strlen(str) >= 3)
		{
			for (unsigned int i = 0; i < strlen(str); i++)
			{
				if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= '0' && str[i] <= '9' || str[i] >= 'a' && str[i] <= 'z')
				{
					if (i == strlen(str) - 1)
					{
						if (login[0] == '\0')
							strcpy(login, str);
						else
							strcpy(password, str);
						
						return;
					}
					continue;
				}
				break;
			}
		}
		cin.clear();
		fflush(stdin);
		cout << "Неправильно, попробуйте еще раз!" << endl;
	}

}


void enter_login(char* login) {
	char str[length];

	while (true)
	{
		cin.getline(str, length, '\n');

		if (strlen(str) >= 3 && strlen(str) <= 16 )
		{
			for (unsigned int i = 0; i < strlen(str); i++)
			{
				if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= '0' && str[i] <= '9' || str[i] >= 'a' && str[i] <= 'z')
				{
					if (i == strlen(str) - 1)
					{
						
						strcpy(login, str);
						return;
					}
					continue;
				}
				break;
			}
		}
		cin.clear();
		fflush(stdin);
		cout << "Неправильно, попробуйте еще раз!" << endl;
	}

}

double check_float() {
	float a;
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
double check_i() {
	float a;
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
bool check(char* str)
{
	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] == '!' || str[i] == '@' || str[i] == '#' || str[i] == '$' || str[i] == '%' || str[i] == '^' || str[i] == '&' || str[i] == '*' || str[i] == '/' || str[i] == '.')
			return false;
	return true;
}
int ValueCheck_2(char stroka[100])
{
	int k, flag = 0;
	k = strlen(stroka);
	while (flag != k)
	{
		for (int i = 0; i < k; i++)
		{
			int l = flag;
			if ((stroka[i] >= (-64)) && (stroka[i] <= (-1)))
			{
				flag++;
			}
			if ((stroka[i] == (-88)) || (stroka[i] == (-72)))
			{
				flag++;
			}
			if (flag == l)
			{
				i = k;
			}
		}
		if (flag != k)
		{
			return 1;
		}
		else return 2;
	}
}

bool check_numbers(char* str)
{
	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] >= '0' && str[i] <= '9')
			return false;
	return true;
}

int CheckNumber() //пропускает только целые числа
{
	int number;
	while (1) {
		cin >> number;
		if (cin.get() != '\n') {
			cout << "Это не число. Повторите попытку:" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
		}
		else return number;
	}
}

int CheckChoice(int a, int b) //сужает целые числа до определённого диапазона (от a до b)
{
	int choice = 0;
	while (choice == 0) {
		choice = CheckNumber();
		if ((choice < a) || (choice > b)) {
			cout << "Такого числа нет в меню! Пожалуйста, повторите попытку:" << endl;
			choice = 0;
		}
	}
	return choice;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	WORD wVersionRequested;
	WSADATA wsaData;
	int err, t, t1 = 0, t2 = 0, t3 = 0; int yyy;
	wVersionRequested = MAKEWORD(2, 2);
	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0)
		return -1;
	struct sockaddr_in peer;
	peer.sin_family = AF_INET;
	peer.sin_port = htons(1280);
	peer.sin_addr.s_addr = inet_addr("127.0.0.1");
	SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
	connect(s, (struct sockaddr*)&peer, sizeof(peer));
	char b[500], f[500], k[500], ex[35];
	
	while (1) {
		f[0] = '\0';
		b[0] = '\0';
		recv(s, b, sizeof(b), 0);
		recv(s, f, sizeof(f), 0);
		cout << b;
		cout << f;
		t = CheckChoice(1, 4);//главное меню
		_itoa_s(t, b, 10);
		send(s, b, sizeof(b), 0);
		recv(s, k, sizeof(k), 0);
		system("cls");
		t = atoi(k);
		switch (t) {
			//меню эксперта
		case 1: {
			system("cls");
			f[0] = '\0';
			recv(s, f, sizeof(f), 0);

			if (strcmp(f, "0") == 0) {
				char login2[20];
				char password2[20];

				cout << "Регистрация." << endl;

				cout << "Введите логин:" << endl;
				enter_login(login2);
				f[0] = '\0';
				//отправили логин
				strcpy_s(f, login2);

				send(s, f, sizeof(f), 0);

				cout << "Введите пароль:" << endl;
				enter_logpass(login2, password2);
				f[0] = '\0';
				strcpy_s(f, password2);
				//отправили пароль
				send(s, f, sizeof(f), 0);


			}

			else {
				cout << "Вход." << endl;
			}


			while (t1 != 5) {
				recv(s, k, sizeof(k), 0);
				cout << k << endl;
				t1=CheckChoice(1, 5);
				_itoa_s(t1, b, 10);
			
				send(s, b, sizeof(b), 0);
				recv(s, k, sizeof(k), 0);
				t1 = atoi(k);
				switch (t1) {
				case 1: {
					system("cls");
					while (t2 != 5) {
						recv(s, k, sizeof(k), 0);
						cout << k << endl;
						t2=CheckChoice(1, 5);
						_itoa_s(t2, b, 10);
						send(s, b, sizeof(b), 0);
						recv(s, k, sizeof(k), 0);
						t2 = atoi(k);
						switch (t2) {
						case 1: {
							system("cls");

							break;
						}
						case 2: {
							system("cls");
							break;
						}
						case 3: {
							system("cls");
							break;
						}
						case 4: {
							system("cls");
							break;
						}
						case 5: {
							system("cls");
							break;
						}
						}
					}
					t2 = 0;
					break;
				}
				case 2: {
					system("cls");
					while (t2 != 4) {
						recv(s, k, sizeof(k), 0);
						cout << k << endl;
						t2 = CheckChoice(1,4);
						_itoa_s(t2, b, 10);
						send(s, b, sizeof(b), 0);
						recv(s, k, sizeof(k), 0);
						t2 = atoi(k);
						switch (t2) {
						case 1: {
							while (t3 != 4) {
								recv(s, k, sizeof(k), 0);
								cout << k << endl;
								cin >> t3;
								_itoa_s(t3, b, 10);
								send(s, b, sizeof(b), 0);
								recv(s, k, sizeof(k), 0);
								t3 = atoi(k);
								break;
							}
						case 2: {
							system("cls");
							break;
						}
						case 3: {
							system("cls");
							break;
						}
						case 4: {
							system("cls");
							break;
						}
						}
						}
					}
					t2 = 0;
					break;
				}
				case 3: {
					system("cls");
					while (t2 != 3) {
						recv(s, k, sizeof(k), 0);
						cout << k << endl;
						 t2 = CheckChoice(1, 3);;
						_itoa_s(t2, b, 10);
						send(s, b, sizeof(b), 0);
						recv(s, k, sizeof(k), 0);
						t2 = atoi(k);
						switch (t2) {
						case 1: {
							system("cls");
							break;
						}
						case 2: {
							system("cls");
							break;
						}
						case 3: {
							system("cls");
							break;
						}

						}
					}
					t2 = 0;
					break;
				}
				case 4: {
					system("cls");
					while (t2 != 3) {
						recv(s, k, sizeof(k), 0);
						cout << k << endl;
						t2 = CheckChoice(1, 3);;
						_itoa_s(t2, b, 10);
						send(s, b, sizeof(b), 0);
						recv(s, k, sizeof(k), 0);
						t2 = atoi(k);
						switch (t2) {
						case 1: {
							system("cls");
							break;
						}
						case 2: {
							system("cls");
							break;
						}
						case 3: {
							system("cls");
							break;
						}

						}
					}
					t2 = 0;
					break;
				}
				case 5: {
					system("cls");
					break;
				}
				}
			}
			t1 = 0;
			break;
		}  
		//меню инвестора
		case 2: {
			system("cls");
			int t444 = 0;
			k[0] = '\0';
			b[0] = '\0';
			while (t444!=3) {
				recv(s, k, sizeof(k), 0);
				cout << k << endl;
				t444 = CheckChoice(1, 3);
				_itoa_s(t444, b, 10);
				send(s, b, sizeof(b), 0);
				recv(s, k, sizeof(k), 0);
				t444 = atoi(k);
				switch (t444) {
				f[0] = '\0';
				case 1: {
					//РЕГИСТРАЦИЯ

					system("cls");

					cout << "Давайте зарегистрируем Вас в качестве инвестора." << endl;
					cout << endl;
					
					int check = 0;

					while (check != 2)
					{
						cout << "Введите Вашу фамилию" << endl;
						cin.getline(f, 20, '\n');
						check = ValueCheck_2(f);
						f[strlen(f)] = '\0';
						if (check == 1) {
							cout << "Неверный ввод, попробуйте ещё раз!" << endl;
							cout << endl;
						}
					}
					send(s, f, sizeof(f), 0);
					check = 0;
					while (check != 2)
					{
						cout << "Введите Ваше имя:" << endl;
						cin.getline(f, 20, '\n');
						check = ValueCheck_2(f);
						if (check == 1) {
							cout << "Неверный ввод, попробуйте ещё раз!" << endl;
							cout << endl;
						}
					}
					send(s, f, sizeof(f), 0);


					check = 0;
					float cap;
					while (true)
					{
						cout << "Введите сумму капитала, которую планируете вложить в производство:(в белорусских рублях):" << endl;
						cap = check_float();
						break;
					}

					sprintf(f, "%.3f", cap);
					//_itoa_s(check, f, 10);
					send(s, f, sizeof(f), 0);

					check = 0;
					while (check != 2)
					{
						cout << "Введите количество проектов, в которые Вы уже инвестируете:" << endl;

						check = check_i();
						break;
					}
					_itoa_s(check, f, 10);
					send(s, f, sizeof(f), 0);

					check = 0;
					while (check != 2)
					{
						cout << "Введите Ваш опыт работы на рынке:" << endl;

						check = check_i();
						break;
					}

					_itoa_s(check, f, 10);
					send(s, f, sizeof(f), 0);
					
					
					char login[20];
					char password[20];
					
					yyy = 0;
					while (yyy == 0) {
						yyy = 0;
						ex[0] = '\0';
						cout << "Введите логин:" << endl;
						enter_login(login);
						f[0] = '\0';
						//отправили логин
						strcpy(f, login);

						send(s, f, sizeof(f), 0);
						
						recv(s, ex, sizeof(ex), 0);//получили сообщение
						if (strcmp(ex, "0") == 0) {
							yyy = 1;
						}
						else {
							cout << "Такой логин уже существует:" << endl;
						}
					}
					cout << "Введите пароль:" << endl;
					enter_logpass(login, password);
					f[0] = '\0';
					strcpy(f, password);
					//отправили пароль
					send(s, f, sizeof(f), 0);
					break;
				}
				case 2: {
					char login1[20];
					char password1[20];
					int yyy1 = 0;
					system("cls");
					while (yyy1 == 0) {
						yyy1 = 0;
						ex[0] = '\0';
						
						cout << "Введите логин:" << endl;
						enter_login(login1);
						f[0] = '\0';
						//отправили логин
						strcpy(f, login1);

						send(s, f, sizeof(f), 0);

						recv(s, ex, sizeof(ex), 0);//получили сообщение
						if (strcmp(ex, "0") == 0) {
							yyy1 = 1;
						}
						else {
							cout << "Такого пользователя нет!" << endl;
						}
					}

					int yyy2 = 0;
					while (yyy2 == 0) {
						yyy2 = 0;
						ex[0] = '\0';
						cout << "Введите пароль:" << endl;
						enter_login(password1);
						f[0] = '\0';
						//отправили пароль
						strcpy(f, password1);

						send(s, f, sizeof(f), 0);

						recv(s, ex, sizeof(ex), 0);//получили сообщение
						if (strcmp(ex, "0") == 0) {
							yyy2 = 1;
						}
						else {
							cout << "Пароли не совпадают!" << endl;
						}
					}

					cout << "Вход выполнен успешно" << endl;
					while (t1 != 4) {
						
						recv(s, k, sizeof(k), 0);
						cout << k << endl;
						t1 = CheckChoice(1, 4);
						_itoa_s(t1, b, 10);
						send(s, b, sizeof(b), 0);
						recv(s, k, sizeof(k), 0);
						yyy1 = 0;

						t1 = atoi(k);
						switch (t1) {

						case 1: {
							system("cls");
							while (t2 != 5) {
								recv(s, k, sizeof(k), 0);
								cout << k << endl;
								t2 = CheckChoice(1, 5);
								_itoa_s(t2, b, 10);
								send(s, b, sizeof(b), 0);
								recv(s, k, sizeof(k), 0);
								t2 = atoi(k);
								switch (t2) {
								case 1: {
									system("cls");
									break;
								}
								case 2: {
									system("cls");
									break;
								}
								case 3: {
									system("cls");
									break;
								}
								case 4: {
									system("cls");
									break;
								}
								case 5: {
									system("cls");
									break;
								}
								}
							}
							t2 = 0;
							break;

						}
						case 2: {
							system("cls");
							for (int i = 0; i < 55; i++)
								cout << "-";
							cout << endl;
							cout << "|             Фамилия|       Имя|Капитал|Проекты| Стаж|" << endl;

							for (int i = 0; i < 55; i++)
								cout << "-";
							cout << endl;

							for (int i = 0; i < 55; i++)
								cout << "-";
							break;
						}
						case 3: {
							system("cls");
							break;
						}
						case 4: {
							system("cls");
							break;
						}

						}
					}
					t1 = 0;
					break;
				}
				case 3: {
					system("cls");
					break;

				}
				}
			}

			t444 = 0;
			break;
		}
		case 3: {
			system("cls");
			while (t1 != 4) {
				recv(s, k, sizeof(k), 0);
				cout << k << endl;
				t1 = CheckChoice(1, 4);
				_itoa_s(t1, b, 10);
				send(s, b, sizeof(b), 0);
				recv(s, k, sizeof(k), 0);
				t1 = atoi(k);
				switch (t1) {
				case 1: {
					system("cls");
					while (t2 != 5) {
						recv(s, k, sizeof(k), 0);
						cout << k << endl;
						t2 = CheckChoice(1, 5);
						_itoa_s(t2, b, 10);
						send(s, b, sizeof(b), 0);
						recv(s, k, sizeof(k), 0);
						t2 = atoi(k);
						switch (t1) {
						case 1: {
							system("cls");
							break;
						}
						case 2: {
							system("cls");
							break;
						}
						case 3: {
							system("cls");
							break;
						}
						case 4: {
							system("cls");
							break;
						}
						case 5: {
							system("cls");
							break;
						}
						}
					}
					t2 = 0;
					break;
				}
				case 2: {
					system("cls");
					break;
				}
				case 3: {
					system("cls");
					break;
				}
				case 4: {
					system("cls");
					break;
				}
				}
				system("cls");
			}
			t1 = 0;
			break;
		}
		case 4: {
			system("cls");
			WSACleanup();
			return 0;
		}
		}
		
	}
}
