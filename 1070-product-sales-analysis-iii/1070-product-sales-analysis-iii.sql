# Write your MySQL query statement below
select s.product_id, s.year as first_year, quantity, price
from Sales s join (
    select product_id, min(year) as year
    from Sales
    group by product_id
    ) as ys on s.product_id = ys.product_id and s.year = ys.year
