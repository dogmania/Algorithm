-- 코드를 입력하세요
SELECT distinct b.CAR_ID
from CAR_RENTAL_COMPANY_CAR a right join CAR_RENTAL_COMPANY_RENTAL_HISTORY b on a.CAR_ID = b.CAR_ID
where CAR_TYPE = '세단' and START_DATE like '%-10-%'
order by b.CAR_ID desc