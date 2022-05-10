#pragma once
#include "account.h"

#define MAX 30
class Cinema_Place
{
protected:
	int seats; //��� �����
	int saving_seats; //������� �����
	void enter_seats(); //���� ���������� ����
public:
	int get_saving_seats() { return saving_seats; } //��������� ������� ����
	int get_seats() { return seats; } //��������� ����
	void change_seats(int); //��������� ���-�� ������� ����
	Cinema_Place() :saving_seats(0) {
		seats = 0;
		saving_seats = 0;

	} //�����������
	Cinema_Place(const Cinema_Place& obj) {
		this->seats = obj.seats;
		this->saving_seats = obj.saving_seats;
		for (int i = 0; i < 6; i++) {

		}
	}
};

class Film : public Cinema_Place

{
protected:
	char name_film[MAX]; //�������� ������
	char genre[MAX]; //����
	
	void enter_genre(); //���� �����
	void change_genre();
	void enter_name_film(); //���� ��������
	void enter_date(); //���� ����
public:
	char* get_name_film() { return name_film; } //��������� ��������

};

class Ticket : public Film
{
protected:
	int price; //����
	void enter_price(); //���� ����
public:
	void set(); //��������� �������� � ������
	friend istream& operator >>(istream&, Ticket&); //���������� �����
	friend ostream& operator <<(ostream&, Ticket&); //���������� ������
	bool operator ==(char*); //���������� ��������� ���������
	Ticket(const Ticket&); //����������� �����������
	Ticket() {}; //����������� �� ���������
	void print_head(); //����� ����� �������
	void print_table(list<Ticket>); //����� ������ �������
	void readticketsinfile(list<Ticket>); //������ ������� � ����
	void readticketsinfile2(list<Ticket> tickets);
	void readticketsfromfile(list<Ticket>&); //������ ������� �� �����
	void del_fields(list<Ticket>&); //�������� �������
	void change_fields(list<Ticket>&); //�������������� ������
	void del_one_field(list<Ticket>&); //�������� ������ ������
	int cursor_table(list<Ticket>); //��������� �� ������ �������
	
	int get_price() { return price; } //��������� ����
};

class Booked_ticket : public Ticket
{
	char client[17]; //��� �������
	int count; //���������� �������
	int row;//����� ����� ��������

public:

	Booked_ticket() {
		for (int i = 0; i < 17; i++) {
			client[i] = 'p';
		}
		count = 0;
		row = 0;

	}; //����������

	Booked_ticket(Ticket, char*, int, int);  //����������� � �����������
	void show_order(list<Booked_ticket>); //������� ���
	void readordersinfile(list<Booked_ticket>); //������ ������� � ����
	void readordersinfile2(list<Booked_ticket> orders);
	void readordersfromfile(list<Booked_ticket>&); //������ ������� �� �����
	void order_head(); //����� ����� ������ �������
	void print_orders(list<Booked_ticket>); //����� ������ ���� �������
	friend ostream& operator <<(ostream&, Booked_ticket&); //���������� ������
	void print_user_orders(list<Booked_ticket>, list<Booked_ticket>, char*); //����� ������� �������
	int get_row() { return row; }
};