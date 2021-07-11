/*
 TABLE: Weather + ---------------+---------+
 | Column NAME | TYPE | + ---------------+---------+
 | id | INT | | recordDate | DATE | | temperature | INT | + ---------------+---------+
 id IS THE primary key FOR this TABLE.This TABLE contains information about THE temperature IN A certain DAY.WRITE an SQL query TO find ALL dates ' id with higher temperature compared to its previous dates (yesterday).
 
 Return the result table in any order.
 
 The query result format is in the following example:
 
 Weather
 +----+------------+-------------+
 | id | recordDate | Temperature |
 +----+------------+-------------+
 | 1  | 2015-01-01 | 10          |
 | 2  | 2015-01-02 | 25          |
 | 3  | 2015-01-03 | 20          |
 | 4  | 2015-01-04 | 30          |
 +----+------------+-------------+
 
 Result table:
 +----+
 | id |
 +----+
 | 2  |
 | 4  |
 +----+
 In 2015-01-02, temperature was higher than the previous day (10 -> 25).
 In 2015-01-04, temperature was higher than the previous day (20 -> 30).
 */
SELECT
    id
FROM
    weather w1
WHERE
    temperature >(
        SELECT
            temperature
        FROM
            weather w2
        WHERE
            w1.recordDate - w2.recordDate = 1
    );
    
    -----------
select a.id as "id"
from weather a,weather b
where (a.recordDate = b.recordDate+1)
and a.temperature>b.temperature;
