# Write your MySQL query statement below
SELECT name from Employee WHERE id IN (SELECT managerId from Employee GROUP BY managerId HAVING count(*)>=5) ;
