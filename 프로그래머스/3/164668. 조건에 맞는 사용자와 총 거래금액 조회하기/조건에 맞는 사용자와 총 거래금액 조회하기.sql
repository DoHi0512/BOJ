-- 코드를 입력하세요
select u.user_id, u.nickname, sum(b.price)
from used_goods_board b, used_goods_user u
where b.status = 'DONE'
and b.writer_id = u.user_id
group by u.user_id
having sum(b.price) >= 700000
order by sum(b.price)
