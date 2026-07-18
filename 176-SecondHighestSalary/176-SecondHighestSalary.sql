-- Last updated: 18/07/2026, 20:02:17
# Write your MySQL query statement below
select max(salary) as SecondHighestSalary from Employee where salary < (select max(salary) from Employee);
