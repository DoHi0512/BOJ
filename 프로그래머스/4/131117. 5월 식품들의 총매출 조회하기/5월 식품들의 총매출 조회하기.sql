-- 코드를 입력하세요
select p.product_id, p.product_name, sum(o.amount  * p.price)
from food_product p, food_order o
where p.product_id = o.product_id
and o.produce_date like '2022-05%'
group by p.product_id
order by 3 desc, 1 asc
