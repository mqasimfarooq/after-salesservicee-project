#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <ctime>
#include <sstream>
#define s6 "\t\t\t\t\t\t"
#define s5 "\t\t\t\t\t"
#define s4 "\t\t\t\t"
#define s3 "\t\t\t"
#define s2 "\t\t"
#define s1 "\t"
#define s0 ""
#define sp0 ""
#define sp1 " "
#define sp2 "  "
#define sp3 "   "
#define sp4 "    "
#define sp5 "     "
#define nl endl
#define cyp "Choose your option : "
#include"payment.h"
#include"booking.h"
#include"user.h"
#include"userdashboard.h"
using namespace std;


class GUI {

private:
	string phonenum, password;
	userdashboard ud_obj;
public:
	int enter = 0;
	user returnuser()
	{
		return ud_obj.getuser();
	}
	GUI()
	{
		phonenum = "";
		password = "";
	}
	bool findexistingphone(string p)
	{
		ifstream file("logins\\login data.txt");
		string x, y;
		if (file.is_open() == false) { return 0; }
		while (file >> x >> y)
		{
			if (x == p)
			{
				return 0;
				break;
			}
		}
		return 1;
	}

	bool loginverification(string u, string p)
	{
		ifstream file("logins\\login data.txt");
		if (file.is_open())
		{
			string x, y;
			while (file >> x >> y)
			{
				if (x == u && y == p)
				{
					return 0;
					break;
				}
			}
			return 1;
		}
		else
		{
			cout << "\nNo User has been signed up yet\n";
			return 1;
		}

	}

	void userdetails()
	{
		ud_obj.showdetails();
	}

	void welcomescreen() {
		cout << "HELLO TO S&J MOTORS" << endl;

	}

	void signup()
	{
		string pnum = "xxxxxxxxxxx", name, email;
		char p[12], d[3], m[3], y[5];
		int tp = 0;
		cout << "Enter your phone number to signup to s&j motors app " << endl;
		cin >> pnum;
		while (findexistingphone(pnum) == 0)
		{
			if (findexistingphone(pnum) == 0)
			{
				cout << "Account already created for this phonenum \n ";
			}
			cout << "Enter your phone number to signup to s&j motors app " << endl;
			cin >> pnum;

		}
		while (pnum.size() != 11)
		{

			if (pnum.size() != 11)
			{
				cout << "Wrong length\n";
			}

			cout << "Enter your phone number to signup to s&j motors app " << endl;
			cin >> pnum;

		}
		phonenum = pnum;
		cout << "\nNow create a password" << endl;
		cin >> password;

		cout << "\nAdditional info.." << endl;
		cout << "\nEnter Name:" << endl;
		getline(cin, name);
		getline(cin, name);
		cout << "\nEnter Email:" << endl;
		cin >> email;
		while (tp < 1 || tp>31)
		{
			cout << "\nEnter Birth Day (between 1 and 31):" << endl;
			cin >> tp;
			if (tp < 1 || tp>31)
			{
				cout << "\nIncorrect data\n";
			}
		}
		std::string s = std::to_string(tp);
		memcpy(d, s.c_str(), 3);
		tp = 0;

		while (tp < 1 || tp>12)
		{
			cout << "\nEnter Birth Month (between 1 and 12):" << endl;
			cin >> tp;
			if (tp < 1 || tp>12)
			{
				cout << "\nIncorrect data\n";
			}
		}
		s = std::to_string(tp);
		memcpy(m, s.c_str(), 3);
		tp = 0;

		while (tp < 1800 || tp>2022)
		{
			cout << "\nEnter Birth Day (between 1800 and 2022):" << endl;
			cin >> tp;
			if (tp < 1 || tp>31)
			{
				cout << "\nIncorrect data\n";
			}
		}
		s = std::to_string(tp);
		memcpy(y, s.c_str(), 5);
		user temp(name, pnum.c_str(), email, d, m, y);
		userdashboard tmp(temp);
		ud_obj = tmp;
		ofstream file("logins\\login data.txt", ios::app);
		if (file.is_open() == false)
		{
			ofstream file("logins\\login data.txt");
		}
		if (file.is_open()) {
			file << phonenum << "\t";
			file << password << endl;
		}
		generateotp();



	}

