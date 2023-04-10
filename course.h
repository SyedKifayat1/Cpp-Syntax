#include <iostream>
using namespace std;
#include <iostream>
#include "filesRead.h"
#include <algorithm>
#include <string>
#include <cctype>
class Result
{
public:
    map<string, pair<float, string>> Calculated_Result;
    SingleTone &singleTone = SingleTone::getInstance();
    read obj;
    string grade;
    vector<float> Comp_Marks;

    void result(int special)
    {
        obj.student();
        obj.course_details();
        obj.ReadRollNum();
        obj.grads();
        string Num[30] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29"};
        vector<float> Marks;
        float totalMarks = 0;
        float comp_total_Marks = 0;
        for (int i = 0; i < singleTone.RollNum.size(); i++)
        {
            for (int comp = 0; comp < singleTone.components.size(); comp++)
            {
                string fileName = singleTone.components[comp];
                // cout<<fileName<<endl;
                vector<int> quantity = singleTone.Num_division[fileName];
                for (int s = 0; s < quantity[1]; s++)
                {
                    float num = obj.ReadData(fileName + "_" + Num[s], singleTone.RollNum[i]);
                    Marks.push_back(num);
                }

                sort(Marks.begin(), Marks.end());
                if (special == 1)
                {
                    for (int ch = quantity[1] - quantity[2]; ch < quantity[1]; ch++)
                    {

                        totalMarks += Marks[ch];
                    }
                    totalMarks = (totalMarks / quantity[2]) * quantity[0];
                }
                else
                {
                    for (int ch = 0; ch < quantity[1]; ch++)
                    {
                        totalMarks += Marks[ch];
                    }
                    totalMarks = (totalMarks / quantity[1]) * quantity[0];
                }
                Comp_Marks.push_back(totalMarks);
                Marks.clear();
                totalMarks = 0;
            }
            for (int m = 0; m < Comp_Marks.size(); m++)
            {
                comp_total_Marks += Comp_Marks[m];
            }
            for (auto &[key, value] : singleTone.grade_divition)
            {
                if (comp_total_Marks >= value.first && comp_total_Marks <= value.second)
                {
                    grade = key;
                    Calculated_Result.insert({singleTone.RollNum[i], {comp_total_Marks, grade}});
                    break;
                }
            }

            Comp_Marks.clear();
            comp_total_Marks = 0;
        }
    }
    // bool compare()
    // {
    //     bool compare(const pair<string, pair<int, string>> &a, const pair<string, pair<int, string>> &b)
    //     {
    //         return a.second.first > b.second.first;
    //     }
    // }
    
    void display()
    {

        cout << "Course Name :" << singleTone.course[0] << endl;
        cout << "Course Code :" << singleTone.course[1] << endl;
        for (int i = 0; i < singleTone.RollNum.size(); i++)
        {
            cout << endl
                 << "Roll No :" << singleTone.RollNum[i] << endl;
            cout << "Name :" << singleTone.student[i] << endl;
            cout << "Persentage " << Calculated_Result[singleTone.RollNum[i]].first << "%" << endl;
            cout << "Grade :" << Calculated_Result[singleTone.RollNum[i]].second << endl;
        }
        Calculated_Result.clear();
        singleTone.RollNum.clear();
        singleTone.number.clear();
        singleTone.course;
        singleTone.Num_division.clear();
        singleTone.components.clear();
        singleTone.grade.clear();
        singleTone.grade_divition.clear();
        singleTone.student.clear();
    }
    void specific_data()
    {
        cout << "\nEnter an Roll Number :";
        string str;
        cin >> str;
        transform(str.begin(), str.end(), str.begin(), ::toupper);
        auto it_calculated_result = Calculated_Result.find(str);
        auto it_name_roll = singleTone.name_roll.find(str);
        if (it_calculated_result != Calculated_Result.end() && it_name_roll != singleTone.name_roll.end())
        {
            float percentage = it_calculated_result->second.first;
            string name = it_name_roll->second;

            cout << "Roll Number: " << str << "\nName: " << name << "\nPercentage: " << percentage << "%" << endl
                 << "Grade :" << it_calculated_result->second.second;
        }

        else
        {
            cout << "Roll Number :" << str << " Not Found!" << endl;
        }
        Calculated_Result.clear();
        singleTone.RollNum.clear();
        singleTone.number.clear();
        singleTone.course;
        singleTone.Num_division.clear();
        singleTone.components.clear();
        singleTone.grade.clear();
        singleTone.grade_divition.clear();
        singleTone.student.clear();
    }
};
