-- 코드를 입력하세요
SELECT TRIM(leading '0' from substr(start_date, 6, 2)) as MONTH, CAR_ID, count(HISTORY_ID) as RECORDS
from CAR_RENTAL_COMPANY_RENTAL_HISTORY
where car_id in (
    select car_id
    from CAR_RENTAL_COMPANY_RENTAL_HISTORY
    where start_date between '2022-08-01' and '2022-10-31'
    group by car_id having count(history_id) >= 5
) and start_date between '2022-08-01' and '2022-10-31'
group by car_id, substr(start_date, 6, 2) having count(HISTORY_ID) != 0
order by substr(start_date, 6, 2) asc, CAR_ID desc