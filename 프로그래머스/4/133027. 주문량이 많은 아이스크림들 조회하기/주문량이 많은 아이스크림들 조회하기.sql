-- 코드를 입력하세요
SELECT a.FLAVOR
from FIRST_HALF a left join JULY b on a.FLAVOR = b.FLAVOR
where a.FLAVOR = b.FLAVOR
group by a.FLAVOR
order by sum(a.TOTAL_ORDER) desc
limit 3