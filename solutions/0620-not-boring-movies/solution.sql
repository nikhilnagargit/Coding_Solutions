# Write your MySQL query statement below
SELECT * from Cinema where ID%2<>0 and description<>"boring" order by rating desc;