	bool generateotp() {

		string str = "abcdefghijklmnopqrstuvwxyzABCD"
			"EFGHIJKLMNOPQRSTUVWXYZ0123456789";
		int n = str.length();

		// String to hold my OTP
		string OTP;
		int len = 8;
		for (int i = 1; i <= len; i++)
			OTP.push_back(str[rand() % n]);
		ofstream f("otp.txt");
		if (f.is_open()) {
			f << OTP << endl;
		}
		OTP.c_str();

		string t;
		ifstream w("otp.txt");
		if (w.is_open())
			getline(w, t);
		cout << " a otp code will be generated shortly" << endl;
		cout << endl;

		cout << "here is your generated otp code : " << t << endl;


		cout << "now enter the enter code displayed to you for verification" << endl;
		string s;
		cin >> s;
		cout << endl;

		if (s == t) {
			cout << "verification succesfull you have succesfully signed up" << endl;
			return true;
		}

		else {

			return false;
		}


	}


	bool login() {
		string u, p;
		cout << "You have reached login page enter username and password to continue" << endl;
		cin >> u;
		cin >> p;

		if (loginverification(u, p) == 0)
		{
			//generateotp();
			userdashboard tmp(u);
			ud_obj = tmp;
			return true;
		}
		else
		{
			return false;
		}
	}
};

class staff {
public:
	string name, ssn, sal, age, exp, casual, sick, study, parental, sdate, edate, days;


	staff() {
		casual = "20", sick = "15", study = "10", parental = "40"; days = "0";
	}
};

class workshopmanager {

public:

	void addUser()
	{
		staff e;
		cout << nl << s2 << "--- A D D  U S E R ---" << nl << nl;
		cout << s2 << sp2 << "Enter the ID : ";
		cin >> e.ssn;
		e.ssn.resize(8);
		cout << s2 << sp2 << "Enter the Name : ";
		cin >> e.name;
		e.name.resize(8);
		cout << s2 << sp2 << "Enter the Age : ";
		cin >> e.age;
		e.age.resize(8);
		cout << s2 << sp2 << "Enter the Salary : ";
		cin >> e.sal;
		e.sal.resize(8);
		cout << s2 << sp2 << "Enter the Experience : ";
		cin >> e.exp;
		e.exp.resize(8);
		fstream file1, file2, file3;
		file1.open("emp.txt", ios::binary | ios::app);
		file2.open("leave.txt", ios::binary | ios::app);
		file3.open("salary.txt", ios::binary | ios::app);
		if (!file1 || !file2) {
			system("cls");
			cout << s4 << "Error Occured!" << nl;
			return;
		}
		e.casual = e.casual + "/20-0", e.sick = e.sick + "/15-0", e.study = e.study + "/10-0", e.parental = e.parental + "/40-0";
		e.casual.resize(10), e.sick.resize(10), e.study.resize(10), e.parental.resize(10), e.sdate.resize(10), e.edate.resize(10), e.days.resize(5);
		file1 << "\t|" << e.ssn << "|\t" << e.name << "|" << e.age << "|" << e.sal << "|" << e.exp << "|" << nl;
		file2 << e.ssn << "|" << e.name << "|" << e.casual << "|" << e.sick << "|" << e.study << "|" << e.parental << "|" << e.sal << "|" << e.sdate << "|" << e.edate << "|" << e.days << "|" << nl;
		file3 << e.ssn << "|" << e.sal << "|" << nl;
		file1.close();
		file2.close();
		file3.close();

		cout << s4 << "User added successfully!" << nl << nl << nl;
	}

