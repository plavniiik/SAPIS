#pragma once
#include "account.h"

#define MAX 30
class Cinema_Place
{
protected:
	int seats; //все места
	int saving_seats; //занятые места
	void enter_seats(); //ввод количества мест
public:
	int get_saving_seats() { return saving_seats; } //получение занятых мест
	int get_seats() { return seats; } //получение мест
	void change_seats(int); //изменение кол-ва занятых мест
	Cinema_Place() :saving_seats(0) {
		seats = 0;
		saving_seats = 0;

	} //конструктор
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
	char name_film[MAX]; //название сеанса
	char genre[MAX]; //жанр
	
	void enter_genre(); //ввод жанра
	void change_genre();
	void enter_name_film(); //ввод названия
	void enter_date(); //ввод даты
public:
	char* get_name_film() { return name_film; } //получение названия

};

class Ticket : public Film
{
protected:
	int price; //цена
	void enter_price(); //ввод цены
public:
	void set(); //установка сведений о билете
	friend istream& operator >>(istream&, Ticket&); //перегрузка ввода
	friend ostream& operator <<(ostream&, Ticket&); //перегрузка вывода
	bool operator ==(char*); //перегрузка оператора сравнения
	Ticket(const Ticket&); //конструктор копирования
	Ticket() {}; //конструктор по умолчанию
	void print_head(); //вывод шапки таблицы
	void print_table(list<Ticket>); //вывод списка билетов
	void readticketsinfile(list<Ticket>); //запись билетов в файл
	void readticketsinfile2(list<Ticket> tickets);
	void readticketsfromfile(list<Ticket>&); //чтение билетов из файла
	void del_fields(list<Ticket>&); //удаление билетов
	void change_fields(list<Ticket>&); //редактирование билета
	void del_one_field(list<Ticket>&); //удаление одного билета
	int cursor_table(list<Ticket>); //навигация по списку билетов
	
	int get_price() { return price; } //получение цены
};

class Booked_ticket : public Ticket
{
	char client[17]; //имя клиента
	int count; //количество билетов
	int row;//номер места занятого

public:

	Booked_ticket() {
		for (int i = 0; i < 17; i++) {
			client[i] = 'p';
		}
		count = 0;
		row = 0;

	}; //конструтор

	Booked_ticket(Ticket, char*, int, int);  //конструктор с параметрами
	void show_order(list<Booked_ticket>); //вывести чек
	void readordersinfile(list<Booked_ticket>); //запись заказов в файл
	void readordersinfile2(list<Booked_ticket> orders);
	void readordersfromfile(list<Booked_ticket>&); //чтение заказов из файла
	void order_head(); //вывод шапки списка заказов
	void print_orders(list<Booked_ticket>); //вывод списка всех заказов
	friend ostream& operator <<(ostream&, Booked_ticket&); //перегрузка вывода
	void print_user_orders(list<Booked_ticket>, list<Booked_ticket>, char*); //вывод заказов клиента
	int get_row() { return row; }
};