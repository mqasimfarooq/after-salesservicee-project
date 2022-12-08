#pragma once
#include <ctime>
struct tm newtime;

void fix(char * d, char* m, char* y, char* hr, char* mi) //fixes date and time data to follow correct format
{
	time_t now = time(0);
	localtime_s(&newtime, &now);
	
	std::string s = std::to_string(1 + newtime.tm_hour);
	if (s.size() == 1)//hour
	{
		hr[0] = '0';
		hr[1] = s[0];
	}
	else
	{
		hr[0] = s[0];
		hr[1] = s[1];
	}

	s = std::to_string(1 + newtime.tm_min);
	if (s.size() == 1)//min
	{
		mi[0] = '0';
		mi[1] = s[0];
	}
	else
	{
		hr[0] = s[0];
		hr[1] = s[1];
	}

	s = std::to_string(newtime.tm_mday);
	if (s.size() == 1)//day
	{
		hr[0] = '0';
		hr[1] = s[0];
	}
	else
	{
		hr[0] = s[0];
		hr[1] = s[1];
	}

	s = std::to_string(1 + newtime.tm_mon);
	if (s.size() == 1)//month
	{
		mi[0] = '0';
		mi[1] = s[0];
	}
	else
	{
		hr[0] = s[0];
		hr[1] = s[1];
	}

	s = std::to_string(1900 + newtime.tm_year);//year
	y[0]=s[0];
	y[1]=s[1];
	y[2]=s[2];
	y[3]=s[3];

}



class _booking
{
private:
	char _date[12];
	char _time[6];
	_payment userpayment;
public:

	char* getdate()
	{
		return _date;
	}
	char* gettime()
	{
		return _time;
	}

	_payment getpaymentinfo()
	{
		return userpayment;
	}


	_booking()
	{
		memcpy(_date, "00-00-0000", 12);
		memcpy(_time, "00:00", 6);
	}

	_booking(const char dt[12], const char tm[6],_payment obj)
	{
		memcpy(_date, dt, 12);
		memcpy(_time, tm, 6);
		userpayment = obj;
	}

	bool checkstaffavailability()
	{
		return true;
	}

	void bookappointment(float cost)
	{
		if (checkstaffavailability() == true) 
		{
			char d[3], m[3], y[5], hr[3], mi[3];
			fix(d, m, y, hr, mi);
			_payment obj;
			_booking(d + '-' + m[0] + m[1] + '-' + y[0] + y[1] + y[2] + y[3], hr + ';' + mi[0] + mi[1],obj);
			cout << "Appointment Booked for: " << d + '-' + m[0] + m[1] + '-' + y[0] + y[1] + y[2] + y[3] << endl << hr + ';' + mi[0] + mi[1] << endl;

			string cno;
			int opt=0;
			while (opt < 1 || opt>2)
			{
				cout << "Please enter an option; 1-On Spot Payment 2-Card Payment"; cin >> opt;
			}
			if (opt == 1)
			{
				float t = 16.00;
				cout << "Booking Complete :)\n";
				_payment temp(t, cost, "     On Spot Payment     ","xxx");
				userpayment = temp;
				userpayment.onspotpayment();
			}
			if (opt == 2)
			{
				float t = 16.00;
				string tmp="";
				while (tmp.size() != 25)
				{
					cout << "Enter Card Number:";
					cin >> tmp;
					if (tmp.size() != 25)
					{
						cout << "\n Card Number Length Should be 25";
					}
				}
				string x = " ";
				while (x.size() != 3)
				{
					cout << "\nEnter CVV";
					cin >> x;
					if (x.size() != 3) { cout << "Length of CVV should be 3"; }
				}
				_payment temp(t, cost, tmp.c_str(),x.c_str());
				userpayment = temp;
				userpayment.onlinepayment();
				cout << "\nBooking Complete :)\n";
				
			}


			
		}
	}

};