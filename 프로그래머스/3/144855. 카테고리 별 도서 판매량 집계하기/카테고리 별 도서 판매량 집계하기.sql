-- 코드를 입력하세요
select b.category, sum(bs.sales)
from book_sales bs, book b
where b.book_id = bs.book_id
and bs.sales_date like '2022-01%'
group by b.category
order by b.category
