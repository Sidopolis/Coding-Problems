# Write your MySQL query statement below
with cte as(
    select products.product_id,sum(unit) as s,product_name from products join orders 
    on products.product_id = orders.product_id 
    where month(order_date) = 2 and year(order_date) = 2020
    group by product_id
    )
select product_name,s as unit from cte having s >=100