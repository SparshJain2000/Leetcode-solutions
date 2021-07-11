https://leetcode.com/problems/customers-who-never-order/
select c.name
as "Customers"
from customers c 
left join orders o
on c.id = o.customerid
where o.customerid IS NULL;
