-- Last updated: 18/07/2026, 20:02:18
# Write your MySQL query statement below
select p.firstName, p.lastName, d.city, d.state from Person as p left join Address as d on p.personId = d.personId;