#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

enum Type { Info = 0, Warning, Error, All };
class Singleton
{
private:
	Singleton() {}
	Singleton(const Singleton&) = delete;
	Singleton& operator=(Singleton&) = delete;
public:
	static Singleton& GetInstance() {
		static Singleton instance;
		return instance;
	}

	void LogInfo(string msg)
	{
		ofstream file("Log.txt", ios::binary | ios::app);
		if (!file.is_open())
		{
			cerr << ">>>>> Error of opening file !>>>>>\n";
		}
		else
		{
			SYSTEMTIME t;
			GetLocalTime(&t);
			file << "INFO: " << t.wDay << "/" << t.wMonth << "/" << t.wYear << " " << t.wHour << ":" << t.wMinute << endl;
			file.close();
		}
	}
	void LogWarning(string msg)
	{
		ofstream file("Log.txt", ios::binary | ios::app);
		if (!file.is_open())
		{
			cerr << ">>>>> Error of opening file !>>>>>\n";
		}
		else
		{
			SYSTEMTIME t;
			GetLocalTime(&t);
			file << "WARNING: " << t.wDay << "/" << t.wMonth << "/" << t.wYear << " " << t.wHour << ":" << t.wMinute << endl;
			file.close();
		}
	}
	void LogError(string msg)
	{
		ofstream file("Log.txt", ios::binary | ios::app);
		if (!file.is_open())
		{
			cerr << ">>>>> Error of opening file !>>>>>\n";
		}
		else
		{
			SYSTEMTIME t;
			GetLocalTime(&t);
			file << "ERROR: " << t.wDay << "/" << t.wMonth << "/" << t.wYear << " " << t.wHour << ":" << t.wMinute << endl;
			file.close();
		}
	}
	void ShowLogList(Type type)
	{
		string msg;
		string type_;
		ifstream file("Log.txt");
		if (!file.is_open())
		{
			cerr << ">>>>> Error of opening file !>>>>>\n";
		}
		else
		{
			while (!file.eof())
			{
				if (type == Type::Info)
				{
					file >> type_;
					getline(file, msg);
					if (type_ == "INFO:")
					{
						cout << type_ << " " << msg << endl;
					}
				}
				else if (type == Type::Warning)
				{
					file >> type_;
					getline(file, msg);
					if (type_ == "WARNING:")
					{
						cout << type_ << " " << msg << endl;
					}
				}
				else if (type == Type::Error)
				{
					file >> type_;
					getline(file, msg);
					if (type_ == "Error:")
					{
						cout << type_ << " " << msg << endl;
					}
				}
				else
				{
					getline(file, msg);
					cout << msg << endl;
				}
			}
		}
	}
};

int main()
{
	Singleton& single = Singleton::GetInstance();
	Singleton::GetInstance().LogInfo("gjerwgwopghrh");
	Singleton::GetInstance().LogWarning("rjrtgtrg");
	Singleton::GetInstance().LogError("erkger[gke");
	Singleton::GetInstance().ShowLogList(Warning);
	system("pause");
}