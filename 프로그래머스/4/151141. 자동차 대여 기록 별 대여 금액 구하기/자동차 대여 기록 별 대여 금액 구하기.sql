-- 코드를 입력하세요
SELECT b.HISTORY_ID, CASE
    when DATEDIFF(b.END_DATE, b.START_DATE) + 1 >= 90 then (DATEDIFF(b.END_DATE, b.START_DATE) + 1) * a.DAILY_FEE * 0.01 * (100 - (select substring_index(DISCOUNT_RATE, '%', 1) from CAR_RENTAL_COMPANY_DISCOUNT_PLAN where DURATION_TYPE = '90일 이상' and CAR_TYPE = '트럭'
))
    when DATEDIFF(b.END_DATE, b.START_DATE) + 1 >= 30 then (DATEDIFF(b.END_DATE, b.START_DATE) + 1) * a.DAILY_FEE * 0.01 * (100 - (select substring_index(DISCOUNT_RATE, '%', 1) from CAR_RENTAL_COMPANY_DISCOUNT_PLAN where DURATION_TYPE = '30일 이상' and CAR_TYPE = '트럭'
))
    when DATEDIFF(b.END_DATE, b.START_DATE) + 1 >= 7 then (DATEDIFF(b.END_DATE, b.START_DATE) + 1) * a.DAILY_FEE * 0.01 * (100 - (select substring_index(DISCOUNT_RATE, '%', 1) from CAR_RENTAL_COMPANY_DISCOUNT_PLAN where DURATION_TYPE = '7일 이상' and CAR_TYPE = '트럭'
))
    else (DATEDIFF(b.END_DATE, b.START_DATE) + 1) * a.DAILY_FEE end as FEE
from CAR_RENTAL_COMPANY_CAR a right join CAR_RENTAL_COMPANY_RENTAL_HISTORY b on a.CAR_ID = b.CAR_ID
where CAR_TYPE = '트럭'
order by FEE desc, HISTORY_ID desc