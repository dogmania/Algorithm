-- 코드를 입력하세요
SELECT a.PRODUCT_ID, a.PRODUCT_NAME, (PRICE * AMOUNT) as TOTAL_SALES
from FOOD_PRODUCT a left join (select PRODUCT_ID, sum(AMOUNT) as AMOUNT from FOOD_ORDER where substr(PRODUCE_DATE, 1, 7) = '2022-05' group by PRODUCT_ID) b on a.PRODUCT_ID = b.PRODUCT_ID
where (PRICE * AMOUNT) is not null
order by TOTAL_SALES desc, a.PRODUCT_ID asc