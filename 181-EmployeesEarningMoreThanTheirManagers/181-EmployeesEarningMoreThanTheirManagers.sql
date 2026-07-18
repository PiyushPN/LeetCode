-- Last updated: 18/07/2026, 20:02:14
# Write your MySQL query statement below
select e1.name as Employee from Employee as e1, Employee as e2 where e1.managerId = e2.id and e1.salary > e2.salary;