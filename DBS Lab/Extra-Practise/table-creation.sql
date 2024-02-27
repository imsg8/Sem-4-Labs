create table customer(
    cid number(5) primary key,
    cname char(15),
    address char(30),
    incomegroup char(15)
);

create table sales(
    sid number(5) primary key,
    saledate date,
    cid number(5),
    item char(15),
    qty number(5),
    unitprice number(5),
    foreign key (cid) references customer(cid)
);


insert into customer values(1,'Anand','Main Road Manipal','High');
insert into customer values(2,'Mohan','Tiger Circle Manipal','Medium');
insert into customer values(3,'Jacob','Main Road Udupi','Medium');

insert into sales values(101,to_date('27-Jan-2023','DD-MON-YYYY'),1,'Sugar',10,50);
insert into sales values(102,to_date('20-Dec-2022','DD-MON-YYYY'),2,'Rice',5,40);
insert into sales values(103,to_date('12-Nov-2022','DD-MON-YYYY'),1,'Sunflower Oil',1,150);
insert into sales values(104,to_date('25-Dec-2022','DD-MON-YYYY'),3,'Rice',2,40);
insert into sales values(105,to_date('21-Nov-2022','DD-MON-YYYY'),1,'Sunflower Oil',2,150);
