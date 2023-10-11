select date_format(sales_date, '%Y-%m-%d'), product_id, user_id, sales_amount
from online_sale
where sales_date between '2022-03-01' and '2022-03-31'
union all
select date_format(sales_date, '%Y-%m-%d'), product_id, NULL as user_id, sales_amount
from offline_sale
where sales_date between '2022-03-01' and '2022-03-31'
order by 1,2,3