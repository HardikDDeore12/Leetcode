# Write your MySQL query statement below
/*
select employee_id, count(department_id) count
from Employee
group by employee_id
*/
select e.employee_id, e.department_id
from Employee e
join (select employee_id, count(department_id) count
from Employee
group by employee_id) as temp
on e.employee_id = temp.employee_id
where count = 1 or e.primary_flag = 'Y'