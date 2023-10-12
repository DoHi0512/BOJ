-- 코드를 입력하세요
select i.ingredient_type , sum(h.total_order)
from first_half h, icecream_info i
where h.flavor = i.flavor
group by i.ingredient_type
order by 2 asc