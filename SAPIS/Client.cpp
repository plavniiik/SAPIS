#define _AFXDLL
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <iostream>
#include <conio.h>
#include <iomanip>

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
int ValueCheck_2(char* stroka)
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

int CheckChoice2(int a, int b) //сужает целые числа до определённого диапазона (от a до b)
{
	int choice = 0;
	while (choice == 0) {
		choice = CheckNumber();
		if ((choice < a) || (choice > b)) {
			cout << "У вас есть только варианты: да и нет. Выберите цифру: 1/2!" << endl;
			choice = 0;
		}
	}
	return choice;
}


int Check_stazh(int a, int b) //сужает целые числа до определённого диапазона (от a до b)
{
	int choice = 0;
	while (choice == 0) {
		choice = CheckNumber();
		if ((choice < a) || (choice > b)) {
			cout << "К сожалению, невозможно работать с таким опытом. " << endl;
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
	char b[500], f[500], k[500], ex[35], buf[500], nuf[500];
	
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
		case 1: {
			char login2[20];
			char password2[20];
			int try_1 = 0;
			system("cls");
			f[0] = '\0';
			recv(s, f, sizeof(f), 0);

			if (strcmp(f, "0") == 0) {
				

				cout << "Администратор еще не зарегистрирован. Давайте пройдем регистрацию." << endl;
				cout << endl;

				cout << "Введите логин:" << endl;
				enter_login(login2);
				f[0] = '\0';
				//отправили логин
				strcpy_s(f, login2);

				send(s, f, sizeof(f), 0);
				cout << endl;
				cout << "Введите пароль:" << endl;
				enter_logpass(login2, password2);
				f[0] = '\0';
				strcpy_s(f, password2);
				//отправили пароль
				send(s, f, sizeof(f), 0);
				cout << endl;
			}
			else {
				cout << "Вход в качестве администратора." << endl;
				cout << endl;
				
				int yyy1 = 0;
				
				while (yyy1 == 0) {
					yyy1 = 0;
					ex[0] = '\0';
					cout << endl;
					cout << "Введите логин:" << endl;
					enter_login(login2);
					f[0] = '\0';
					//отправили логин
					strcpy(f, login2);

					send(s, f, sizeof(f), 0);

					recv(s, ex, sizeof(ex), 0);//получили сообщение
					if (strcmp(ex, "0") == 0) {
						yyy1 = 1;
					}
					else {
						cout << "Логин неверный!" << endl;
						cout << endl;
					}

				}

			int yyy2 = 0;
			
				while (yyy2 == 0) {
					yyy2 = 0;
					ex[0] = '\0';
					cout << endl;
					cout << "Введите пароль:" << endl;
					enter_logpass(login2, password2);
					f[0] = '\0';
					//отправили пароль
					strcpy(f, password2);

					send(s, f, sizeof(f), 0);

					recv(s, ex, sizeof(ex), 0);//получили сообщение
					if (strcmp(ex, "0") == 0) {
						yyy2 = 1;
					}
					else {
						cout << endl;
						cout << "Пароли не совпадают!" << endl;
						cout << endl;
						
					}
				}
				cout << endl;
			cout << "Вход выполнен успешно" << endl;
			cout << endl;
			system("pause");
			system("cls");
			}

			while (t1 != 5) {
				recv(s, k, sizeof(k), 0);
				cout << k << endl;
				t1=CheckChoice(1, 5);
				_itoa_s(t1, b, 10);
				int check457 = 0;
				send(s, b, sizeof(b), 0);
				recv(s, k, sizeof(k), 0);
				t1 = atoi(k);
				switch (t1) {
				case 1: {
					//работа с экпертами
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
							b[0] = '\0';
							f[0] = '\0';
							strcpy_s(f, "*");
							strcpy_s(b, "f");

							while (strcmp(b, f) != 0) {
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "*") != 0) { cout << b << endl; }
							}

							f[0] = '\0';
							break;
						}
						case 2: {
							system("cls");

							k[0] = '\0';
							recv(s, k, sizeof(k), 0);

							if (strcmp(k, "0") == 0) {
							
								cout << "Давайте зарегистрируем эксперта." << endl;
								cout << endl;

								int check = 0;
								f[0] = '\0';
								while (check != 2)
								{
									cout << "Введите фамилию" << endl;
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
								f[0] = '\0';
								while (check != 2)
								{
									cout << "Введите имя:" << endl;
									cin.getline(f, 20, '\n');
									check = ValueCheck_2(f);
									if (check == 1) {
										cout << "Неверный ввод, попробуйте ещё раз!" << endl;
										cout << endl;
									}
								}
								send(s, f, sizeof(f), 0);


								check = 0;
								f[0] = '\0';
								while (check != 2)
								{
									cout << "Введите стаж работы:" << endl;

									check = Check_stazh(1,55);
									break;
								}

								_itoa_s(check, f, 10);
								send(s, f, sizeof(f), 0);

								check = 0;
								f[0] = '\0';
								while (check != 2)
								{
									cout << "Введите вашу должность:" << endl;
									cin.getline(f, 50, '\n');
									check = ValueCheck_2(f);
									if (check == 1) {
										cout << "Неверный ввод, попробуйте ещё раз!" << endl;
										cout << endl;
									}
								}
								send(s, f, sizeof(f), 0);

								check = 0;
								f[0] = '\0';
								while (check == 0) {
									cout << "Введите свою электронную почту" << endl;
									cin.getline(f, 50, '\n');
									bool valid = true;
									int all_presents = 0;
									string suitable_symbols = "-_.@"; // допустимые символы помимо латинских букв и цифр

									for (int i = 0; f[i] != '\0'; i++)
									{
										if (!isalpha(f[i]) && !isdigit(f[i]) && suitable_symbols.find(f[i]) == std::string::npos) { // наличие недопустимого символа
											valid = false; break;
										}
										if (i > 0 && f[i] == '.' && f[i - 1] == '.') { valid = false; break; } // две точки подряд
										else if (i > 0 && f[i] == '@' && !all_presents) { all_presents = 1; } // наличие @
										else if (f[i] == '@' && all_presents) { valid = false; break; } // наличие двух @ в строчке
										else if ((isalpha(f[i]) || isdigit(f[i])) && all_presents == 1) { all_presents = 2; } // наличие буквы или цифры после @
										else if (f[i] == '.' && all_presents == 2) { all_presents = 3; } // наличие точки после символа( который после @ )
										else if (isalpha(f[i]) && all_presents == 3 && f[i + 2] == '\0') { all_presents = 4; } // наличие буквы в конце строчки
									}
									if (valid && all_presents == 4) { check = 1; }
									else { cout << "Почта введена неверно!\n"; }
								}
								send(s, f, sizeof(f), 0);
								
								/*while (check != 2)
								{
									cout << "Введите почту:" << endl;
									cin.getline(f, 50, '\n');
									check = ValueCheck_2(f);
									if (check == 1) {
										cout << "Неверный ввод, попробуйте ещё раз!" << endl;
										cout << endl;
									}
								}*/

								char login[20];
								char password[20];
								f[0] = '\0';
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
							}
							else {
								cout << "Уже существует три эксперта. К сожалению больше нельзя!" << endl;
							}

							break;
						}
						case 3: {
							system("cls");
							//удаление эксперта
							b[0] = '\0';
							f[0] = '\0';
							strcpy_s(f, "*");
							strcpy_s(b, "f");

							while (strcmp(b, f) != 0) {
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "*") != 0) { cout << b << endl; }
							}

							f[0] = '\0';
							cout << endl;

							cout << "Введите фамилию эксперта которого хотитет удалить." << endl;

							check457 = 0;
							while (check457 != 2)
							{
								cin.getline(f, 20, '\n');
								check457 = ValueCheck_2(f);
								f[strlen(f)] = '\0';
								if (check457 == 1) {
									cout << "Неверный ввод, попробуйте ещё раз!" << endl;
									cout << endl;
								}
							}
							send(s, f, sizeof(f), 0);


							strcpy_s(f, "*");
							strcpy_s(b, "f");

							while (strcmp(b, f) != 0) {
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "1") == 0) {
									cout << "Такого эксперта не существует!" << endl;
									strcpy_s(b, f);
								}
								if (strcmp(b, "*") != 0) { cout << b << endl; }
							}
							b[0] = '\0';
							cout << "Эксперт успешно удален" << endl;
							
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
					//раздел работы с инвесторами
					system("cls");
					while (t2 != 5) {
						recv(s, k, sizeof(k), 0);//получили меню
						cout << k << endl;
						t2 = CheckChoice(1,5);
						_itoa_s(t2, b, 10);
						send(s, b, sizeof(b), 0);
						recv(s, k, sizeof(k), 0);
						//cout << k << endl;
						int check456 = 0;
						t2 = atoi(k);
						switch (t2) {
							
						case 1: {
							system("cls");
							k[0] = '\0';
							
							while (t3 != 4) {
								recv(s, k, sizeof(k), 0);
								cout << k << endl;
								k[0] = '\0';
								t3 = CheckChoice(1, 4);
								_itoa_s(t3, b, 10);
								send(s, b, sizeof(b), 0);
								recv(s, k, sizeof(k), 0);
								int check = 0;
								t3 = atoi(k);
								int checu = 1;
								switch(t3){

								case 1:
									system("cls");
									cout << "Сoртировка" << endl;
									b[0] = '\0';
									f[0] = '\0';
									strcpy_s(f, "*");
									strcpy_s(b, "f");

									while (strcmp(b, f) != 0) {
										b[0] = '\0';
										recv(s, b, sizeof(b), 0);
										if (strcmp(b, "*") != 0) { cout << b << endl; }
									}
									
									f[0] = '\0';

									break;
								case 2:
									system("cls");
									cout << "Фильтрация" << endl;
									cout << "Вы можете отфильтровать список по опыту работы на рынке." << endl;
									check = 0;
									while (check != 2)
									{
										cout << "Введите минимальное значение" << endl;
										check = check_i();
										break;
									}
									_itoa_s(check, f, 10);
									send(s, f, sizeof(f), 0);

									
									check = 0;
									while (check != 2)
									{
										cout << "Введите максимальное значение" << endl;
										check = check_i();
										break;
									}
									_itoa_s(check, f, 10);
									send(s, f, sizeof(f), 0);


									strcpy_s(f, "*");
									strcpy_s(b, "f");

									while (strcmp(b, f) != 0) {
										b[0] = '\0';
										recv(s, b, sizeof(b), 0);
										if (strcmp(b, "1") == 0) {
											cout << "Такого инвестора не существует!" << endl;
											strcpy_s(b, f);
										}
										if (strcmp(b, "*") != 0) { cout << b << endl; }
									}

									b[0] = '\0';
									
									

									break;
								case 3:

									system("cls");
									cout << "Поиск" << endl;
									
									check456 = 0;

									while (check456 != 2)
									{
										cout << "Введите фамилию для поиска" << endl;
										cin.getline(f, 20, '\n');
										check456 = ValueCheck_2(f);
										f[strlen(f)] = '\0';
										if (check456 == 1) {
											cout << "Неверный ввод, попробуйте ещё раз!" << endl;
											cout << endl;
										}
									}
									send(s, f, sizeof(f), 0);


									strcpy_s(f, "*");
									strcpy_s(b, "f");

									while (strcmp(b, f) != 0) {
										b[0] = '\0';
										recv(s, b, sizeof(b), 0);
										if (strcmp(b, "1") == 0) {
											cout << "Такого инвестора не существует!" << endl;
											strcpy_s(b, f);
										}
										if (strcmp(b, "*") != 0) { cout << b << endl; }
									}

									b[0] = '\0';

									break;
								case 4:
									system("cls");
									break;
								}
							}
							break;
						}
						case 2: {
							system("cls");
							//удаление инвестора
							b[0] = '\0';
							f[0] = '\0';
							strcpy_s(f, "*");
							strcpy_s(b, "f");

							while (strcmp(b, f) != 0) {
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "*") != 0) { cout << b << endl; }
							}

							f[0] = '\0';
							cout << endl;

							cout << "Введите фамилию инвестора которого хотите удалить." << endl;

							check457 = 0;
							while (check457 != 2)
							{
								cin.getline(f, 20, '\n');
								check457 = ValueCheck_2(f);
								f[strlen(f)] = '\0';
								if (check457 == 1) {
									cout << "Неверный ввод, попробуйте ещё раз!" << endl;
									cout << endl;
								}
							}
							send(s, f, sizeof(f), 0);


							strcpy_s(f, "*");
							strcpy_s(b, "f");

							while (strcmp(b, f) != 0) {
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "1") == 0) {
									cout << "Такого инвестора не существует!" << endl;
									strcpy_s(b, f);
								}
								if (strcmp(b, "*") != 0) { cout << b << endl; }
							}
							b[0] = '\0';
							cout << "Эксперт успешно удален" << endl;

							break;
						}
						case 3: {
							system("cls");
							//заключение договра с инвестором
							b[0] = '\0';
							f[0] = '\0';
							strcpy_s(f, "*");
							strcpy_s(b, "f");

							while (strcmp(b, f) != 0) {
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "*") != 0) { cout << b << endl; }
							}

							f[0] = '\0';
							cout << endl;

							cout << "Введите фамилию, с которым хотите заключить договор." << endl;

							check457 = 0;
							while (check457 != 2)
							{
								cin.getline(f, 20, '\n');
								check457 = ValueCheck_2(f);
								f[strlen(f)] = '\0';
								if (check457 == 1) {
									cout << "Неверный ввод, попробуйте ещё раз!" << endl;
									cout << endl;
								}
							}
							send(s, f, sizeof(f), 0);


							strcpy_s(f, "*");
							strcpy_s(b, "f");

							while (strcmp(b, f) != 0) {
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "1") == 0) {
									cout << "Такого инвестора не существует!" << endl;
									strcpy_s(b, f);
								}
								if (strcmp(b, "*") != 0) { cout << b << endl; }
							}
							b[0] = '\0';

							cout << endl;
							cout << "Заявка отправлена на расcмотрение инвестору!"<<endl;

							break;
						}
						case 4: {
							system("cls");
							//расторжение договора с инвестором
							b[0] = '\0';
							f[0] = '\0';
							strcpy_s(f, "*");
							strcpy_s(b, "f");

							while (strcmp(b, f) != 0) {
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "*") != 0) { cout << b << endl; }
							}

							f[0] = '\0';
							//cout << endl;

							cout << "Введите фамилию иневестора, с которым хотите расторгнуть договор." << endl;

							check457 = 0;
							while (check457 != 2)
							{
								cin.getline(f, 20, '\n');
								check457 = ValueCheck_2(f);
								f[strlen(f)] = '\0';
								if (check457 == 1) {
									cout << "Неверный ввод, попробуйте ещё раз!" << endl;
									cout << endl;
								}
							}
							send(s, f, sizeof(f), 0);


							strcpy_s(f, "*");
							strcpy_s(b, "f");

							while (strcmp(b, f) != 0) {
								b[0] = '\0';
								recv(s, b, sizeof(b), 0);
								if (strcmp(b, "1") == 0) {
									cout << "Такого инвестора нет!" << endl;
									strcpy_s(b, f);
								}
								if (strcmp(b, "*") != 0) { cout << b << endl; }
							}
							b[0] = '\0';

							cout << endl;
							cout << "Заявка на рассторжение!" << endl;

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
				//меню изменения логина и пароля
				case 3: {
					system("cls");
					int yyy1 = 0;
					cout << "Чтобы изменить логин/пароль, пройдите повторную авторизацию." << endl;
					while (yyy1 == 0) {
						yyy1 = 0;
						ex[0] = '\0';
						cout << endl;
						cout << "Введите логин:" << endl;
						enter_login(login2);
						f[0] = '\0';
						//отправили логин
						strcpy(f, login2);

						send(s, f, sizeof(f), 0);

						recv(s, ex, sizeof(ex), 0);//получили сообщение
						if (strcmp(ex, "0") == 0) {
							yyy1 = 1;
						}
						else {
							cout << "Логин неверный!" << endl;
							cout << endl;
						}

					}

					int yyy2 = 0;

					while (yyy2 == 0) {
						yyy2 = 0;
						ex[0] = '\0';
						cout << endl;
						cout << "Введите пароль:" << endl;
						enter_logpass(login2, password2);
						f[0] = '\0';
						//отправили пароль
						strcpy(f, password2);

						send(s, f, sizeof(f), 0);

						recv(s, ex, sizeof(ex), 0);//получили сообщение
						if (strcmp(ex, "0") == 0) {
							yyy2 = 1;
						}
						else {
							cout << endl;
							cout << "Пароли не совпадают!" << endl;
							cout << endl;

						}
					}
					cout << endl;
					cout << "Подтверждение прошло успешно!" << endl;
					system("pause");
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
							//изменение логина
							cout << "Введите логин:" << endl;
							enter_login(login2);
							f[0] = '\0';
							//отправили логин
							strcpy_s(f, login2);
							send(s, f, sizeof(f), 0);
							cout << endl;
							break;
						}
						case 2: {
							system("cls");
							//изменение пароля

							cout << "Введите пароль:" << endl;
							enter_logpass(login2, password2);
							f[0] = '\0';
							strcpy_s(f, password2);
							//отправили пароль
							send(s, f, sizeof(f), 0);
							cout << endl;

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
					//меню работы с компанией
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
							int check = 0;
							system("cls");
							k[0] = '\0';

							recv(s, k, sizeof(k), 0);
							
							if (strcmp(k, "0")==0) {
								cout << "Давайте зарегистрируем компанию!" << endl;
								cout << endl;
								cout << "Введите название компании." << endl;
								cout << endl;
								cin.getline(f, 20, '\n');
								f[strlen(f)] = '\0';
								send(s, f, sizeof(f), 0);

								cout << "Введите название выпускаемого продукта." << endl;
								cout << endl;
								cin.getline(f, 20, '\n');
								f[strlen(f)] = '\0';
								
								send(s, f, sizeof(f), 0);

								check = 0;
								while (check != 2)
								{
									cout << "Введите фамилию ответственного за заключение договора с инвесторами." << endl;
									cout << endl;
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
								float cap;
								while (true)
								{
									cout << "Введите желаемую сумму капитала, в которой требуется компания" << endl;
									cap = check_float();
									break;
								}

								sprintf(f, "%.3f", cap);
								
								send(s, f, sizeof(f), 0);


							}

							else {
								cout << "Данные о компании уже существуют. Удалите их, прежде чем записать новые данные" << endl;
								cout << endl;
							}



							break;
						}
						case 2: {
							system("cls");
							k[0] = '\0';
							recv(s, k, sizeof(k), 0);

							if (strcmp(k, "0") == 0) {
								cout << "Нам нечего удалять :(" << endl;
								cout << endl;
							}

							else {
								cout << "Данные о компании удалены. Не забудьте записать новые данные." << endl;
								cout << endl;
							}

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

						check = Check_stazh(1, 55);
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
						enter_logpass(login1,password1);
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
							//редактирование инвестора
							system("cls");
							while (t2 != 5) {

								//показ таблицы
								char F[500];
								F[0] = '\0';
								char I[500];
								I[0] = '\0';
								char cap[500];
								cap[0] = '\0';
								char pr[500];
								pr[0] = '\0';
								char exp[500];
								exp[0] = '\0';
								system("cls");
								for (int i = 0; i < 55; i++)
									cout << "-";
								cout << endl;
								cout << "|             Фамилия|       Имя|Капитал|Проекты| Стаж|" << endl;
								for (int i = 0; i < 55; i++)
									cout << "-";
								cout << endl;
								recv(s, F, sizeof(k), 0);
								recv(s, I, sizeof(k), 0);
								recv(s, cap, sizeof(k), 0);
								
								recv(s, pr, sizeof(k), 0);
								recv(s, exp, sizeof(k), 0);

								cout << "|" << setw(20) << F << "|" << setw(10) << I << "|" << setw(7) << cap << "|" << setw(7) << pr << "|" << setw(5) << exp << "|" << endl;
								for (int i = 0; i < 55; i++)
									cout << "-";
								cout << endl;

								//конец показа таблицы

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

									break;
								}
								case 2: {
									system("cls");
									
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

									break;
								}
								case 3: {
									system("cls");

									int check = 0;
									while (check != 2)
									{
										cout << "Введите количество проектов, в которые Вы уже инвестируете:" << endl;

										check = check_i();
										break;
									}
									_itoa_s(check, f, 10);
									send(s, f, sizeof(f), 0);
									break;
								}
								case 4: {
									system("cls");

									int check = 0;
									while (check != 2)
									{
										cout << "Введите Ваш опыт работы на рынке:" << endl;

										check = Check_stazh(1, 55);
										break;
									}

									_itoa_s(check, f, 10);
									send(s, f, sizeof(f), 0);

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

							char F[500];
							F[0] = '\0';
							char I[500];
							I[0] = '\0';
							char cap[500];
							cap[0] = '\0';
							char pr[500];
							pr[0] = '\0';
							char exp[500];
							exp[0] = '\0';
							system("cls");
							for (int i = 0; i < 55; i++)
								cout << "-";
							cout << endl;
							cout << "|             Фамилия|       Имя|Капитал|Проекты| Стаж|" << endl;
							for (int i = 0; i < 55; i++)
								cout << "-";
							cout << endl;
							recv(s, F, sizeof(k), 0);
							recv(s, I, sizeof(k), 0);
							recv(s, cap, sizeof(k), 0);
							recv(s, pr, sizeof(k), 0);
							recv(s, exp, sizeof(k), 0);

							cout << "|"<< setw(20) << F << "|" << setw(10) << I << "|" << setw(7) << cap << "|" << setw(7) << pr << "|" << setw(5) << exp << "|" << endl;
							for (int i = 0; i < 55; i++)
								cout << "-";
							cout << endl;
							
							system("pause");
							break;
						}
						case 3: {
							system("cls");
							char mes[500];
							char mes2[500];
							mes[0] = '\0';
							int t_4 = 0;
							k[0] = '\0';
							b[0] = '\0';
							while (t_4 != 4) {
								recv(s, k, sizeof(k), 0);
								cout << k << endl;
								t_4 = CheckChoice(1, 4);
								_itoa_s(t_4, b, 10);
								send(s, b, sizeof(b), 0);
								recv(s, k, sizeof(k), 0);
								t_4 = atoi(k);
								switch (t_4){
								f[0] = '\0';
								case 1: {
									int choiceee;
									recv(s, mes, sizeof(k), 0);
									if (strcmp(mes, "0") == 0) {
										cout << "У вас есть завка на подписание договора!" << endl;
										cout << endl;
										cout << "Вы хотите одобрить заявку?\n1 - Да\n2 - Нет." << endl;
										choiceee = CheckChoice2(1, 2);
										if (choiceee == 1) {
											mes2[0] = '\0';
											strcpy(mes2, "1");
											send(s, mes2, sizeof(mes2), 0);
										}

										else {
											mes2[0] = '\0';
											strcpy(mes2, "2");
											send(s, mes2, sizeof(mes2), 0);
										}

									}

									else {
										cout << "К сожалению, у вас нет заявок на подписание договора!" << endl;
										cout << endl;
									}
									break;
								}
								case 2: {
									system("cls");
									int choiceee;
									recv(s, mes, sizeof(k), 0);
									if (strcmp(mes, "0") == 0) {
										cout << "У вас есть завка на рассторжение договора!" << endl;
										cout << endl;
										cout << "Вы хотите одобрить заявку?\n1 - Да\n2 - Нет." << endl;
										choiceee = CheckChoice2(1, 2);
										if (choiceee == 1) {
											mes2[0] = '\0';
											strcpy(mes2, "1");
											send(s, mes2, sizeof(mes2), 0);
										}

										else {
											mes2[0] = '\0';
											strcpy(mes2, "2");
											send(s, mes2, sizeof(mes2), 0);
										}

									}

									else {
										cout << "У вас нет заявки на рассторжение договора!" << endl;
										cout << endl;
									}
									break;
								}
								case 3: {
									system("cls");
									
									recv(s, mes, sizeof(k), 0);
									if (strcmp(mes, "0") == 0) {
										cout << "У вас есть подписанные договоры!" << endl;
									}
									else {
										cout << "К сожалению, у вас нет подписанных договоров!" << endl;
										cout << endl;
									}
									
									break;
								}
								case 4: {
									system("cls");
									break;
								}

							}
							}
							t_4 = 0;
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
