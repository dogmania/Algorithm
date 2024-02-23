-- 코드를 작성해주세요
SELECT distinct b.ID, b.EMAIL, b.FIRST_NAME, b.LAST_NAME
from DEVELOPERS b, (select CODE from SKILLCODES where CATEGORY = 'Front End') a
where b.ID not in (
    select ID
    from DEVELOPERS
    where (SKILL_CODE & a.CODE = 0)
)
order by b.ID asc