CREATE TABLE CUSTOMER(
Cid number(1),
CName varchar(5),
Address varchar(20),
CreditScore number(3),
Constraint cust_pk primary key(Cid));

Create Table Account(
Ano number(3),
Cid number(1),
BName varchar(10),
Balance Number(8,2),
Constraint acc_pk primary key(Ano),
Constraint acc_fk foreign key (Cid) references Customer);

insert into customer values(1,'Anand','Main Road Manipal',300);
insert into customer values(2,'Mohan','Tiger Circle Manipal',500);
insert into customer values(3,'Jacob','Main Road Udupi',800);

insert into account values(100,1,'Manipal',10000);
insert into account values(101,2,'Manipal',5000);
insert into account values(200,1,'Udupi',2000);
insert into account values(201,3,'Udupi',7000);

a) select Cname 
   from Account natural join Customer
   where BName='Manipal';

b) select BName,sum(Balance) tot_balance
   from Account
   group by BName;

c) select Cname
   from Customer C
   where not exists((select distinct Bname
                     from Account)
                     minus
                    (select Bname
                     from Account 
                     where C.Cid=Cid));
