# Write your MySQL query statement below
SELECT machine_id, ROUND(AVG(CASE WHEN activity_type="start" THEN timestamp*-1 ELSE timestamp END)*2.0,3) as processing_time FROM activity GROUP BY machine_id;
