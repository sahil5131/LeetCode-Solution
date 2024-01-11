# Write your MySQL query statement below
select s.student_id, s.student_name, s.subject_name, count(e.subject_name) as attended_exams from
(SELECT * FROM
Students cross join Subjects) s left join Examinations e
on s.student_id = e.student_id and s.subject_name = e.subject_name
GROUP BY s.student_id, s.subject_name
order by s.student_id




