SELECT w1.id
FROM Weather w1
join Weather w2
where datediff(w1.recordDate, w2.recordDate) = 1
AND w1.temperature>w2.temperature