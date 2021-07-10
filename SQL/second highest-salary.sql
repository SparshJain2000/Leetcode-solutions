https://leetcode.com/problems/second-highest-salary/
# select max(salary) as SecondHighestSalary
# from employee
# where salary<(select max(salary) from employee);

# select max(salary) as SecondHighestSalary
# from employee 
# where salary NOT IN(select max(salary) from employee);
