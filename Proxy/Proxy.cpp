#include <iostream>
#include <ctime>
#include <fstream>
#include <windows.h>

using namespace std;


class DataBase
{
private:
	string connectionString = "database.txt";
	bool isConnected = false;

public:
	bool Connect()
	{
		return (rand() % 10) < 6; // immitates 60% good connection, aka. very bad
	}
	void Log(string msg)
	{
		ofstream file(connectionString, std::ios::app);
		if (file.is_open())
		{
			SYSTEMTIME t;
			GetLocalTime(&t);
			file << msg << " - " << t.wDay << "/" << t.wMonth << "/" << t.wYear << " " << t.wHour << ":" << t.wMinute << endl;;
		}
	}
};

class DataBaseProxy
{
private:
	DataBase* _database = new DataBase();

	void EnsureConnectedWithDatabase()
	{
		if (_database == nullptr)
		{
			_database = new DataBase();
		}
	}

public:
	DataBaseProxy() { }
	void Log(string msg)
	{
		EnsureConnectedWithDatabase();
		if (_database->Connect())
			_database->Log(msg);
		else
		{
			cout << "No conections\n";
			ofstream file("localTempDatabase.txt", ios::app);
			if (file.is_open())
			{
				SYSTEMTIME t;
				GetLocalTime(&t);
				file << msg << " - " << t.wDay << "/" << t.wMonth << "/" << t.wYear << " " << t.wHour << ":" << t.wMinute << endl;
			}
		}
	}
};

void main()
{
	srand(time(0));
	DataBaseProxy* proxy = new DataBaseProxy;
	string STRING;
	for (size_t i = 0; i < 5; i++)
	{
		cout << "Enter message ";
		cin >> STRING;
		proxy->Log(STRING);
	}
	system("pause");
}