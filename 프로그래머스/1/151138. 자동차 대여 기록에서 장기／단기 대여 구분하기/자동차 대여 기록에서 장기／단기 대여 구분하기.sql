-- 코드를 입력하세요
SELECT HISTORY_ID, CAR_ID, substr(START_DATE, 1, 10) as START_DATE, substr(END_DATE, 1, 10) as END_DATE, CASE
    when DATEDIFF(end_date, start_date) >= 29 then '장기 대여'
    else '단기 대여' end as RENT_TYPE
from CAR_RENTAL_COMPANY_RENTAL_HISTORY
where substr(START_DATE, 1, 7) = '2022-09'
order by HISTORY_ID desc