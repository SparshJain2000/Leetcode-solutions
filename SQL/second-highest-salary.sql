/*
 Write a SQL query to get the second highest salary from the Employee table.
 
 +----+--------+
 | Id | Salary |
 +----+--------+
 | 1  | 100    |
 | 2  | 200    |
 | 3  | 300    |
 +----+--------+
 */
SELECT
    (
        SELECT
            DISTINCT Salary
        FROM
            Employee
        ORDER BY
            Salary DESC
        LIMIT
            1 offset 1
    ) AS SecondHighestSalary;