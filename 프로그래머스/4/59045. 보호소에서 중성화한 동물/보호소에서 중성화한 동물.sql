-- 코드를 입력하세요
SELECT a.ANIMAL_ID, a.ANIMAL_TYPE, a.NAME
from ANIMAL_INS a left join ANIMAL_OUTS b on a.ANIMAL_ID = b.ANIMAL_ID
where a.SEX_UPON_INTAKE like 'Intact%' and (b.SEX_UPON_OUTCOME like 'Spayed%' or b.SEX_UPON_OUTCOME like 'Neutered%')
order by a.ANIMAL_ID asc