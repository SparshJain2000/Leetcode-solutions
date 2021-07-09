/*
 The Employee table holds all employees including their managers. Every employee has an Id, and there is also a column for the manager Id.
 
 +----+-------+--------+-----------+
 | Id | Name  | Salary | ManagerId |
 +----+-------+--------+-----------+
 | 1  | Joe   | 70000  | 3         |
 | 2  | Henry | 80000  | 4         |
 | 3  | Sam   | 60000  | NULL      |
 | 4  | Max   | 90000  | NULL      |
 +----+-------+--------+-----------+
 Given the Employee table, write a SQL query that finds out employees who earn more than their managers. For the above table, Joe is the only employee who earns more than his manager.
 
 +----------+
 | Employee |
 +----------+
 | Joe      |
 +----------+
 */
SELECT
    NAME AS 'Employee'
FROM
    employee e1
WHERE
    salary >(
        SELECT
            salary
        FROM
            employee e2
        WHERE
            e2.id = e1.managerid
    );
--------------------------------------------------------------------------
SELECT
    e1.name AS 'Employee'
FROM
    employee e1
    JOIN employee e2
WHERE
    e1.managerid = e2.id
    AND e1.salary > e2.salary;
--------------------------------------------------------------------------
SELECT
    NAME AS "Employee"
FROM
    Employee e
WHERE
    EXISTS (
        SELECT
            salary
        FROM
            Employee
        WHERE
            Id = e.ManagerId
            AND salary < e.salary
    );