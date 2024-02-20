-- 코드를 입력하세요
SELECT r1.FOOD_TYPE, r1.REST_ID, r1.REST_NAME, r1.FAVORITES
from REST_INFO r1
where r1.FAVORITES in
    (SELECT max(FAVORITES)
    from REST_INFO r2
    where r1.FOOD_TYPE = r2.FOOD_TYPE
    )
order by r1.FOOD_TYPE DESC