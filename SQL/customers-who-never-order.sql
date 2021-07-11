-- https://leetcode.com/problems/customers-who-never-order/
SELECT
    C .name AS "Customers"
FROM
    customers C
    LEFT JOIN orders o ON C .id = o.customerid
WHERE
    o.customerid IS NULL;
-- -------------------------------------------------------
SELECT
    NAME AS "Customers"
FROM
    Customers
WHERE
    id NOT IN (
        SELECT
            customerid
        FROM
            orders
    );
;