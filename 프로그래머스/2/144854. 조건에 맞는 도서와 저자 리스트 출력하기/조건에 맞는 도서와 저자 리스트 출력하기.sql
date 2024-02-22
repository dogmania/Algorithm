-- 코드를 입력하세요
SELECT a.BOOK_ID, b.AUTHOR_NAME, substr(a.PUBLISHED_DATE, 1, 10) as PUBLISHED_DATE
from BOOK a left join AUTHOR b on a.AUTHOR_ID = b.AUTHOR_ID
where a.CATEGORY = '경제'
order by PUBLISHED_DATE ASC