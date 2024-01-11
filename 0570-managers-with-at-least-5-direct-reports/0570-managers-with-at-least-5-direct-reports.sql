# Write your MySQL query statement below
SELECT name FROM
Employee e JOIN 
(
    SELECT managerID, COUNT(managerID) as cntManagerReport 
    FROM Employee 
    GROUP BY managerId
) t on e.id = t.managerId
WHERE t.cntManagerReport>=5