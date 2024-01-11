# Write your MySQL query statement below
SELECT query_name, round(AVG(rating/position), 2) as quality, round(count(if(rating<3, 1, NULL))/count(rating)*100, 2) as poor_query_percentage
FROM Queries
WHERE query_name is not NULL
GROUP BY query_name