#include <iostream>
#include <vector>
#include <map>
using namespace std;
class SingleTone
{
private:
    SingleTone() {}
    ~SingleTone() {}

public:
    vector<string> RollNum;
    vector<int> number;
    vector<string> course;
    map<string, vector<int>> Num_division;
    vector<string> components;
    vector<string> grade;
    map<string,pair<int,int>> grade_divition;
    vector<string> student;
    map<string,string>name_roll;
    static SingleTone &getInstance()
    {

        static SingleTone instance;
        return instance;
    }
};