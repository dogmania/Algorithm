-- 코드를 입력하세요
SELECT TRUNCATE(PRICE / 10000, 0) * 10000 as PRICE_GROUP, count(PRODUCT_ID) as PRODUCTS
from PRODUCT
group by TRUNCATE(PRICE / 10000, 0)
order by PRICE_GROUP asc