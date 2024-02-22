-- 코드를 입력하세요
SELECT a.PRODUCT_CODE as PRODUCT_CODE, (b.amount * a.price) as SALES
from PRODUCT a left join (
    select PRODUCT_ID, sum(SALES_AMOUNT) amount
    from OFFLINE_SALE
    group by PRODUCT_ID
) b on a.PRODUCT_ID = b.PRODUCT_ID
where (b.amount * a.price) is not null
order by SALES DESC, PRODUCT_CODE ASC