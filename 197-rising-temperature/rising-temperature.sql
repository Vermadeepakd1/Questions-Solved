# Write your MySQL query statement below
select w.id from Weather as w
join Weather as t
on t.recordDate = date_sub(w.recordDate,interval 1 day)
where w.temperature > t.temperature;