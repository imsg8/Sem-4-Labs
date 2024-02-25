--Qustion 1

create table salary_raise(
    instructor_id number,
    raise_date date,
    raise_amt number);

set serveroutput on
declare
    cursor c(dname instructor.dept_name%TYPE) is select * from instructor where dept_name = dname;
    str instructor.dept_name%TYPE;
    inst instructor%ROWTYPE;
begin
    str := '&DeptName';
    open c(str);
    loop
        fetch c into inst;
        exit when c%NOTFOUND;
        update instructor set salary = salary * 1.05 where id = inst.id;
        insert into salary_raise values(inst.id, SYSDATE, inst.salary * 0.05);
    end loop;
    close c;
end;
/

--Qustion 2

declare
    cursor c is select * from(select * from student order by tot_cred) where rownum < 11;
begin
    for i in c
    loop
        dbms_output.put_line('ID: ' || i.id || ' Name: ' || i.name || ' Dept_name: ' || i.dept_name || ' Total credits: ' || i.tot_cred);
    end loop;
end;
/

--Qustion 3

set serveroutput on
declare
    cursor c is select * from teaches;
    n number;
    iname instructor.name%TYPE;
    courseRow course%ROWTYPE;
    sectionRow section%ROWTYPE;
begin
    for i in c
    loop
        begin
            select count(*) into n from takes group by course_id, sec_id, semester, year 
            having course_id = I.course_id and sec_id = I.sec_id and semester = I.semester and year = I.year;
            exception
                when no_data_found then n := 0;
            end;
            select name into iname from instructor where id = i.id;
            select * into sectionRow from section 
            where course_id = I.course_id and sec_id = I.sec_id and semester = I.semester and year = I.year;
            select * into courseRow from course where course_id = i.course_id;

            DBMS_OUTPUT.PUT_LINE('Course ID: ' || I.course_id || ' Title: ' || courseRow.title || ' Dept name: ' || courseRow.dept_name || ' Credits: ' || courseRow.credits || 
        ' Instructor name: ' || iname || ' Building: ' || sectionRow.building || ' Room number: ' || sectionRow.room_number || ' Time slot id: ' || sectionRow.time_slot_id || ' Total students enrolled: ' || n);
    end loop;
end;
/

--Qustion 4

set serveroutput on
declare
    cursor c is select * from takes where course_id = 'CS-101';
    cr student.tot_cred%TYPE;
begin
    for i in c
    loop
        select tot_cred into cr from student where id = i.id;
        if cr < 40 then
            delete from takes where id = i.id and course_id = i.course_id;
        end if;
    end loop;
end;
/

--Qustion 5

update StudentTable set LetterGrade = 'F';

set serveroutput on
declare
    cursor c is select * from StudentTable for update;
    g StudentTable.GPA%TYPE;
begin
    for i in c
    loop
        g := i.gpa;
        if g > 0 and g <= 4 then
            update StudentTable set LetterGrade = 'F' where current of c;
        elsif g > 4 and g <= 5 then
            update StudentTable set LetterGrade = 'E' where current of c;
        elsif g > 5 and g <= 6 then
            update StudentTable set LetterGrade = 'D' where current of c;
        elsif g > 6 and g <= 7 then
            update StudentTable set LetterGrade = 'C' where current of c;
        elsif g > 7 and g <= 8 then
            update StudentTable set LetterGrade = 'B' where current of c;
        elsif g > 8 and g <= 9 then
            update StudentTable set LetterGrade = 'A' where current of c;
        elsif g > 9 and g <= 10 then
            update StudentTable set LetterGrade = 'A+' where current of c;
        end if;
    end loop;
end;
/

--Qustion 6

set serveroutput on
declare
    cursor c(cid teaches.course_id%TYPE) is select distinct id from teaches where course_id = cid;
    iname instructor.name%TYPE;
    cid teaches.course_id%TYPE;
begin
    cid := '&CourseID';
    for i in c(cid)
    loop
        select name into iname from instructor where id = i.id;
        dbms_output.put_line('ID: ' || i.id || ' Name: ' || iname);
    end loop;
end;
/

--Qustion 7

set serveroutput on
declare
    cursor C1 is select * from advisor;
    cursor C2(i takes.ID%TYPE) is select * from takes where ID = i;
    cursor C3(i teaches.ID%TYPE) is select * from teaches where ID = i;
    stdName student.name%TYPE;
    flag numeric(1);
begin
    for i in c1
    loop
        flag := 0;
        for j in c2(i.s_id)
        loop
            for z in c3(i.i_id)
            loop
                if j.course_id = z.course_id and j.sec_id = z.sec_id and j.semester = z.semester and j.year = z.year then
                select name into stdName from student where id = j.id;
                dbms_output.put_line('ID: ' || j.id || 'Name: ' || stdName);
                flag := 1;
                end if;
            end loop;
            if flag = 1 then exit; 
            end if;
        end loop;
    end loop;
end;
/
