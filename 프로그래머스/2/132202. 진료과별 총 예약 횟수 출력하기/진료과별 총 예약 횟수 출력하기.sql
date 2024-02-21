-- 코드를 입력하세요
SELECT mcdp_cd as '진료과코드', count(pt_no) as '5월예약건수'
from APPOINTMENT
where apnt_ymd like '2022-05%'
group by mcdp_cd
order by count(pt_no) asc, mcdp_cd asc