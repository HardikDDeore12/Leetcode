select e.name, b.bonus
FROM Employee e
left join Bonus b on e.empId = b.empId
Where b.bonus IS NULL OR b.bonus<1000