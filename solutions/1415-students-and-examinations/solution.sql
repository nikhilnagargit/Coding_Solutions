# Write your MySQL query statement below
SELECT s.student_id, s.student_name, sub.subject_name, count(e.subject_name) as attended_exams from  Students as s CROSS JOIN Subjects as sub LEFT JOIN Examinations as e ON e.student_id = s.student_id and e.subject_name = sub.subject_name GROUP BY sub.subject_name, s.student_id  ORDER BY s.student_id, sub.subject_name;
