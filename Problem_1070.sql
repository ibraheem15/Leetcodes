/* 
*Write an SQL query that selects the product id, year, quantity, and price for the first year of every product sold.

*Return the resulting table in any order.
*/

select product_id, year as first_year, quantity, price
from Sales
where (product_id,year) in (select product_id, min(year)
from Sales
group by product_id)