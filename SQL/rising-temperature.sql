https://leetcode.com/problems/rising-temperature/
select a.id as "id"
from weather a,weather b
where (a.recordDate = b.recordDate+1)
and a.temperature>b.temperature;
