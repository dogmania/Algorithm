-- 코드를 작성해주세요
SELECT sum(SCORE) as SCORE, a.EMP_NO, EMP_NAME, POSITION, EMAIL
FROM HR_EMPLOYEES a LEFT JOIN HR_GRADE b ON a.EMP_NO = b.EMP_NO
WHERE b.YEAR = '2022'
GROUP BY EMP_NO
ORDER BY SCORE DESC
limit 1