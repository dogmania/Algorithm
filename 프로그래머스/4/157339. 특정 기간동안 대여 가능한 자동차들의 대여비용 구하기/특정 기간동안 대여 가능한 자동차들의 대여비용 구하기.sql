-- 코드를 입력하세요
SELECT a.CAR_ID, a.CAR_TYPE, (a.DAILY_FEE * 30 * (1 - 0.01 * SUBSTRING_INDEX(c.DISCOUNT_RATE, '%', 1))) as FEE
from CAR_RENTAL_COMPANY_CAR a left join (select CAR_TYPE, DISCOUNT_RATE from CAR_RENTAL_COMPANY_DISCOUNT_PLAN where DURATION_TYPE = '30일 이상' and (CAR_TYPE = '세단' or CAR_TYPE = 'SUV')) c on a.CAR_TYPE = c.CAR_TYPE
where (a.car_id not in (select car_id from CAR_RENTAL_COMPANY_RENTAL_HISTORY where ('2022-11-01' between start_date and end_date) or ('2022-11-30' between start_date and end_date))) 
and ((a.DAILY_FEE * 30 * (1 - 0.01 * SUBSTRING_INDEX(c.DISCOUNT_RATE, '%', 1))) between 500000 and 1999999)
order by FEE DESC, a.CAR_TYPE asc, a.CAR_ID desc
# select * from CAR_RENTAL_COMPANY_RENTAL_HISTORY order by CAR_ID