	void modUser()
	{
		char ch;
		string id, str;
		int found = 0, count = 0;
		fstream file1, file2;
		file1.open("emp.txt", ios::binary | ios::in);
		cout << nl << s2 << "--- M O D I F Y  U S E R ---" << nl << nl;
		cout << s2 << sp4 << "Enter Employee ID : ";
		cin >> id;
		id.resize(8);
		if (!file1) {
			system("cls");
			cout << s4 << "Error Occured" << nl;
			return;
		}
		int index = 5;
		while (file1) {
			file1.seekg(index, ios::beg);
			getline(file1, str, '|');

			if (str == id) {
				found = 1;
				break;
			}
			else {
				index += 51;
				str.clear();
				count++;
			}
		}
		file1.close();
		if (found == 1)
		{
		start:
			int ch, beg, end;
			string newstr, str;
			cout << s4 << "1. EDIT AGE" << nl;
			cout << s4 << "2. EDIT SALARY" << nl;
			cout << s4 << "3. EDIT EXPERIENCE" << nl << nl;
			cout << s4 << cyp;
			cin >> ch;
			cout << nl;
			if (ch == 1 || ch == 2 || ch == 3) {
				cout << s4 << "Enter the new value : ";
				cin >> newstr;
			}
			else
				goto start;
			newstr.resize(8);

			file1.open("emp.txt", ios::binary | ios::in);
			file2.open("temp.txt", ios::binary | ios::app);

			while (count--) {
				getline(file1, str);
				file2 << str << endl;
			}
			if (ch == 1)
				beg = 3, end = 2;
			else if (ch == 2)
				beg = 4, end = 1;
			else if (ch == 3)
				beg = 5, end = 0;
			for (int i = 0; i < beg; i++) {
				getline(file1, str, '|');
				file2 << str << "|";
			}

			file2 << newstr << "|";
			getline(file1, str, '|');
			for (int i = 0; i < end; i++) {
				getline(file1, str, '|');
				file2 << str << "|";
			}

			while (file1) {
				getline(file1, str);
				file2 << str;
				if (file1)
					file2 << endl;
			}
			file1.close();
			file2.close();
			cout << s4 << "Employee has been updated!" << nl << nl;
			char fn1[] = "emp.txt", fn2[] = "temp.txt";
			recover(fn1, fn2);


		}
		else
			cout << s2 << sp4 << "Employee not found!" << nl << nl;

	}
	void recover(char* fn1, char* fn2)
	{
		remove(fn1);
		rename(fn2, fn1);
	}

	void displayUsers()
	{
		string str;
		fstream file;
		file.open("emp.txt", ios::binary | ios::in);
		if (!file) {
			system("cls");
			cout << s4 << "Error Occured" << nl;
			return;
		}
		cout << nl << "\tEmployee ID" << s2 << "Name" << s2 << "Age" << s2 << "Salary" << s1 << sp2 << "Experience" << nl << nl;
		while (file) {
			getline(file, str, '|');
			cout << str;
		}
		file.close();
		int t = 80;
		cout << nl;
		while (t--)
			cout << "-";
		cout << nl << nl;
		file.close();
	}

