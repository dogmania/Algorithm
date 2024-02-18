-- 코드를 입력하세요
SELECT b.TITLE, b.BOARD_ID, r.REPLY_ID, r.WRITER_ID, r.CONTENTS, SUBSTR(r.CREATED_DATE, 1, 10)
from USED_GOODS_BOARD b 
inner join USED_GOODS_REPLY r on b.BOARD_ID = r.BOARD_ID
where b.BOARD_ID = r.BOARD_ID and SUBSTR(b.CREATED_DATE, 1, 7) = '2022-10'
order by r.CREATED_DATE ASC, b.TITLE ASC