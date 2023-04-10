#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "SingleTone.h"
using namespace std;
class read
{
    float Marks, total;
    string line;

public:
    SingleTone &singleTone = SingleTone::getInstance();
    float ReadData(string fileName, string rollNum)
    {
        ifstream file(fileName + ".txt");
        if (!file.is_open())
        {
            cout << "\nThis File Is Not Exist!\n";
            return 0.0;
        }
        getline(file, line, '_');
        getline(file, line, '\n');
        total = stof(line);
        int k = 0;
        while (getline(file, line, ' '))
        {
            if (line.find(rollNum) != string::npos)
            {

                getline(file, line, '\n');
                Marks = stof(line);
                k = 1;
            }
        }
        if (k == 1)
        {
            return (Marks / total);
        }
        else
        {
            
            file.close();
            return 0;
        }
        file.close();
        return 0;
    }

    void course_details()
    {
        ifstream file("course.txt");
        if (!file.is_open())
        {
            cout << "\nThis File Is Not Exist!\n";
            return;
        }
        getline(file, line);
        getline(file, line);
        singleTone.course.push_back(line);
        getline(file, line);
        getline(file, line);
        singleTone.course.push_back(line);
        getline(file, line);
        while (getline(file, line, ' '))
        {
            vector<int> obj;
            string str = line;
            transform(str.begin(), str.end(), str.begin(), ::tolower);
            singleTone.components.push_back(str);
            getline(file, line, ' ');
            int n = stoi(line);
            obj.push_back(n);
            getline(file, line, ' ');
            n = stoi(line);
            obj.push_back(n);
            getline(file, line, '\n');
            n = stoi(line);
            obj.push_back(n);
            singleTone.Num_division[str] = obj;
        }
        file.close();
    }
    void ReadRollNum()
    {
        ifstream file("students.txt");
        if (!file.is_open())
        {
            cout << "\nThis File Is Not Exist!\n";
            return;
        }
        getline(file, line);
        while (getline(file, line, ' '))
        {
            singleTone.RollNum.push_back(line);
            getline(file, line, '\n');
        }
        file.close();
    }
    void grads()
    {
        ifstream file("grades.txt");
        if (!file.is_open())
        {
            cout << "\nThis File Is Not Exist!\n";
            return;
        }
        getline(file, line);
        while (getline(file, line, ' '))
        {

            string grade = line;
            getline(file, line, ' ');
            int n = stoi(line);

            getline(file, line, '\n');
            int k = stoi(line);

            singleTone.grade.push_back(grade);
            singleTone.grade_divition.insert({grade, {n, k}});
        }
        file.close();
    }
    void student()
    {
        ifstream file("students.txt");
        if (!file.is_open())
        {
            cout << "\nThis File Is Not Exist!\n";
            return;
        }
        getline(file, line);
        while (getline(file, line, ' '))
        {
            string rol=line;
            getline(file, line, '\n');
            singleTone.student.push_back(line);
            singleTone.name_roll[rol]=line;
        }
        file.close();
    }
};