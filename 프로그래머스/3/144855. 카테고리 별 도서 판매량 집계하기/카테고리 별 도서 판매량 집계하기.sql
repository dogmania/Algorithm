-- 코드를 입력하세요
SELECT CATEGORY, sum(b.SALES) as TOTAL_SALES
from BOOK a
left join BOOK_SALES b
on a.BOOK_ID = b.BOOK_ID
where substr(b.SALES_DATE, 1, 7) = '2022-01'
group by CATEGORY
order by CATEGORY asc