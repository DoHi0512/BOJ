-- 코드를 입력하세요
SELECT b.author_id, a.author_name, b.category, sum(bs.sales * b.price)
from book b, author a, book_sales bs
where bs.sales_date between '2022-01-01' and '2022-01-31'
and bs.book_id = b.book_id
and a.author_id = b.author_id
group by a.author_name, b.category
order by a.author_id, b.category desc


