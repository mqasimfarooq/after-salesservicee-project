#pragma once
class _payment
{
private:
	float tax;
	float amount;
	char cardno[26];
	char cvv[4];
public:
	_payment()
	{
		tax = 0;
		amount = 0;
		memcpy(cardno, "0000000000000000000000000", 26);
		memcpy(cvv, "000", 4);
	}

	_payment(float t, float b, const char cno[26],const char cv[4])
	{
		tax = t;
		amount = b;
		memcpy(cardno, cno, 26);
		memcpy(cvv, cv, 4);
	}

	float gettax()
	{
		return tax;
	}
	float getamt()
	{
		return amount;
	}
	char * getcno()
	{
		return cardno;
	}
	char* getcv()
	{
		return cvv;
	}

	float applytax()
	{
		return float(amount+float(amount*float(tax / 100)));
	}
	void onlinepayment()
	{
		
		cout << "payable amount before tax: " << amount << endl;
		cout << "tax amount: " << tax << endl;
		cout << "your total payable amount is: " << applytax() << endl;
		
		creditusercard();
		cout << "\n*Amount credited*\n";
	}
	void onspotpayment()
	{
		cout << "\nPlease pay upon arrival.";
	}
	bool creditusercard()
	{
		
		ifstream fin;
		fin.open("payment\\payment gateway.txt");
		if (fin.is_open() == true)// * all payments made will have their card no and cvv added to text file, if any same card number isentered again another time but different cvv payment fails, if a new cardno is added payment is succesful and new addition is made to text file
		{

			string inp1,inp2,cn="x", cv="x";
			while (fin >> inp1>>inp2)
			{
				if (strcmp(cardno, inp1.c_str()) == 0)
				{
					cn = inp1;
					cv = inp2;
				}
			}
			if (cn == "x")
			{
				ofstream fout;
				fout.open("payment\\payment gateway.txt");
				fout <<endl<< cardno << " " << cvv;
				return 1;
			}
			else
			{
				if (strcmp(cvv, cv.c_str()) == 0)
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}
		}
		else 
		{
			ofstream fout;
			fout.open("payment\\payment gateway.txt");
			fout << cardno << " " << cvv;
			return 1;
		}

	}
};