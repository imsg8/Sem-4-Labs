--1)

set serveroutput on;
create or replace
procedure display is
begin
dbms_output.put_line('Good Day To You');
end;
/

--2)

set serveroutput on;
create or replace procedure dept_inst_courses(dname varchar) is
cursor inst is (select name from instructor where dept_name=dname);
cursor course is (select title from course where dept_name=dname);
begin
	dbms_output.put_line('Instructors');
	for i in inst loop
		dbms_output.put_line(i.name);
	end loop;
	dbms_output.put_line('Courses');
	for i in course loop
		dbms_output.put_line(i.title);
	end loop;
end;
/

--3)

set serveroutput on;
create or replace procedure course_popular(dname varchar) is
mm number := 0;
cid course.course_id%TYPE;
cursor c is (select course_id,count(course_id) cc from takes natural join course group by dept_name,course_id having dept_name=dname); 
begin
	for i in c loop
		if i.cc>mm then 
			mm :=i.cc;
			cid :=i.course_id;
		end if;
	end loop;
	dbms_output.put_line('Most Popular Course is '||cid);
end;
/

--4)

set serveroutput on;
create or replace procedure dept_student_courses(dname varchar) is
cursor stud is (select name from student where dept_name=dname);
cursor course is (select title from course where dept_name=dname);
begin
	dbms_output.put_line('Students');
	for i in stud loop
		dbms_output.put_line(i.name);
	end loop;
	dbms_output.put_line('Courses');
	for i in course loop
		dbms_output.put_line(i.title);
	end loop;
end;
/

--Functions
--5)

set serveroutput on;
create or replace function sqr(num number) 
return number as
begin
	return num*num;
end;
/

--6)

set serveroutput on;
create or replace function dept_highest(dname varchar) 
return number as
inst_max number;
begin
	select max(salary) into inst_max from instructor where dept_name=dname;
	return inst_max;
end;
/

--Packages
--7)

set serveroutput on;
create or replace package q7 as
procedure dept_inst(dname varchar);

function dept_highest(dname varchar) 
return number;
end q7;
/

create or replace package body q7 as
procedure dept_inst(dname varchar) is
cursor inst is (select name from instructor where dept_name=dname);
begin
	dbms_output.put_line('Instructors');
	for i in inst loop
		dbms_output.put_line(i.name);
	end loop;
end;

function dept_highest(dname varchar) 
return number as
inst_max number;
begin
	select max(salary) into inst_max from instructor where dept_name=dname;
	return inst_max;
end;
end q7;
/

--IN, OUT, IN OUT
--8)

set serveroutput on;
create or replace procedure simp_comp(principle in number,rate in number,years in number,times in number,SI out numeric,CI out numeric,tot_sum in out numeric) as
begin
	SI :=(principle*rate*years)/100;
	CI :=principle*power((1+rate/times),times*years);
	tot_sum := principle + SI + CI;
end;
/
