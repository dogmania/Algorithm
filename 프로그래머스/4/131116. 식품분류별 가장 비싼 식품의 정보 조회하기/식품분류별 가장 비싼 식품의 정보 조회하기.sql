-- 코드를 입력하세요
SELECT CATEGORY, PRICE as MAX_PRICE, PRODUCT_NAME
from FOOD_PRODUCT a
where a.PRICE in (
    select max(PRICE)
    from FOOD_PRODUCT b
    where a.CATEGORY = b.CATEGORY
    group by CATEGORY
) and (category = '과자' or category = '국' or category = '김치' or category = '식용유')
order by MAX_PRICE desc