	void modLeave()
	{
		string id, str;
		int found = 0, count = 0;
		fstream file1, file2;
		file1.open("leave.txt", ios::binary | ios::in);
		cout << nl << s2 << "--- A P P L Y  L E A V E ---" << nl << nl;
		cout << s2 << sp4 << "Enter the Employee ID : ";
		cin >> id;
		cout << nl;
		id.resize(8);
		if (!file1) {
			system("cls");
			cout << s4 << "Error Occured" << nl;
			return;
		}
		int index = 0;
		while (file1) {
			file1.seekg(index, ios::beg);
			getline(file1, str, '|');
			if (str == id) {
				found = 1;
				break;
			}
			else {
				index += 100;
				str.clear();
				count--;
			}
		}
		file1.close();
		if (found == 1)
		{
		start:
			string sdate, edate;
			int ch, com = 7, beg, end, nol, ex = 0, lea, tot, days = 0, leave, nod;
			float sal, per;
			cout << s2 << sp4 << "1. CASUAL LEAVE" << nl;
			cout << s2 << sp4 << "2. SICK LEAVE" << nl;
			cout << s2 << sp4 << "3. STUDY LEAVE" << nl;
			cout << s2 << sp4 << "4. PARENTAL LEAVE" << nl << nl;
			cout << s0 << cyp;
			cin >> ch;
			cout << "=========================================================";
			cout << nl;
			if (ch == 1) { beg = 0, end = 3, tot = 20, per = .08; }
			else if (ch == 2) { beg = 1, end = 2, tot = 15, per = 0.05; }
			else if (ch == 3) { beg = 2, end = 1, tot = 10, per = 0.03; }
			else if (ch == 4) { beg = 3, end = 0, tot = 40, per = 0.15; }
			file1.open("leave.txt", ios::binary | ios::in);
			file2.open("temp1.txt", ios::binary | ios::app);
			while (count--) {
				getline(file1, str);
				file2 << str << endl;
			}
			for (int i = 0; i < 2; i++) {
				getline(file1, str, '|');
				file2 << str << "|";
			}
			for (int i = 0; i < beg; i++) {
				getline(file1, str, '|');
				file2 << str << "|";
			}
			cout << s2 << sp4 << "Enter the number of leaves : ";
			cin >> nol;
			getline(file1, str, '|');
			stringstream buf1(str);
			buf1 >> lea;
			leave = lea;
			if (lea - nol < 0)
				days = abs(lea - nol);
			lea = lea - nol;
			if (days != 0)
				lea = 0;
			fstream buf2;
			buf2.open("mod.txt", ios::binary | ios::out);
			buf2 << lea << "/" << tot << "-" << days;
			buf2.close();
			buf2.open("mod.txt", ios::binary | ios::in);
			getline(buf2, str);
			buf2.close();
			remove("mod.txt");
			str.resize(10);
			file2 << str << "|";
			for (int i = 0; i < end; i++) {
				getline(file1, str, '|');
				file2 << str << "|";
			}
			getline(file1, str, '|');
			sal = getSal(id);

			if (leave - nol < 0)
				sal = sal - (float)sal * per * abs(tot - leave);

			ostringstream buf4;
			buf4 << sal;
			str = buf4.str();;
			str.resize(8);
			file2 << str << "|";

			cout << s2 << sp4 << "Enter the Start Date(dd/mm/yyyy) : ";
			cin >> sdate;
			cout << s2 << sp4 << "Enter the End Date(dd/mm/yyy) : ";
			cin >> edate;
			sdate.resize(10);
			edate.resize(10);
			file2 << sdate << "|";
			file2 << edate << "|";
			for (int i = 0; i < 3; i++)
				getline(file1, str, '|');

			stringstream buf5(str);
			buf5 >> nod;
			nod = nod + nol;

			ostringstream buf6;
			buf6 << nod;
			str = buf6.str();
			str.resize(5);
			file2 << str << "|";

			while (file1) {
				getline(file1, str);
				file2 << str;
				if (file1)
					file2 << endl;
			}
			file1.close();
			file2.close();
			char fn1[] = "leave.txt", fn2[] = "temp1.txt";
			recover(fn1, fn2);
			cout << s4 << "Leave updated!" << nl << nl;
		}
		else
			cout << s4 << "User not found!" << nl << nl;
	}

	void dispLeave()
	{
		string str;
		fstream file;
		file.open("leave.txt", ios::binary | ios::in);
		if (!file) {
			system("cls");
			cout << s4 << "Error Occured" << nl;
			return;
		}
		cout << nl << "Employee ID\t" << "Name\t\t" << "CL(20)\t\t" << "SL(15)\t\t" << "STL(10)\t\t" << "PL(40)\t\t" << "Salary\t\t" << "Start Date" << sp2 << sp2 << "End Date" << sp2 << sp2 << "NoofLeaves" << nl << nl;
		while (file) {
			getline(file, str, '|');
			cout << str << "\t";
		}
		cout << nl << nl;
		cout << "Note : This table shows remaining leaves." << nl << sp2 << "CL : CASUAL LEAVE" << nl << sp2 << "SL : SICK LEAVESEAVE" << nl << sp2 << "STL : STUDY LEAVE" << nl << sp2 << "PL : PARENTAL LEAVE" << nl << sp2 << "Number after '-' sign indicates extra leaves." << nl << nl;
		file.close();
	}

