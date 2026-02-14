Select e.name as Employee from Employee e JOIN Employee m ON e.managerID = m.id where e.salary >m.salary;
