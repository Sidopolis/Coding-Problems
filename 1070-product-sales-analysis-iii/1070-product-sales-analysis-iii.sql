/* Write your PL/SQL query statement below */
WITH sale_id_first AS (
    SELECT 
        product_id,
        year,
        FIRST_VALUE(year) OVER (PARTITION BY product_id ORDER BY year) AS first_year,
        quantity,
        price    
    FROM sales
)
SELECT 
    product_id,
    FIRST_VALUE(year) OVER (PARTITION BY product_id ORDER BY year) AS first_year,
    quantity,
    price    
FROM sale_id_first
WHERE first_year = year;