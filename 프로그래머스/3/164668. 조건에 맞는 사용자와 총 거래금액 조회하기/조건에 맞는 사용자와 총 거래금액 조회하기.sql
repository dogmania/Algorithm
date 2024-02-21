-- 코드를 입력하세요
SELECT b.user_id as USER_ID, b.nickname as NICKNAME, sum(price) as TOTAL_SALES
from USED_GOODS_BOARD a left join USED_GOODS_USER b on writer_id = user_id
where a.status = 'done'
group by writer_id having sum(price) >= 700000
order by sum(price) asc