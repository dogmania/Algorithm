-- 코드를 작성해주세요
SELECT DISTINCT ITEM_ID, ITEM_NAME, RARITY
from ITEM_INFO
where ITEM_ID in
(SELECT ITEM_ID
 from ITEM_TREE
 where PARENT_ITEM_ID in
 (SELECT ITEM_ID
  from ITEM_INFO
  where RARITY = "RARE"
 )
)
order by ITEM_ID DESC