-- 코드를 입력하세요
SELECT substr(b.SALES_DATE, 1, 4) as YEAR, substr(b.SALES_DATE, 6, 2) as MONTH, count(distinct a.USER_ID) as PUCHASED_USERS, ROUND((count(distinct a.USER_ID) / c.USERS_SUM), 1) as PUCHASED_RATIO
from USER_INFO a right join ONLINE_SALE b on a.USER_ID = b.USER_ID, (select count(*) as USERS_SUM from USER_INFO where YEAR(JOINED) = '2021') c
where YEAR(JOINED) = '2021'
group by substr(SALES_DATE, 1, 7)
order by YEAR asc, MONTH asc