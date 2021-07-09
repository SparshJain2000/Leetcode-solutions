/* 
 There is a table courses with columns: student and class
 Please list out all classes which have more than or equal to 5 students.
 For example, the table:
 
 +---------+------------+
 | student | class      |
 +---------+------------+
 | A       | Math       |
 | B       | English    |
 | C       | Math       |
 | D       | Biology    |
 | E       | Math       |
 | F       | Computer   |
 | G       | Math       |
 | H       | Math       |
 | I       | Math       |
 +---------+------------+
 Should output:
 
 +---------+
 | class   |
 +---------+
 | Math    |
 +---------+
 */
SELECT
    class
FROM
    (
        SELECT
            *
        FROM
            courses
        GROUP BY
            class,
            student
        HAVING
            COUNT(class) = 1
    )
GROUP BY
    class
HAVING
    COUNT(class) >= 5;
---------------------------------
SELECT
    class
FROM
    (
        SELECT
            class,
            COUNT(DISTINCT student) AS num
        FROM
            courses
        GROUP BY
            class
    ) AS temp_table
WHERE
    num >= 5;