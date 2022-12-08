#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <ctime>
#include <sstream>
class user
{
private:
	string name;
	char phone[12];
	string email;
	char birth_day[3];
	char birth_month[3];
	char birth_year[5];
	float projectedmileage;
	vector<_booking> userbookings;
public:
	user()
	{
		name = "NULL";
		memcpy(phone, "00000000000", 12);
		memcpy(birth_day,"00", 3);
		memcpy(birth_month, "00", 3);
		memcpy(birth_year, "0000", 5);
		projectedmileage = 0;
	}

	void load_data(string p)
	{
		ifstream fin;
		fin.open("users\\" + p + " userdata.txt");
		if (fin.is_open() == true) //if a record exists
		{
			cout << "open\n";
			string s;
			fin >> s;
			memcpy(phone, s.c_str(),12);
			fin >> email;
			getline(fin,name);
			getline(fin, name);
			fin >> s;
			cout << "*" << name << endl;
			memcpy(birth_day, s.c_str(), 3);
			fin >> s;
			memcpy(birth_month, s.c_str(), 3);
			fin >> s;
			memcpy(birth_year, s.c_str(), 5);
			getline(fin, s);
			string a, b, c, d, e,f;//a=date,b=time,c=tax,d=amount,e=cardno,f=cvv
			while (fin >> a >> b >> c >> d >> e>>f)
			{
				float tx;
				float amt;
				char cno[26];
				char _dt[12];
				char _tm[6];
				char cv[4];
				memcpy(_dt, a.c_str(), 12);
				memcpy(_tm, b.c_str(), 6);
				cout << c;
				tx=std::stof(c);
				amt= std::stof(d);
				memcpy(cno, e.c_str(), 26);
				memcpy(cv, f.c_str(), 4);
				_payment temp(tx,amt,cno,cv);
				_booking tempx(_dt, _tm, temp);
				userbookings.push_back(tempx);
			}
		}
		else
		{
			cout << "Error: Data not available";
		}
	}

	void save_data()
	{
		string p = phone;
		string bd = birth_day;
		string bm = birth_month;
		string by = birth_year;
		std::string av = std::to_string(projectedmileage);

		ofstream fout;
		fout.open("users\\" + p + " userdata.txt");
		fout << endl << p << " " << email << "\n" << name << endl << bd << " " << bm << " " << by << endl << av << endl;
		fout << "Payment and Booking History:";
		
		for (auto it = begin(userbookings); it != end(userbookings); ++it)
		{
			_payment temp = it->getpaymentinfo();
			fout << it->getdate() << " " << it->gettime()<<"\t"<<temp.gettax()<<" "<<temp.getamt() << " "<<temp.getcno()<<temp.getcv() << endl;
		}
			
		
	}


	user(string n, const char p[12],string ml, const char d[3], const char m[3], const char y[5])
	{
		name = n;
		email = ml;
		memcpy(phone, p, 12);
		memcpy(birth_day, d, 3);
		memcpy(birth_month, m, 3);
		memcpy(birth_year, y, 5);
		projectedmileage = 0;
		save_data();
	}


	void showuserdetails()
	{
		cout << "-\n\n\nname:" << name << endl << "phone:" << phone << endl << "DOB:" << birth_day << " - " << birth_month << " - " << birth_year << endl;
		cout << "Projected Mileage for Today: ";
		calculateavg();
		if (projectedmileage != 0)
		{
			cout << projectedmileage;
		}
		else
		{
			cout << "*No existing data*";
		}
	}

	void calculateavg()
	{
		ifstream fin;
		fin.open("userrecords\\" + name + " avgrecord.txt");
		if (fin.is_open() == true) //if a record exists
		{

			string x;
			int count = 0;
			float temp;
			float sum = 0;
			while (fin >> x)
			{
				temp = std::stof(x);
				count++;
				sum = sum + temp;
			}
			projectedmileage = sum / count;

		}
	}

	void enteravg(float avg)
	{
		ifstream fin;
		fin.open("userrecords\\"+name + " avgrecord.txt");
		if (fin.is_open() == true) //if a record exists
		{

			ofstream fout;
			fout.open("userrecords\\" + name + " avgrecord.txt", ios::app);
			std::string s = std::to_string(avg);
			fout << s << " ";
			calculateavg();// Made a seperate fucntion to calculate mileage
		}
		else //if no record exists
		{
			ofstream fout;
			fout.open("userrecords\\" + name + " avgrecord.txt");
			std::string s = std::to_string(avg);
			fout << s << " ";
			projectedmileage = avg;
		}
	}

	void booking(float cost)
	{
		_booking obj;
		obj.bookappointment(cost);
		userbookings.push_back(obj);
	}

	float getmileage()
	{
		calculateavg();
		return projectedmileage;
	}
	void payment()
	{

	}

};