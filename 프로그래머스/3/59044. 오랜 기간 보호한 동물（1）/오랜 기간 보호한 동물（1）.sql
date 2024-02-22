-- 코드를 입력하세요
SELECT a.NAME, a.DATETIME
from ANIMAL_INS a
where a.ANIMAL_ID not in (
    select b.ANIMAL_ID 
    from ANIMAL_OUTS b
)
order by a.DATETIME asc
limit 3