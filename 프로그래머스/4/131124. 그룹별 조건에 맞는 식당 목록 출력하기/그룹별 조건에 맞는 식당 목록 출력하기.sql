-- 코드를 입력하세요
SELECT a.MEMBER_NAME, b.REVIEW_TEXT, substr(b.REVIEW_DATE, 1, 10) as REVIEW_DATE
from MEMBER_PROFILE a right join REST_REVIEW b on a.MEMBER_ID = b.MEMBER_ID
where b.member_id = (
    select member_id
    from REST_REVIEW
    group by member_id
    order by count(*) desc
    limit 1
)
order by REVIEW_DATE asc, b.REVIEW_TEXT asc