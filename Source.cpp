#include <iostream>
#include <string>
#include<cstdlib> 
using namespace std;
int number_of(string str1, string str2)
{
	int n, f;
	f = 0;
	string x;
	x = str1;
	int s;
	s = str1.length();
	for (int i = 0; i <= s; i++)
	{
		n = x.find(str2);
		if (n >= 0)
		{
			x = x.erase(0, (n + str2.length()));
			f++;
		}
	}
	return f;
}
int main()
{

	int month_days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int days_in_between , no_of_students, no_of_courses, IDn[100], minID, maxID, no_of_halls, dayn[10], monn[10], yearn[10];
	string  coursesdata, studentsdata, str1, str2, str3, IDs[100], operation[10], halls, hall[10], date[10], days[10], mons[10], years[10], student[100], course[10];
	halls = " ";
	cin >> coursesdata >> studentsdata;
	str1 = coursesdata.erase(0, (coursesdata.find("=") + 2));
	str2 = studentsdata.erase(0, (studentsdata.find("=") + 2));
	no_of_courses = number_of(coursesdata, ";") + 1;
	no_of_students = number_of(studentsdata, ";") + 1;
	for (int i = 0; i < no_of_courses; i++)
	{
		if (i< no_of_courses - 1)
		{
			course[i] = str1.substr(0, (str1.find(";")));
			str1 = str1.erase(0, (str1.find(";") + 1));
		}
		else
		{
			course[i] = str1.substr(0, (str1.find("]")));
		}

	}
	for (int i = 0; i < no_of_students; i++)
	{
		if (i< no_of_students - 1)
		{
			student[i] = str2.substr(0, (str2.find(";")));
			str2 = str2.erase(0, (str2.find(";") + 1));
		}
		else
		{
			student[i] = str2.substr(0, (str2.find("]")));
		}

	}
	for (int i = 0; i < no_of_students; i++)
	{
		IDs[i] = student[i].substr(0, (student[i].find(",")));
		IDn[i] = atof(IDs[i].c_str());
	}
	maxID = IDn[0];
	for (int i = 1; i < no_of_students; i++)
	{
		if (IDn[i] > maxID)
			maxID = IDn[i];
	}
	minID = IDn[0];
	for (int i = 1; i < no_of_students; i++)
	{
		if (IDn[i] < minID)
			minID = IDn[i];
	}
	for (int i = 0; i < no_of_courses; i++)
	{
		str3 = course[i];
		for (int j = 0; j < 2; j++)
			str3 = str3.erase(0, (str3.find(",") + 1));
		date[i] = str3.substr(0, (str3.find(",")));
		days[i] = date[i].substr(0, (date[i].find("/")));
		dayn[i] = atof(days[i].c_str());
		str3 = date[i].erase(0, (date[i].find("/") + 1));
		mons[i] = str3.substr(0, str3.find("/"));
		monn[i] = atof(mons[i].c_str());
		str3 = str3.erase(0, (str3.find("/") + 1));
		years[i] = str3;
		yearn[i] = atof(years[i].c_str());
	}
	int maxY = yearn[0];
	int maxM;
	int maxD;
	for (int i = 0; i < no_of_courses; i++)
	{
		if (yearn[i] >= maxY)
		{
			maxY = yearn[i];
			maxM = monn[i];
		}
	}
	for (int i = 0; i < no_of_courses; i++)
	{
		if (yearn[i] == maxY)
		{
			if (monn[i] >= maxM)
			{
				maxM = monn[i];
				maxD = dayn[i];
			}
			else continue;
		}
	}
	for (int i = 0; i < no_of_courses; i++)
	{
		if ((yearn[i] == maxY) && (monn[i] == maxM))
		{
			if (dayn[i] >= maxD)
				maxD = dayn[i];
			else continue;
		}
	}
	int minY = yearn[0];
	int minM;
	int minD;
	for (int i = 0; i < no_of_courses; i++)
	{
		if (yearn[i] <= minY)
		{
			minY = yearn[i];
			minM = monn[i];
		}
	}
	for (int i = 0; i < no_of_courses; i++)
	{
		if (yearn[i] == minY)
		{
			if (monn[i] <= minM)
			{
				minM = monn[i];
				minD = dayn[i];
			}
			else continue;
		}
	}
	for (int i = 0; i < no_of_courses; i++)
	{
		if ((yearn[i] == minY) && (monn[i] == minM))
		{
			if (dayn[i] <= minD)
				minD = dayn[i];
			else continue;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		cin >> operation[i];
		if (operation[i] == "Number_Students")
			cout << no_of_students << endl;
		else if (operation[i] == "Number_Courses")
			cout << no_of_courses << endl;
		else if (operation[i] == "Student_ID_Min")
			cout << minID << endl;
		else if (operation[i] == "Student_ID_Max")
			cout << maxID << endl;
		else if (operation[i] == "Student_Dropped_ID")
		{
			for (int j = minID; j < maxID; j++)
			{
				if (!(j == minID))
					cout << j << endl;
			}
		}
		else if (operation[i] == "Number_Halls")
		{
			no_of_halls = 0;
			for (int j = 0; j < no_of_courses; j++)
			{
				hall[j] = course[j].substr((course[j].find("Hall") + 4), 1);
				if (halls.find(hall[j]) == -1)
					no_of_halls++;
				halls += hall[j];
			}
			cout << no_of_halls << endl;
		}
		else if (operation[i] == "Exams_Start_Date")
			cout << minD << "/" << minM << "/" << minY << endl;
		else if (operation[i] == "Exams_End_Date")
			cout << maxD << "/" << maxM << "/" << maxY << endl;
		else if (operation[i] == "Exams_Period_Indays")
		{
			days_in_between = 0;
			if (maxY == minY)
			{
				for (int j = minM; j < maxM; j++)
				{
					if (j == 2 && maxY % 4 == 0 && maxY % 100 > 0)
						days_in_between += 29;
					else
						days_in_between += month_days[j - 1];
				}
				days_in_between = days_in_between + maxD - minD + 1;
			}
			else
			{
				for (int j = minM; j <= 12; j++)
				{
					if (j == 2 && minY % 4 == 0 && minY % 100 > 0)
						days_in_between += 29;
					else
						days_in_between += month_days[j - 1];
				}
				for (int j = 1; j < maxM; j++)
				{
					if (j == 2 && maxY % 4 == 0 && maxY % 100 > 0)
						days_in_between += 29;
					else
						days_in_between += month_days[j - 1];
				}
				if ((maxY - minY) > 1)
				{
					for (int j = minY; j < (maxY - 1); j++)
					{
						if ((j + 1) % 4 == 0 && (j + 1) % 100 > 0)
							days_in_between = days_in_between + maxD - minD + 1 + 365;
						else
							days_in_between = days_in_between + maxD - minD + 1 + 364;
					}
				}
				else
					days_in_between = days_in_between + maxD - minD + 1;
			}
			cout << days_in_between<<endl;
		}
		else if (operation[i] == "Quit")
			break;
	}
	system("pause");
	return 0;

}
