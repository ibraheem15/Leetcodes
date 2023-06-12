/* 
* Write an SQL query to report the second highest salary from the Employee table. If there is no second highest salary, the query should report null.
*/

select max(Salary) as SecondHighestSalary
from Employee
where Salary < (select max(Salary)
from Employee)