	void deleteLeave()
	{
		string id, str;
		int found = 0, count = 0;
		fstream file1, file2;
		file1.open("leave.txt", ios::binary | ios::in);
		cout << s2 << "--- D E L E T E  L E A V E ---" << nl << nl;
		cout << s2 << sp4 << "Enter the Employee ID to delete : ";
		cin >> id;
		id.resize(8);
		if (!file1) {
			system("cls");
			cout << s2 << sp4 << "Error Occured" << nl;
			return;
		}
		int index = 0;
		while (file1) {
			file1.seekg(index, ios::beg);
			getline(file1, str, '|');
			if (str == id) {
				found = 1;
				break;
			}
			else {
				index += 100;
				str.clear();
				count = count + 1;
			}
		}
		file1.close();
		if (found == 1)
		{
			file1.open("leave.txt", ios::binary | ios::in);
			file2.open("temp1.txt", ios::binary | ios::app);
			while (count > 0) {
				getline(file1, str);
				file2 << str;
				count = count - 1;
				if (count > 0)
					file2 << nl;
			}
			for (int i = 0; i < 2; i++) {
				getline(file1, str, '|');
				file2 << str << "|";
			}
			str = "20/20-0"; str.resize(10);
			file2 << str << "|";
			str = "15/15-0"; str.resize(10);
			file2 << str << "|";
			str = "10/10-0"; str.resize(10);
			file2 << str << "|";
			str = "40/40-0"; str.resize(10);
			file2 << str << "|";
			float sal = getSal(id);
			ostringstream buf;
			buf << sal;
			str = buf.str();
			str.resize(8);
			file2 << str << "|";
			str = "-"; str.resize(10);
			file2 << str << "|" << str << "|";
			str = "0"; str.resize(10);
			file2 << str << "|";
			for (int i = 0; i < 8; i++)
				getline(file1, str, '|');
			while (file1) {
				getline(file1, str);
				file2 << str;
				if (file1)
					file2 << endl;
			}
			file1.close();
			file2.close();
			char fn1[] = "leave.txt", fn2[] = "temp1.txt";
			recover(fn1, fn2);
		}
		else
			cout << s2 << sp4 << "User not found!" << nl;
	}

	float getSal(string id)
	{
		fstream file;
		float sal;
		string str;
		file.open("salary.txt", ios::binary | ios::in);
		if (!file) {
			system("cls");
			cout << s4 << "Error Occured" << nl;
			return 0;
		}
		while (file) {
			getline(file, str, '|');
			str.resize(8);
			if (str == id)
				break;
		}
		str.clear();
		getline(file, str, '|');
		stringstream buf(str);
		buf >> sal;
		file.close();
		return sal;
	}
	void searchLeave()
	{
		string id, str;
		cout << nl << s2 << "--- S E A R C H  L E A V E ---" << nl << nl;
		cout << s2 << sp4 << "Enter the Employee ID : ";
		cin >> id;
		id.resize(8);
		fstream file;
		file.open("leave.txt", ios::binary | ios::in);
		if (!file) {
			system("cls");
			cout << s4 << "Error Occured" << nl;
			return;
		}
		while (file) {
			getline(file, str, '|');
			str.resize(8);
			if (str == id) {
				break;
			}
		}
		cout << nl << "Employee ID\t" << "Name\t\t" << "CL(20)\t\t" << "SL(15)\t\t" << "STL(10)\t\t" << "PL(40)\t\t" << "Salary\t\t" << "Start Date" << sp2 << sp2 << "End Date" << sp2 << sp2 << "NoofLeaves" << nl << nl;
		cout << str << "\t";
		for (int i = 0; i < 9; i++) {
			getline(file, str, '|');
			cout << str << "\t";
		}
		file.close();
		cout << nl << nl;
	}









};

