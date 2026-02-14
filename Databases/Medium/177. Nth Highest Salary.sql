CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
declare offset_val int;
set offset_val=N-1;
  RETURN (
      # Write your MySQL query statement below.
      Select DISTINCT salary
      from Employee
      order by salary DESC
      limit 1 OFFSET offset_val

  );
END