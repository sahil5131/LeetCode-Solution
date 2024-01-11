# Write your MySQL query statement below
select r.contest_id, round(count(distinct u.user_id)*100/(select count(user_id) from Users), 2) as percentage
from Users u
inner join Register r
on u.user_id = r.user_id
group by contest_id
order by percentage desc, r.contest_id