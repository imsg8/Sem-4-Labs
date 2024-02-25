1)
select count(id), course_id from takes group by course_id;

2)
select dept_name, count(distinct id) from department natural join course c, takes t where c.course_id = t.course_id group by dept_name having count(distinct id)>10;

3)
select count(course_id), dept_name from course group by dept_name;

4)
select dept_name, avg(salary) from instructor group by dept_name having avg(salary)>42000;

5)
select count(id), sec_id from section natural join takes where semester = 'Spring' and year = 2009 group by sec_id;

6)
select course_id, prereq_id from prereq order by course_id;

7)
select * from instructor order by salary;

8)
select max(sum_salary) from (select dept_name, sum(salary) as sum_salary from instructor group by dept_name) dept_sum_salary;

9)
select dept_name, avg_sal from (select dept_name, avg(salary) as avg_sal from instructor group by dept_name having avg(salary)>42000);

10)
with total_enrol(sec_id, val) as (select sec_id, count(id) from section natural join takes where semester='Spring' and year=2010 group by sec_id)
select sec_id, max(val) from total_enrol group by sec_id;

11)
select distinct i.name from instructor i, teaches t1, takes t2, student s
where i.id = t1.id and t1.course_id = t2.course_id and t2.id = s.id and s.dept_name = 'Comp. Sci.';

12)
select dept_name, avg_sal from (select dept_name, avg(salary) as avg_sal from instructor group by dept_name having avg(salary)>50000 and count(id)>5);

13)
with max_budget(val) as (select max(budget) from department)
select d.dept_name, d.budget from department d, max_budget m where d.budget = m.val;

14)
with dept_tot_sal(dept_name, tot_sal) as (select dept_name, sum(salary) as tot_sal from instructor group by dept_name), avg_sal(val) as (select avg(tot_sal) from dept_tot_sal)
select d.dept_name, d.tot_sal from dept_tot_sal d, avg_sal a where d.tot_sal>a.val;

15)
update student set dept_name ='IT' where dept_name = 'Comp. Sci.';

16)
update instructor set salary=
case
when salary>100000 then salary*1.03
else salary*1.05
end;
