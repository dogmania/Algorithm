-- 코드를 입력하세요
SELECT b.ANIMAL_ID, b.NAME
from ANIMAL_INS a right join ANIMAL_OUTS b on a.ANIMAL_ID = b.ANIMAL_ID
order by DATEDIFF(b.DATETIME, a.DATETIME) desc
limit 2