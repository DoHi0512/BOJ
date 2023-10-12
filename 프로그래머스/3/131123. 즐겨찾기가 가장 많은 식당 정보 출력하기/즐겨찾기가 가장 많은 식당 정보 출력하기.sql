-- 코드를 입력하세요
select food_type, rest_id, rest_name, favorites
from rest_info
where  (favorites, food_type) in (
select max(favorites), food_type
from rest_info
group by food_type
) 
order by food_type desc