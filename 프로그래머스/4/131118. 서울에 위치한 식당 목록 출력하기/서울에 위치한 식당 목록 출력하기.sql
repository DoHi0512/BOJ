select i.rest_id, i.rest_name, i.food_type, i.favorites, i.address, round(avg(r.review_score),2)
from rest_info i, rest_review r
where i.address like '서울%'
and i.rest_id = r.rest_id
group by i.rest_id
order by avg(r.review_score) desc, favorites desc