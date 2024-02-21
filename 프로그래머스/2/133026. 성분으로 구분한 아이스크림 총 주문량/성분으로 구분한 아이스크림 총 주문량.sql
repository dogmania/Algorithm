-- 코드를 입력하세요
SELECT INGREDIENT_TYPE, sum(TOTAL_ORDER) as TOTAL_ORDER
from FIRST_HALF a left join ICECREAM_INFO b on a.flavor = b.flavor
group by INGREDIENT_TYPE