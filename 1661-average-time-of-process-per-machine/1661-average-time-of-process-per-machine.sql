# Write your MySQL query statement below
SELECT s.machine_id, round(sum(e.timestamp - s.timestamp)/count(s.machine_id), 3) as processing_time FROM
(SELECT * FROM Activity 
WHERE activity_type = 'start') as s JOIN
(SELECT * FROM Activity
WHERE activity_type = 'end') as e ON s.machine_id = e.machine_id AND s.process_id = e.process_id
GROUP BY s.machine_id
