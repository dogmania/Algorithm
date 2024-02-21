-- 코드를 입력하세요
SELECT a.author_id as AUTHOR_ID, b.author_name as AUTHOR_NAME, a.category as CATEGORY, sum(a.price * c.sales) as TOTAL_SALES
from BOOK a left join AUTHOR b on a.AUTHOR_ID = b.AUTHOR_ID left join (
    select book_id, sales_date, sum(sales) as sales
    from BOOK_SALES
    where substr(sales_date, 1, 7) = '2022-01'
    group by book_id
) c on a.book_id = c.book_id
group by b.author_name, a.category
order by a.author_id asc, a.category desc