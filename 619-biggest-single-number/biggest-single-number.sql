/*
select num
from MyNumbers 
group by num
having count(*) = 1
*/
select max(n.num) as num
from (
    select num
    from MyNumbers 
    group by num
    having count(*) = 1
) n