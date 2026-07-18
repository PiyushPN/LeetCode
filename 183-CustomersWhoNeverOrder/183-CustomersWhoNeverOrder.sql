-- Last updated: 18/07/2026, 20:02:12
# Write your MySQL query statement below
select c.name as Customers from Customers as c left join Orders as o on c.id = o.customerId where o.customerId is NULL; 