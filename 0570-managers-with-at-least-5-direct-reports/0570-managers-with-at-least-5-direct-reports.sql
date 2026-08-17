select e2.name from Employee e1 join Employee e2
on e1.managerID=e2.id
group by e1.managerID 
having count(e1.id)>=5;
