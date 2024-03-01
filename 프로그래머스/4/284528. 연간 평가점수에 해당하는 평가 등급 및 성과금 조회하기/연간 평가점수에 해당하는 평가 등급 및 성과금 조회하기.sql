-- 코드를 작성해주세요
select a.EMP_NO, EMP_NAME,
    (case
    when avg(SCORE) >= 96 then 'S'
    when avg(SCORE) >= 90 then 'A'
    when avg(SCORE) >= 80 then 'B'
    ELSE 'C' end) as GRADE,
    (case
    when avg(SCORE) >= 96 then SAL * 0.2
    when avg(SCORE) >= 90 then SAL * 0.15
    when avg(SCORE) >= 80 then SAL * 0.1
    ELSE SAL * 0 end) as BONUS
from HR_EMPLOYEES a left join HR_GRADE b on a.EMP_NO = b.EMP_NO
group by a.EMP_NO
order by a.EMP_NO asc