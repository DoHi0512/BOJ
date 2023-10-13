-- 코드를 입력하세요
select month(start_date), car_id, count(*) as records
from car_rental_company_rental_history
where car_id in (
    select car_id
    from car_rental_company_rental_history
     where month(start_date) between 8 and 10
     group by car_id
     having count(*) >= 5
)
and month(start_date) between 8 and 10
group by month(start_date), car_id
order by month(start_date), car_id desc