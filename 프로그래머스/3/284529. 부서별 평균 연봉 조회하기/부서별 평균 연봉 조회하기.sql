-- 코드를 작성해주세요
select a.DEPT_ID, b.DEPT_NAME_EN, round(avg(sal), 0) as AVG_SAL
from HR_EMPLOYEES a left join HR_DEPARTMENT b on a.DEPT_ID = b.DEPT_ID
group by a.DEPT_ID
order by AVG_SAL desc