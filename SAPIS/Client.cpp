#define _AFXDLL
#define _WINSOCK_DEPRECATED_NO_WARNINGS
//#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <iostream>

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	WORD wVersionRequested;
	WSADATA wsaData;
	int err, t, t1 = 0, t2 = 0, t3 = 0;
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
	char b[500], f[500], k[500];
	while (1) {
		recv(s, b, sizeof(b), 0);
		recv(s, f, sizeof(f), 0);
		cout << b;
		cout << f;
		cin >> t;
		_itoa_s(t, b, 10);
		send(s, b, sizeof(b), 0);
		recv(s, k, sizeof(k), 0);
		t = atoi(k);
		switch (t) {
		case 1: {
			recv(s, k, sizeof(k), 0);
			cout << k << endl;
			while (t1 != 4) {
				recv(s, k, sizeof(k), 0);
				cout << k << endl;
				cin >> t1;
				_itoa_s(t1, b, 10);
				send(s, b, sizeof(b), 0);
				recv(s, k, sizeof(k), 0);
				t1 = atoi(k);
				switch (t1) {
				case 1: {
					while (t2 != 3) {
						recv(s, k, sizeof(k), 0);
						cout << k << endl;
						cin >> t2;
						_itoa_s(t2, b, 10);
						send(s, b, sizeof(b), 0);
						recv(s, k, sizeof(k), 0);
						t2 = atoi(k);
						switch (t2) {
						case 1: {
							break;
						}
						case 2: {
							break;
						}
						case 3: {
							break;
						}
						case 4: {
							break;
						}
						case 5: {
							break;
						}
						}
					}
					t2 = 0;
					break;
				}
				case 2: {
					while (t2 != 6) {
						recv(s, k, sizeof(k), 0);
						cout << k << endl;
						cin >> t2;
						_itoa_s(t2, b, 10);
						send(s, b, sizeof(b), 0);
						recv(s, k, sizeof(k), 0);
						t2 = atoi(k);
						switch (t2) {
						case 1: {
							while (t3 != 3) {
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
							break;
						}
						case 3: {
							break;
						}
						case 4: {
							break;
						}
						}
						}
					}
					t2 = 0;
					break;
				}
				case 3: {
					while (t2 != 3) {
						recv(s, k, sizeof(k), 0);
						cout << k << endl;
						cin >> t2;
						_itoa_s(t2, b, 10);
						send(s, b, sizeof(b), 0);
						recv(s, k, sizeof(k), 0);
						t2 = atoi(k);
						switch (t2) {
						case 1: {
							break;
						}
						case 2: {
							break;
						}
						case 3: {
							break;
						}

						}
					}
					t2 = 0;
					break;
				}
				case 4: {
					break;
				}
				}
			}
			t1 = 0;
			break;
		}
		case 2: {
			while (t1 != 4) {
				recv(s, k, sizeof(k), 0);
				cout << k << endl;
				cin >> t1;
				_itoa_s(t1, b, 10);
				send(s, b, sizeof(b), 0);
				recv(s, k, sizeof(k), 0);
				t1 = atoi(k);
				switch (t1) {
				case 1: {
					break;
				}
				case 2: {
					break;
				}
				case 3: {
					break;
				}
				case 4: {
					break;
				}
				case 5: {
					break;
				}

				}
			}
			t1 = 0;
			break;
		}
		case 3: {
			while (t1 != 3) {
				recv(s, k, sizeof(k), 0);
				cout << k << endl;
				cin >> t1;
				_itoa_s(t1, b, 10);
				send(s, b, sizeof(b), 0);
				recv(s, k, sizeof(k), 0);
				t1 = atoi(k);
				switch (t1) {
				case 1: {
					while (t2 != 5) {
						recv(s, k, sizeof(k), 0);
						cout << k << endl;
						cin >> t2;
						_itoa_s(t2, b, 10);
						send(s, b, sizeof(b), 0);
						recv(s, k, sizeof(k), 0);
						t2 = atoi(k);
						switch (t1) {
						case 1: {
							break;
						}
						case 2: {
							break;
						}
						case 3: {
							break;
						}
						case 4: {
							break;
						}
						case 5: {
							break;
						}
						}
					}
					t2 = 0;
					break;
				}
				case 2: {
					break;
				}
				case 3: {
					break;
				}
				case 4: {
					break;
				}
				}
			}
			t1 = 0;
			break;
		}
		case 4: {
			WSACleanup();
			return 0;
		}
		}
	}
}