class Payment {
protected:
	float tax;
	float amount;
	int   carno;
	string cvc;
	int   expmon;
	int   expyear;

public:
	//constructor
	Payment() {
		tax = 1.16;
		amount = 2000;
	}

	//amount after tax
	float finalamount(int amount) {
		return amount * tax;
	}

	//input card details
	void file_handle() {
		fstream out;
		out.open("payment.txt");
		out << carno << " " << cvc << " " << expmon << "/" << expyear << endl;
	}

	//Displaying reciept of the payment
	void make_reciept() {
		cout << "Thankyou for your payment, Your reciept is: " << endl << "Total amount payed " << finalamount(amount) << " by cardno " << carno;
	}

};

class online_payment : public Payment {

public:

	//online payment dashboard
	void onlinepayment() {
		int expiry = 0;
		cout << "ONLINE PAYMENT OPTION \nThank you for choosing online payment\n\nYour total bill is " << finalamount(amount) << endl;

		do {
			expiry = 0;
			cout << "Enter Credit Card NO:";
			cin >> carno;
			cout << "Enter 3 digit CVC number:";
			cin >> cvc;
			if (cvc.length() != 3) { cout << "Wrong cvc code"; expiry = 1; break; }
			cout << "Enter expiry date of card which is in the format mm/yyyy";
			//checking for expirty date
			cout << "\n Please enter the month of expiry date: ";
			cin >> expmon;
			cout << "Please enter the year of expiry date: ";
			cin >> expyear;
			if (expmon < 12 and expyear <= 2022) {
				cout << "Your card is expired: please enter again\n";
				expiry = 1;
			}
		} while (expiry == 1);
		if (expiry == 0) {
			file_handle();
			cout << endl << endl;
			make_reciept();
		}
	}

};

class onspot_payment : public Payment {
public:
	void payonspot() {
		cout << "you have chosen Payment on spot \n\n Your total bill is " << finalamount(amount) << endl;
		make_reciept();
	}


};

