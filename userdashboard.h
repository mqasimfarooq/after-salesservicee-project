#pragma once
class userdashboard
{
private:
	user U;
public:
	userdashboard()
	{

	}
	userdashboard(user obj)
	{
		U = obj;
	}
	userdashboard(string p)
	{
		U.load_data(p);
	}
	user getuser()
	{
		return U;
	}

	void showdetails()
	{
		U.showuserdetails();
	}
	void mileagegraph();
	void maintennancehistory();
	void popupnotification();
	void showmileage()
	{
		cout << U.getmileage();
	}
	void showpredictedcost();
};

