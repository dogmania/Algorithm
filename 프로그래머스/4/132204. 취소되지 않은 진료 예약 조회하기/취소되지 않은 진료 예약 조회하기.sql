-- 코드를 입력하세요
SELECT a.APNT_NO, c.PT_NAME, a.PT_NO, a.MCDP_CD, b.DR_NAME, a.APNT_YMD
from APPOINTMENT a left join DOCTOR b on a.MDDR_ID = b.DR_ID left join PATIENT c on a.PT_NO = c.PT_NO
where (a.APNT_CNCL_YN = 'N') and (substr(a.APNT_YMD, 1, 10) = '2022-04-13') and a.MCDP_CD = 'CS'
order by a.APNT_YMD asc