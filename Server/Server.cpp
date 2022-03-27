#define _AFXDLL  
#include <iostream>
#include <afx.h>  
#include <winsock2.h>
#include <process.h> 
#include <string.h>
#include <fstream>

using namespace std;
CFile f;
CFileException ex;



void mailWorking(void* newS) {
	int c, c1 = 0, c2 = 0, c3 = 0;
	int flag = 0;
	char p[500], com[200], k[500], m[500];
	com[0] = '\0'; p[0] = '\0'; k[0] = '\0'; m[0] = '\0';
	cout << "Сервер работает.\n";
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
			send((SOCKET)newS, p, sizeof(p), 0);
			while (c1 != 4) {
				strcpy_s(k, "Меню администратора:\n 1 - Раздел работы с инвесторами \n 2 - Раздел работы с экспертами \n 3 - Изменить пароль и/или логин;\n 4 - Главное меню.\n ");
				send((SOCKET)newS, k, sizeof(k), 0);
				recv((SOCKET)newS, m, sizeof(m), 0);
				c1 = atoi(m);
				switch (c1) {
				case 1: {
					strcpy_s(p, "1");
					send((SOCKET)newS, p, sizeof(p), 0);
					while (c2 != 3) {
						strcpy_s(p, "Работа с инвесторами:\n 1 - Просмотреть данные об инвесторах \n 2 - Удалить инвестора \n 3 - Заключить договор \n 4 - Расторгнуть договор \n 5 - Выход.");
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
					while (c2 != 6) {
						strcpy_s(p, "Работа с экспертами:\n1 - Просмотреть информацию об экспертах \n2 -  Удалить эксперта \n3 - Просомтреть оценки экспертов\n4 - Выход.\n");
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
						case 6: {
							strcpy_s(p, "6");
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
					while (c2 != 3) {
						strcpy_s(p, "Меню изменения пароля и/или логина:\n 1 - Изменить пароль \n 2 - Изменить логин;\n 3 - Выход.\n");
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
				case 4: {
					strcpy_s(p, "4");
					send((SOCKET)newS, p, sizeof(p), 0);
					break;
				}
				}
			}
			c1 = 0;
			break;
		}
		case 2: {
			strcpy_s(p, "2");
			send((SOCKET)newS, p, sizeof(p), 0);
			p[0] = '\0';
			while (c1 != 4) {
				strcpy_s(k, "Меню инвестора:\n 1 - Ввести свои инвестиционные данные \n 2 - Редактировать свои данные \n 3 - Удалить данные \n 4 - Просмотреть договоры \n 5 -Выход. ");
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
		case 3: {
			strcpy_s(p, "3");
			send((SOCKET)newS, p, sizeof(p), 0);
			while (c1 != 3) {
				strcpy_s(k, "Меню эксперта:\n 1 - Информация об экспертах \n 2 - Выставить оценки для инвесторов \n 3 - Выбрать наилучший вариант\n 4 - Выход. ");
				send((SOCKET)newS, k, sizeof(k), 0);
				recv((SOCKET)newS, m, sizeof(m), 0);
				c1 = atoi(m);
				switch (c1) {
				case 1: {
					strcpy_s(p, "1");
					send((SOCKET)newS, p, sizeof(p), 0);
					while (c2 != 5) {
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

		///(c = recv((SOCKET)newS, p, sizeof(p), 0) != 0)
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

