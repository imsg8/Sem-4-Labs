1)
set serveroutput on
declare
    rno StudentTable.RollNo%TYPE;
    g StudentTable.GPA%TYPE;
begin
    rno := '&rno';
    select gpa into G from StudentTable where RollNo = rno;
    dbms_output.put_line('GPA: ' || g);
end;
/

2)
set serveroutput on
declare
    rno StudentTable.RollNo%TYPE;
    g StudentTable.GPA%TYPE;
begin
    rno := '&rno';
    select gpa into g from StudentTable where RollNo = rno;

    if g > 0 and g <= 4 then
        dbms_output.put_line('grade f');
    elsif g > 4 and g <= 5 then
        dbms_output.put_line('grade e');
    elsif g > 5 and g <= 6 then
        dbms_output.put_line('grade d');
    elsif g > 6 and g <= 7 then
        dbms_output.put_line('grade c');
    elsif g > 7 and g <= 8 then
        dbms_output.put_line('grade b');
    elsif g > 8 and g <= 9 then
        dbms_output.put_line('grade a');
    elsif g > 9 and g <= 10 then
        dbms_output.put_line('grade a+');
    else
        dbms_output.put_line('no grade');
    end if;
end;
/

3)
set serveroutput on
declare
    di date;
    dr date;
    n numeric(3);
    f numeric(3);
begin
    di := to_date('&issuedate', 'dd-mm-yy');
    dr := to_date('&returndate', 'dd-mm-yy');
    n := dr - di;
    if n <= 7 then
        f := 0;
    elsif n <= 15 then
        f := n;
    elsif n <= 30 then
        f := n * 2;
    else
        f := n * 5;
    end if;
    dbms_output.put_line('fine is '|| f);
end;
/

4)
set serveroutput on
declare
    i numeric(1);
    g StudentTable.GPA%TYPE;
begin
    i := 1;
    loop
        select gpa into g from StudentTable where RollNo = i;
        if g > 0 and g <= 4 then
            dbms_output.put_line('grade f');
        elsif g > 4 and g <= 5 then
            dbms_output.put_line('grade e');
       elsif g > 5 and g <= 6 then
            dbms_output.put_line('grade d');
        elsif g > 6 and g <= 7 then
            dbms_output.put_line('grade c');
        elsif g > 7 and g <= 8 then
            dbms_output.put_line('grade b');
        elsif g > 8 and g <= 9 then
            dbms_output.put_line('grade a');
        elsif g > 9 and g <= 10 then
            dbms_output.put_line('grade a+');
        else
            dbms_output.put_line('no grade');
        end if;
        i := i + 1;
        if i > 5 then exit;
        end if;
    end loop;
end;
/

5)
alter table StudentTable add (LetterGrade varchar(2));

set serveroutput on
declare
    g StudentTable.GPA%TYPE;
    i number;
    n number;
begin
    select count(*) into n from StudentTable;
    i := 1;
    while i <= n
    loop
        select gpa into g from StudentTable where RollNo = i;
        if g > 0 and g <= 4 then
            update StudentTable set LetterGrade = 'F' where RollNo = i;
        elsif g > 4 and g <= 5 then
            update StudentTable set LetterGrade = 'E' where RollNo = i;
       elsif g > 5 and g <= 6 then
            update StudentTable set LetterGrade = 'D' where RollNo = i;
        elsif g > 6 and g <= 7 then
            update StudentTable set LetterGrade = 'C' where RollNo = i;
        elsif g > 7 and g <= 8 then
            update StudentTable set LetterGrade = 'B' where RollNo = i;
        elsif g > 8 and g <= 9 then
            update StudentTable set LetterGrade = 'A' where RollNo = i;
        elsif g > 9 and g <= 10 then
            update StudentTable set LetterGrade = 'A+' where RollNo = i;
        end if;
        i := i + 1;
    end loop;
end;
/

6)
set serveroutput on
declare
    g StudentTable.GPA%TYPE;
    mg StudentTable.GPA%TYPE;
    i number;
    n number;
begin
    select count(*) into n from StudentTable;
    i := 1;
    mg := 0;
    for i in 1..n loop
        select gpa into g from StudentTable where RollNo = i;
        if g > mg then
            mg := g;
        end if;
    end loop;
    select RollNo into i from StudentTable where gpa = mg;
    dbms_output.put_line('student with max gpa is roll no. '|| i);
end;
/

7)
set serveroutput on
declare
    i numeric(1);
    g StudentTable.GPA%TYPE;
    gr varchar(2);
begin
    i := 1;
    loop
        select gpa into g from StudentTable where RollNo = i;
        if g > 0 and g <= 4 then
            gr :='F';
            goto disp;
        elsif g > 4 and g <= 5 then
            gr :='E';
            goto disp;
       elsif g > 5 and g <= 6 then
            gr :='D';
            goto disp;
        elsif g > 6 and g <= 7 then
            gr :='C';
            goto disp;
        elsif g > 7 and g <= 8 then
            gr :='B';
            goto disp;
        elsif g > 8 and g <= 9 then
            gr :='A';
            goto disp;
        elsif g > 9 and g <= 10 then
            gr :='A+';
            goto disp;
        else
            dbms_output.put_line('no grade');
        end if;
        <<disp>>
            dbms_output.put_line('grade is '|| gr);
        i := i + 1;
        if i > 5 then exit;
        end if;
    end loop;
end;
/

8)
set serveroutput on
declare
    name instructor.name%TYPE;
begin
    select name into name from instructor where name='&name';
    dbms_output.put_line(name||' Found');
    exception
    when no_data_found then dbms_output.put_line('No Rows Found');
    when dup_val_on_index then dbms_output.put_line('Multiple Rows Found');
end;
/
