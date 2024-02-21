-- 코드를 입력하세요
SELECT substr(DATETIME, 12, 2) as HOUR, count(ANIMAL_ID) as COUNT
from ANIMAL_OUTS
where substr(DATETIME, 12, 2) between '09' and '19'
group by substr(DATETIME, 12, 2)
order by substr(DATETIME, 12, 2) ASC