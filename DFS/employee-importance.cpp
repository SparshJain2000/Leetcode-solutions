//Problem Statement
/*
You are given a data structure of employee information, which includes the employee's unique id, their importance value and their direct subordinates' id.

For example, employee 1 is the leader of employee 2, and employee 2 is the leader of employee 3. They have importance value 15, 10 and 5, respectively. Then employee 1 has a data structure like [1, 15, [2]], and employee 2 has [2, 10, [3]], and employee 3 has [3, 5, []]. Note that although employee 3 is also a subordinate of employee 1, the relationship is not direct.

Now given the employee information of a company, and an employee id, you need to return the total importance value of this employee and all their subordinates.
*/
#include <bits/stdc++.h>
using namespace std;
class Employee
{
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution
{
public:
    int getImportance(vector<Employee *> employees, int id)
    {
        int ans = 0;
        for (Employee *emp : employees)
        {
            if (emp->id == id)
            {
                ans += emp->importance;
                for (int i : emp->subordinates)
                    ans += getImportance(employees, i);
            }
        }
        return ans;
    }
};