/*
 Mary IS A teacher IN A middle school
 AND she has A TABLE seat storing students ' names and their corresponding seat ids.
 
 The column id is continuous increment.
 
 Mary wants to change seats for the adjacent students.
 
 Can you write a SQL query to output the result for Mary?
 
 +---------+---------+
 |    id   | student |
 +---------+---------+
 |    1    | Abbot   |
 |    2    | Doris   |
 |    3    | Emerson |
 |    4    | Green   |
 |    5    | Jeames  |
 +---------+---------+
 For the sample input, the output is:
 
 +---------+---------+
 |    id   | student |
 +---------+---------+
 |    1    | Doris   |
 |    2    | Abbot   |
 |    3    | Green   |
 |    4    | Emerson |
 |    5    | Jeames  |
 +---------+---------+
 */
SELECT
    (
        CASE
            WHEN MOD(id, 2) = 1
            AND counts != id THEN id + 1
            WHEN MOD(id, 2) = 1
            AND counts = id THEN id
            ELSE id - 1
        END
    ) id,
    student
FROM
    seat,
    (
        SELECT
            COUNT(*) counts
        FROM
            seat
    ) seat_counts
ORDER BY
    id;