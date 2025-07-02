/*select min(sale_id) AS sale_id
from Sales
group by product_id
*/
/*
SELECT product_id, year AS first_year, quantity, price    ------    tle
FROM Sales
WHERE year = (
    SELECT MIN(year)
    FROM Sales AS s2
    WHERE s2.product_id = Sales.product_id
);
*/
/*
select product_id, min(year) as first_year
from Sales
group by product_id
*/
select s.product_id, s.year as first_year, s.quantity, s.price
from Sales s
join (
    select product_id, min(year) as min_first_year
    from Sales
    group by product_id
) as first_year
on s.product_id = first_year.product_id and s.year = first_year.min_first_year