int main()
{
	int opt = -5;
	GUI obj;
	obj.welcomescreen();
	while (opt < 0 || opt>2)
	{
		cout << "\nPlease choose 0-exit 1-sign up 2-login 3-exit\n";
		cin >> opt;
		if (opt < 0 || opt>2)
		{
			cout << "\n*choose a correct option*\n";
		}
	}
	if (opt == 0)
	{

	}
	if (opt == 1)
	{
		int optt = -5;
		obj.signup();
		while (optt < 0 || optt>3)
		{
			cout << "Please choose 0-Exit 1-Enter Average \n2-Book Appointment 3-View Todays Predicted Mileage\n";
			cin >> optt;
			if (optt < 0 || optt>3)
			{
				cout << "\n*choose a correct option*\n";
			}
		}
		if (optt == 0)
		{

		}
		user X = obj.returnuser(); //loads user into a user variable
		if (optt == 1)
		{
			float avg;
			cout << "Enter Todays Mileage: ";
			cin >> avg;
			X.enteravg(avg);

			cout << "Projected Average for tommorow is: " << X.getmileage();
		}
		if (optt == 2)
		{
			float cost = 0;
			int opttt = 0;
			int exit = 9999;
			while (exit != 0)
			{
				while (opttt < 1 || opttt>5)
				{
					cout << "Please choose the car part that needs repair 1-Engine($1000) 2-Door($50) 3-Windows($40) 4-Interior($15) 5-Tyres($100)\n";
					cin >> opttt;
					if (opttt < 1 || opttt>5)
					{
						cout << "\n*choose a correct option*\n";
					}
				}
				switch (opttt)
				{
				case 1:
					cost += 1000;
					break;
				case 2:
					cost += 50;
					break;
				case 3:
					cost += 40;
					break;
				case 4:
					cost += 15;
					break;
				case 5:
					cost += 100;
					break;
				}

				cout << "Enter 0 to Exit, Any other number to continue";
				cin >> exit;
			}
		}
		if (optt == 3)
		{
			cout << "Projected Average for today is: " << X.getmileage();
		}
	}
	if (opt == 2)
	{
		int optt = -5;
		obj.login();
		obj.userdetails();
		while (optt < 0 || optt>3)
		{
			cout << "Please choose 1-Enter Average 2-Book Appointment\n";
			cin >> optt;
			if (optt < 0 || optt>3)
			{
				cout << "\n*choose a correct option*\n";
			}
		}
		if (optt == 0)
		{

		}
		user X = obj.returnuser(); //loads user into a user variable
		if (optt == 1)
		{
			float avg;
			cout << "Enter Todays Mileage: ";
			cin >> avg;
			X.enteravg(avg);

			cout << "Projected Average for tommorow is: " << X.getmileage();
		}
		if (optt == 2)
		{
			float cost = 0;
			int opttt = 0;
			int exit = 9999;
			while (exit != 0)
			{
				while (opttt < 1 || opttt>5)
				{
					cout << "Please choose the car part that needs repair 1-Engine($1000) 2-Door($50) 3-Windows($40) 4-Interior($15) 5-Tyres($100)\n";
					cin >> opttt;
					if (opttt < 1 || opttt>5)
					{
						cout << "\n*choose a correct option*\n";
					}
				}
				switch (opttt)
				{
				case 1:
					cost += 1000;
					break;
				case 2:
					cost += 50;
					break;
				case 3:
					cost += 40;
					break;
				case 4:
					cost += 15;
					break;
				case 5:
					cost += 100;
					break;
				}

				cout << "Enter 0 to Exit, Any other number to continue";
				cin >> exit;
			}

		}
		if (optt == 3)
		{
			cout << "Projected Average for tommorow is: " << X.getmileage();
		}
	}
	cout << endl;



	int a;
	online_payment o1;
	onspot_payment op;
	cout << "Welcome to Payment section" << endl;
	cout << "Press 1 for online payment \nPress 2 for onspot payment: \n\n";
	cin >> a;
	if (a == 1) { o1.onlinepayment(); }
	if (a == 2) { op.payonspot(); }

	workshopmanager c;
	while (true) {
	start:
		int ch;
		cout << "=========================================================" << nl;
		cout << s0 << "------ L E A V E  M A N A G E M E N T  S Y S T E M ------" << nl;
		cout << "=========================================================    " << nl << nl;
		cout << s2 << "--- M A I N  M E N U ---" << nl << nl;
		cout << s2 << sp4 << "1. APPLY LEAVE" << nl;
		cout << s2 << sp4 << "2. DELETE LEAVE" << nl;
		cout << s2 << sp4 << "3. SEARCH LEAVE" << nl;
		cout << s2 << sp4 << "4. MODIFY LEAVE" << nl;
		cout << s2 << sp4 << "5. DISPLAY ALL LEAVES" << nl;
		cout << s2 << sp4 << "6. USER MANAGEMENT" << nl;
		cout << s2 << sp4 << "7. EXIT" << nl;
		cout << nl << s0 << cyp;
		cin >> ch;
		cout << "=========================================================";
		cout << nl;
		switch (ch)
		{
		case 1:
			c.modLeave();
			break;
		case 2:
			c.deleteLeave();
			break;
		case 3:
			c.searchLeave();
			break;
		case 4:
			c.modLeave();
			break;
		case 5:
			c.dispLeave();
			break;
		case 6:
			int ch1;
			cout << nl << s2 << "--- U S E R  M E N U ---" << nl << nl;
			cout << s2 << sp4 << "1. ADD employee" << nl << s2 << sp4 << "2. MODIFY user" << nl;
			cout << s2 << sp4 << "3. SHOW ALL employee" << nl;
			cout << nl << s0 << cyp;
			cin >> ch1;
			cout << "=========================================================";
			cout << nl;
			if (ch1 == 1)
				c.addUser();
			else if (ch1 == 2)
				c.modUser();
			else if (ch1 == 3)
				c.displayUsers();
			break;

		case 7:
			exit(0);

		default: goto start;
		}
	}

	return 0;
}