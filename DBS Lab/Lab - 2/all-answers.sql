1) 
create table Employee(EmpNo numeric(5) primary key,
EmpName varchar(20) not null,
Gender character(1) not null check (Gender = 'M' OR Gender = 'F'),
Salary numeric(8) not null,
Address varchar(20) not null,
DNo numeric(5));

2) 
create table Department(
DeptNo numeric(5) primary key,
DeptName varchar(20) unique);

3)
alter table Employee add constraint FK_DNo foreign key(DNo) references Department(DeptNo);

4)
insert into Department values (1,'cse');
insert into Department values (2,'it');
insert into Department values (3,'ece');

insert into Employee values (1,'Shivang','M',65000,'Manipal',1);
insert into Employee values (2,'Janav','F',62000,'Manipal',3);
insert into Employee values (3,'Laven','M',69000,'Manipal',2);

5)
insert into Department values (2,'mechx');
insert into Employee values (3,NULL,'N',30000,'Manipal',2);
insert into Employee values (4,'ronit','N',NULL,'Manipal',2);

6)
delete from Department where DeptNo = 2;

7)
alter table Employee drop constraint FK_DNo;
alter table Employee add constraint FK_DNo foreign key(DNo) references Department(DeptNo) on delete cascade;

8)
alter table Employee modify(constraint defSal Salary default 10000);

9)
select name, dept_name from student;

10)
select * from Instructor where dept_name = 'Comp. Sci.';

11)
select title from Course where dept_name = 'Comp. Sci.' and credits = 3;

12)
select course_id, title from Course where course_id in(select course_id from takes where id = 12345);

13)
select * from Instructor where salary between 40000 and 90000;

14)
select id from instructor where id not in (select id from teaches);

15)
select name, title, year from Student natural join Course natural join Section where room_number = 303;

16)
select name, title as c_name from Student natural join Course natural join Takes where year = 2015;

17)
select name, salary as inst_salary from Instructor where salary > (select min(salary) from Instructor where dept_name = 'Comp. Sci.');

18)
select name from Instructor where dept_name like '%ch%';

19)
select name, length(name) from Student;

20)
select dept_name, substr(dept_name, 3, 3) from Department;

21)
select upper(name) from Instructor;

22)
select id, course_id, NVL(grade, 'NA') from takes where semester = 'Summer';

23)
select salary, round(salary/3, -2) from Instructor;
