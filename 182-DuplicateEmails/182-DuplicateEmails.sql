-- Last updated: 18/07/2026, 20:02:13
# Write your MySQL query statement below
select email as Email from Person group by email having count(*) > 1;
