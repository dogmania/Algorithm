-- 코드를 입력하세요
SELECT a.ANIMAL_ID, a.NAME
from ANIMAL_OUTS a left join ANIMAL_INS b on a.ANIMAL_ID = b.ANIMAL_ID
where b.ANIMAL_ID is null