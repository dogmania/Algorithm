-- 코드를 입력하세요
SELECT substr(b.SALES_DATE, 1, 4) as YEAR, substr(b.SALES_DATE, 6, 2) as MONTH, a.GENDER as GENDER, count(distinct (b.user_id)) as USERS
from USER_INFO a right join ONLINE_SALE b on a.USER_ID = b.USER_ID
where a.GENDER is not null
group by YEAR, MONTH, GENDER
order by YEAR asc, MONTH asc, GENDER asc