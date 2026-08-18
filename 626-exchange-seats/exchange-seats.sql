# Write your MySQL query statement below
-- LEAD/LAG syntax
select id, 
CASE 
    WHEN id % 2 = 1 THEN COALESCE(LEAD(student) OVER (ORDER BY id), student)
    ELSE LAG(student) OVER (ORDER BY id)
END AS student
from Seat
order by id asc;