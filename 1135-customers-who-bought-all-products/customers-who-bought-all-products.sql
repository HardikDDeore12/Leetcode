# Write your MySQL query statement below
/*
select customer_id, count(distinct product_key) as distinct_products
from Customer
group by customer_id
*/
select customer_id
from (
    select customer_id, count(distinct product_key) as distinct_products
    from Customer
    group by customer_id
) as temp 
where distinct_products = (select count(distinct product_key) from Product)